#ifndef _MSP40_H_
#define _MSP40_H_

union PAIR {
	struct b {
		uint8_t  h, l;
		uint16_t pad;
	};

	struct w {
		uint16_t h, l;
	}

	uint32_t d
};


struct MSP430CPU {
	PAIR r[16];
	uint32_t zf, cf, vf, nf;
	uint32_t cpuoff, gie;

	uint8_t *memory;
};

#endif // _MSP40_H_
