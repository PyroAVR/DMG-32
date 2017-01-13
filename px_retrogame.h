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
{   3,     KEY_A  },    // A
{   2,     KEY_B  },    // B
{   4,     KEY_X  },    // X
{  27,     KEY_Y  },    // Y
{  17,     KEY_UP  },   // Up
{   7,     KEY_DOWN  }, // Down
{  12,     KEY_LEFT  }, // Left
{  16,     KEY_RIGHT }, // Right
{  23,     KEY_L  },    // L
{  24,     KEY_R },     // R
{  22,     KEY_N },     // Select
{  10,     KEY_M },     // Start
{  -1,     -1           } }; // END OF LIST, DO NOT CHANGE

// A "Vulcan nerve pinch" (holding down a specific button combination
// for a few seconds) issues an 'esc' keypress to RetroArch (which brings up
// an exit menu or quits the current game).  The button combo is
// configured with a bitmask corresponding to elements in the above io[]
// array.  The default value here uses elements 10 and 11 (select and start
// in the DMG-32 pinout).  If you change this, make certain it's a combo
// that's not likely to occur during actual gameplay (i.e. avoid using
// joystick directions or hold-for-rapid-fire buttons).
// Also key auto-repeat times are set here.  This is for navigating the
// game menu using the 'gamera' utility; MAME disregards key repeat
// events (as it should).
//This causes random crashes if those pins are not connected properly!
//Elements 10 and 11 are START and SELECT in ioPixel
const unsigned long vulcanMask = (1L << 10) | (1L << 11);
const int           vulcanKey  = KEY_Q, // Keycode to send
                    vulcanTime = 1500,    // Pinch time in milliseconds
                    repTime1   = 500,     // Key hold time to begin repeat
                    repTime2   = 100;     // Time between key repetitions
