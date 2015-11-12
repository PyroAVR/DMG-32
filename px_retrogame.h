#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <linux/uinput.h>

// START HERE ------------------------------------------------------------
// This table remaps GPIO inputs to keyboard values.  In this initial
// implementation there's a 1:1 relationship (can't attach multiple keys
// to a button) and the list is fixed in code; there is no configuration
// file.  Buttons physically connect between GPIO pins and ground.  There
// are only a few GND pins on the GPIO header, so a breakout board is
// often needed.  If you require just a couple extra ground connections
// and have unused GPIO pins, set the corresponding key value to GND to
// create a spare ground point.

#define GND -1
struct {
	int pin;
	int key;
} *io,
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
