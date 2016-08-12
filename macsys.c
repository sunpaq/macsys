#include "macsys.h"

int setModeColor(DisMode mode, DFColor fc, DBColor bc)
{
	return printf("\033[%d;%d;%dm", mode, fc, bc);
}

int setColor(DFColor fc, DBColor bc)
{
	return setModeColor(DisDefault, fc, bc);
}

int setColorWindowsHex(unsigned char hex)
{
	unsigned char high = (hex & 0xF0) >> 4;
	unsigned char low  = (hex & 0x0F);

	DBColor bc;
	DFColor fc;

	DisMode mode = DisDefault;

	if (high == 0x0) bc = DBBlack;
	if (high == 0x1) bc = DBBlue;
	if (high == 0x2) bc = DBGreen;
	if (high == 0x3) bc = DBCyan;
	if (high == 0x4) bc = DBRed;
	if (high == 0x5) bc = DBMagenta;
	if (high == 0x6) bc = DBYellow;
	if (high == 0x7) bc = DBWhite;
	
	if (high == 0x8) bc = DBBlack;   mode = DisHighlight;
	if (high == 0x9) bc = DBBlue;    mode = DisHighlight;
	if (high == 0xA) bc = DBGreen;   mode = DisHighlight;
	if (high == 0xB) bc = DBCyan;    mode = DisHighlight;
	if (high == 0xC) bc = DBRed;     mode = DisHighlight;
	if (high == 0xD) bc = DBMagenta; mode = DisHighlight;
	if (high == 0xE) bc = DBYellow;  mode = DisHighlight;
	if (high == 0xF) bc = DBWhite;   mode = DisHighlight;

	if (low == 0x0) fc = DFBlack;
	if (low == 0x1) fc = DFBlue;
	if (low == 0x2) fc = DFGreen;
	if (low == 0x3) fc = DFCyan;
	if (low == 0x4) fc = DFRed;
	if (low == 0x5) fc = DFMagenta;
	if (low == 0x6) fc = DFYellow;
	if (low == 0x7) fc = DFWhite;

	if (low == 0x8) fc = DFBlack;    mode = DisHighlight;
	if (low == 0x9) fc = DFBlue;     mode = DisHighlight;
	if (low == 0x10) fc = DFGreen;   mode = DisHighlight;
	if (low == 0x11) fc = DFCyan;    mode = DisHighlight;
	if (low == 0x12) fc = DFRed;     mode = DisHighlight;
	if (low == 0x13) fc = DFMagenta; mode = DisHighlight;
	if (low == 0x14) fc = DFYellow;  mode = DisHighlight;
	if (low == 0x15) fc = DFWhite;   mode = DisHighlight;

	return setModeColor(mode, fc, bc);
}

int resetColor()
{
	//return setColor(DFWhite, DBBlack);
	//'\033[0m' not work
	return printf("\033[0m");
}

int macsys(const char* cmd)
{
	char *remain, *next;
	char buff[1024];
	if ((remain = strstr(cmd, "color")) != NULL) {
		//skip 'color'
		remain += 5;
		//strip whitespace
		while(*remain == ' ') remain++;
		//make hex string
		sprintf(buff, "0x%s", remain);
		//convert hex
		unsigned char hex = (unsigned char)strtoul(buff, &next, 16);
		//printf("debug: %s=(%d)\n", buff, hex);
		if (hex == 0) {
			return resetColor();
		}
		return setColorWindowsHex(hex);
	}

	if (strstr(cmd, "pause") != NULL) {
		printf("Press any key to continue ...");
		return getchar();
	}

	if (strstr(cmd, "dir") != NULL) {
		system("echo Directory of $(pwd)");
		return system("ls -all");
	}

	//fall back
	return system(cmd);
}

void showAllWindowHexColor()
{
	char buff[1024];
	for (unsigned i = 0; i < 0xff; i++) {
		sprintf(buff, "color %d", i);
		macsys(buff);
		printf("%s\n", buff);
	}
}

