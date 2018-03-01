# dcsd_led
Playing with LEDs on DCSD cables

| Value  | LED        |
|-------|:----------:|
| `0xF0` | all LEDs OFF |
| `0xF1` | red ON |
| `0xF2`| green ON|
| `0xF3`| green and red ON |
| `0xF4` | all LEDs are OFF|
| `0xF8` | yellow ON |
| `0xF9` | yellow and red ON |
| `0xFA` | yellow and green ON |
| `0xFB` | all LEDs ON |

### Demo
[![demo_img](https://raw.githubusercontent.com/matteyeux/dcsd_led/master/demo.png)](https://www.youtube.com/watch?v=Mb5CwDhj2hg)

### Build

First, install [libftdi](https://www.intra2net.com/en/developer/libftdi/index.php) then build with GCC:

`gcc dcsd_leds.c -Wall -I/usr/include/libftdi1 -L/usr/local/lib/ -lftdi1 -o dcsd_leds`

### Doc

Documentation is available on [The iPhone Wiki](https://www.theiphonewiki.com/wiki/DCSD_Cable).

There is also a Github repo about [DCSD Reverse Engineering](https://github.com/lululombard/DCSD-reverse-engineering).

### Credits

Code is from Libftdi `bitbang_cbus.c` example, and a bit modified.

[Lululombard's](https://www.youtube.com/watch?v=QEdPzHy-dbc&t) (French) video helped a lot.
