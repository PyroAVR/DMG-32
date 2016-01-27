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
//These mappings are taken directly from the schematic.  For convenience,
//the data has been organized into a neat table, Connectivity Table.ods in this
//repository.
// Input   Output (from /usr/include/linux/input.h)
{   3,     KEY_A  },   // A
{   2,     KEY_B  },  // B
{   4,     KEY_X  },  // X
{  27,     KEY_Y  },  // Y
{  18,     KEY_UP  },  // Up
{   7,      KEY_DOWN  }, // Down
{  12,     KEY_LEFT  },  // Left
{  16,     KEY_RIGHT },  // Right
{  23,      KEY_L  },       // L
{  24,     KEY_R },  // R
{  22,     KEY_N },    // Select
{  10,      KEY_M }, // Start
{  -1,     -1           } }; // END OF LIST, DO NOT CHANGE
