SOFTWARE SETUP
==========
I/O Pins for Pixel Interface board:
(Make sure these are correct!)
Note that BCM# and GPIO# are synonymous

GPIO NAME         PIN #               FUNCTION          MAP
GPIO3                05               A BUTTON          KEY_A
GPIO2                03               B BUTTON          KEY_B
GPIO4                07               X BUTTON          KEY_X
GPIO27               13               Y BUTTON          KEY_Y
GPIO23               16               L BUTTON          KEY_L
GPIO24               18               R BUTTON          KEY_R
GPIO22               15               SELECT            KEY_N
GPIO10               19               START             KEY_M
GPIO17               11               UP                KEY_UP
GPIO5                26               DOWN              KEY_DOWN
GPIO12               32               LEFT              KEY_LEFT
GPIO16               36               RIGHT             KEY_RIGHT

```C
ioPixel[] = {
//This pin/key table is set up for the tentative Pixel Interface Board,
// which fits quite nicely inside an original DMG Gameboy.
//These mappings are taken directly from the schematic.  For convenience,
//the data has been organized into a neat table, Connectivity Table.ods in this
//repository.
// Input   Output (from /usr/include/linux/input.h)
{   3,     KEY_A  },    // A
{   2,     KEY_B  },    // B
{   4,     KEY_X  },    // X
{  27,     KEY_Y  },    // Y
{  17,     KEY_UP  },   // Up
{   5,     KEY_DOWN  }, // Down
{  12,     KEY_LEFT  }, // Left
{  16,     KEY_RIGHT }, // Right
{  23,     KEY_L  },    // L
{  24,     KEY_R }      // R
{  22,     KEY_N },     // Select
{  10,     KEY_M },     // Start
{  -1,     -1           } }; // END OF LIST, DO NOT CHANGE
```
