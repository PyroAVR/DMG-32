SOFTWARE SETUP
==========
I/O Pins for Pixel Interface board:
(Make sure these are correct!)
GPIO NAME         PIN #           FUNCTION            MAP
GPIO16               36               A BUTTON           KEY_X
GPIO20               38               B BUTTON           KEY_Z
GPIO21               40               X BUTTON           KEY_A
GPIO12               32               Y BUTTON           KEY_S
GPIO13               33               L BUTTON           KEY_L
GPIO6                 31               R BUTTON           KEY_R
GPIO26               37                  START           KEY_ENTER
GPIO19               35                 SELECT          KEY_LSHIFT
GPIO5                 29                     UP               KEY_UP
GPIO22               15                  DOWN           KEY_DOWN
GPIO27               13                   LEFT            KEY_LEFT
GPIO11               17                  RIGHT           KEY_RIGHT

*C*
ioPixel[] = {
//This pin/key table is set up for the tentative Pixel Interface Board,
// which fits quite nicely inside an original DMG Gameboy.
// Input   Output (from /usr/include/linux/input.h)
{  16,     KEY_X  },   // A
{  20,     KEY_Z  },  // B
{  21,     KEY_A  },  // X
{  12,     KEY_S  },  // Y
{  13,     KEY_L  },  // L
{   6,      KEY_R  }, // R
{  26,     KEY_ENTER  },  // Start
{  19,     KEY_LSHIFT },  // Select
{   5,      KEY_UP  },       // Up
{  22,     KEY_DOWN },  // Down
{  27,     KEY_LEFT },    // Left
{  11,      KEY_RIGHT }, // Right
{  -1,     -1           } }; // END OF LIST, DO NOT CHANGE
