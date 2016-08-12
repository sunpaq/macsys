#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
COLOR

Sets the default console foreground and background colours.

Syntax
      COLOR [background][foreground]
Colour attributes are specified by 2 of the following hex digits. There should be no space between the two color numbers.

Each digit can be any of the following values: 

0 = Black 
8 = Gray 

1 = Blue 
9 = Light Blue 

2 = Green 
A = Light Green 

3 = Aqua 
B = Light Aqua 

4 = Red 
C = Light Red 

5 = Purple 
D = Light Purple 

6 = Yellow 
E = Light Yellow 

7 = White 
F = Bright White 

If no argument is given, COLOR restores the colour to what it was when CMD.EXE started. 
*/

//ASCII Color Code
typedef enum {
	DisDefault = 0,
	DisHighlight = 1,
	DisNoBold = 22,

	DisUnderline = 4,
	DisNoUnderline = 24,

	DisBlink = 5,
	DisNoBlink = 25,

	DisInverse = 7,
	DisNoInverse = 27,
} DisMode;

typedef enum {
	DFBlack = 30,
	DFRed,
	DFGreen,
	DFYellow,
	DFBlue,
	DFMagenta,
	DFCyan,
	DFWhite
} DFColor;

typedef enum {
	DBBlack = 40,
	DBRed,
	DBGreen,
	DBYellow,
	DBBlue,
	DBMagenta,
	DBCyan,
	DBWhite
} DBColor;

int setModeColor(DisMode mode, DFColor fc, DBColor bc);

int setColor(DFColor fc, DBColor bc);

int setColorWindowsHex(unsigned char hex);

int resetColor();

int macsys(const char* cmd);

void showAllWindowsHexColor();

unsigned int Sleep(unsigned int milisecs);

