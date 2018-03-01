#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ftdi.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	struct ftdi_context *ftdi;
	int f;
	int i = 0;
	long int tab[10] = {0xF2, 0xF8, 0xF1};
	unsigned char buf[1];
	

	ftdi = ftdi_new();
	
	if (ftdi == 0)
	{
		fprintf(stderr, "ftdi_new failed\n");
		return EXIT_FAILURE;
	}

	f = ftdi_usb_open(ftdi, 0x0403, 0x8a88);
	if (f < 0 && f != -5)
	{
		fprintf(stderr, "unable to open ftdi device: %d (%s)\n", f, ftdi_get_error_string(ftdi));
		ftdi_free(ftdi);
		exit(-1);
	}
	printf("ftdi open succeeded: %d\n",f);
	
	while(1){
		i = 0;
		for (;i < 3; ++i)
		{
			f = ftdi_set_bitmode(ftdi, tab[i], BITMODE_CBUS);
			if (f < 0)
			{
				fprintf(stderr, "set_bitmode failed for 0x%ld, error %d (%s)\n", tab[i], f, ftdi_get_error_string(ftdi));
				ftdi_usb_close(ftdi);
				ftdi_free(ftdi);
				exit(-1);
			}
			// read CBUS
			f = ftdi_read_pins(ftdi, &buf[0]);
			if (f < 0)
			{
				fprintf(stderr, "read_pins failed, error %d (%s)\n", f, ftdi_get_error_string(ftdi));
				ftdi_usb_close(ftdi);
				ftdi_free(ftdi);
				exit(-1);
			}
			printf("0x%01x\n", buf[0] & 0x0f);
			usleep(100000);
		}
	}

	printf("disabling bitbang mode\n");
	ftdi_disable_bitbang(ftdi);

	ftdi_usb_close(ftdi);
	ftdi_free(ftdi);

	return 0;
}