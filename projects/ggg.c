typedef unsigned short uint16_t;
int main() {
	//* (const uint16_t *) (0x8E5D) = 0xA95E;
	//uint16_t *p = (uint16_t *) 0x8E5D; p = 0xA95E;
	//* (uint16_t * const) (0xA95E) = 0x8E5D;
	//uint16_t *q = (uint16_t *) 0xA95E; q = 0x8E5D;
	//* (uint16_t const *) (0x8E5D) = 0xA95E;
	//uint16_t *r = (uint16_t * const) 0xA95E; r = 0x8E5D;
	* (uint16_t * const ) (0x8E5D) = 0xA95E;
	//uint16_t *s = (const uint16_t *) 0x8E5D; s = 0xA95E;
	//* (uint16_t const *) (0xA95E) = 0x8E5D;
}
