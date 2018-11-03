
void enc() {

	int r13;

	int *addr = (int *)0x247c;
	for (r13 = 0; r13<256; r13++) {
		*(addr+r13) = r13;
	}

	int r12 = 0x247c; r13 = 0;
	int r11 = r13;

	for (; r11<256; r11++, r12++) {

		unsigned char r8  = *((unsigned char *)r12)
		unsigned char r10 = r8;
		r13 += r10;
		r10  = r11;
		r10  = *((unsigned char *)(0x4472 + r10));

	}





}
