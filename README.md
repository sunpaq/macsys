# macsys

###### this is a C library for simulate the windows prompt system("pause") calls on Unix

#### Purpose

	to help the beginner who choose Mac as his study machine
	some text book for C beginners use windows system as example
	the system() call behavior is different from most Unix shells
	
#### How to use

	#include "macsys.h"
	
	and replace all the 'system()' call with 'macsys()'
	
	exp.
	macsys("pause");
	macsys("color 1");