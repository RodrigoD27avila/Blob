#include <stdio.h>

int main(int argc, char **argv)
{

int i, j=0;
for (i=0; i<99000000; i++) {
	switch (argc) {
	case 1 : {
		int a = 10;
		j = a;
		}
		break;
	case 44: {
		int a = 10, b = 89;
		int c = a+b+76;
		j = c;
		}
		break;
	}
}

	return j;

}
