#include <stdio.h>
#include <stdlib.h>

#define SOFTINT      0xf00 // software interrupt
#define BRANCH       0xa00 // branch
#define COPROCDOP    0xe00 // coprocessor data operation
#define COPROCRTR    0xe01 // coprocessor register transfer
#define COPROCDTR    0xc00 // coprocessor data transfer

int main()
{
	for (int data=0 ;data<4096; i++) {

		// isolate bit 11 to 08
		int res = (data & 0xf00);

		if (res == SOFTINT) {

		} else {

		}



	}
}
