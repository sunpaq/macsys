#include "macsys.h"

int main(int argc, char const *argv[])
{
	/* code */
	macsys("color 1");
	printf("hello world\n");

	Sleep(500);
	macsys("color 2");
	printf("hello world\n");

	macsys("color 3");
	macsys("dir");
	Sleep(2000);
	macsys("cls");

	Sleep(500);
	macsys("color 4");
	printf("hello world\n");

	macsys(" color ");
	macsys(" pause ");

	return 0;
}
