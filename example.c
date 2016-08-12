#include "macsys.h"

int main(int argc, char const *argv[])
{
	/* code */
	macsys("color 1");
	printf("hello world\n");

	macsys("color 2");
	printf("hello world\n");
	
	macsys("color 3");
	printf("hello world\n");

	macsys("dir");

	macsys(" color ");
	macsys(" pause ");

	return 0;
}
