#include <iostream>
#include <bitset>

#define CF 0x01 // Carry Flag
#define NF 0x02 // Subtract Flag
#define PF 0x04 // Parity Flag
#define XF 0x8
#define VF PF   // Overflow Flag
#define HF 0x10 // Half Carry Flag
#define YF 0x20
#define ZF 0x40 // Zero Flag
#define SF 0x80 // Sign Flag

// zero, sign, carry, half carry and overflow flags for ADD, ADC, SUB and SBC
static unsigned char SZHVC_add[65536L * 2];
static unsigned char SZHVC_sub[65536L * 2];
static unsigned char SZHVC_addt[65536L * 2];
static unsigned char SZHVC_subt[65536L * 2];

void initialize()
{
        uint8_t *padd = &SZHVC_add[0];
        uint8_t *padc = &SZHVC_add[(1<<16)];
        uint8_t *psub = &SZHVC_sub[0];
        uint8_t *psbc = &SZHVC_sub[(1<<16)];

        int newval, oldval, k=0;
        for (oldval=0; oldval< 256; oldval++) {
                for (newval=0; newval < 256; newval++, k++) {

                        // add or adc w/o carry set
                        int val  = newval - oldval;
                        padd[k] |= (newval) ? ((newval & 0x80) ? SF : 0) : ZF;
			padd[k] |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                        if ((newval & 0x0f) < (oldval & 0x0f)) padd[k] |=  HF;
                        if (newval < oldval) padd[k] |= CF;
                        if ((val ^ oldval ^ 0x80) & (val ^ newval) & 0x80) padd[k] |= VF;

                        //adc with carry set
                        val -= 1;
                        padc[k] |= (newval) ? ((newval & 0x80) ? SF : 0) : ZF;
			padc[k] |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                        if ((newval & 0x0f) <= (oldval & 0x0f)) padc[k] |=  HF;
                        if (newval <= oldval) padc[k] |= CF;
                        if ((val ^ oldval ^ 0x80) & (val ^ newval) & 0x80) padc[k] |= VF;

                        // cp, sub or sbc w/o carry set
                        val = oldval - newval;
                        psub[k] = NF | ((newval) ? ((newval & 0x80) ? SF : 0) : ZF);
			psub[k] |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                        if ((newval & 0x0f) > (oldval & 0x0f)) psub[k] |=  HF;
                        if (newval > oldval) psub[k] |= CF;
			if((val ^ oldval) & (oldval ^ newval) & 0x80) psub[k] |= VF;

                        // sbc with carry set
                        val -= 1;
                        psbc[k] = NF | ((newval) ? ((newval & 0x80) ? SF : 0) : ZF);
			psbc[k] |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                        if ((newval & 0x0f) >= (oldval & 0x0f)) psbc[k] |=  HF;
                        if (newval >= oldval) psbc[k] |= CF;
			if((val ^ oldval) & (oldval ^ newval) & 0x80) psbc[k] |= VF;

		}
	}
}

void initialize_takeda()
{
		uint8_t *padd = SZHVC_addt;
                uint8_t *padc = SZHVC_addt + 256 * 256;
                uint8_t *psub = SZHVC_subt;
                uint8_t *psbc = SZHVC_subt + 256 * 256;

                for(int oldval = 0; oldval < 256; oldval++) {
                        for(int newval = 0; newval < 256; newval++) {
                                /* add or adc w/o carry set */
                                int val = newval - oldval;
                                *padd = (newval) ? ((newval & 0x80) ? SF : 0) : ZF;
                                *padd |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                                if((newval & 0x0f) < (oldval & 0x0f)) *padd |= HF;
                                if(newval < oldval) *padd |= CF;
                                if((val ^ oldval ^ 0x80) & (val ^ newval) & 0x80) *padd |= VF;
                                padd++;

                                /* adc with carry set */
                                val = newval - oldval - 1;
                                *padc = (newval) ? ((newval & 0x80) ? SF : 0) : ZF;
                                *padc |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                                if((newval & 0x0f) <= (oldval & 0x0f)) *padc |= HF;
                                if(newval <= oldval) *padc |= CF;
                                if((val ^ oldval ^ 0x80) & (val ^ newval) & 0x80) *padc |= VF;
                                padc++;

                                /* cp, sub or sbc w/o carry set */
                                val = oldval - newval;
                                *psub = NF | ((newval) ? ((newval & 0x80) ? SF : 0) : ZF);
                                *psub |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                                if((newval & 0x0f) > (oldval & 0x0f)) *psub |= HF;
                                if(newval > oldval) *psub |= CF;
                                if((val ^ oldval) & (oldval ^ newval) & 0x80) *psub |= VF;
                                psub++;

                                /* sbc with carry set */
                                val = oldval - newval - 1;
                                *psbc = NF | ((newval) ? ((newval & 0x80) ? SF : 0) : ZF);
                                *psbc |= (newval & (YF | XF));  /* undocumented flag bits 5+3 */
                                if((newval & 0x0f) >= (oldval & 0x0f)) *psbc |= HF;
                                if(newval >= oldval) *psbc |= CF;
                                if((val ^ oldval) & (oldval ^ newval) & 0x80) *psbc |= VF;
                                psbc++;
		}
	}
}

int main()
{
	initialize();
	initialize_takeda();

	for (int i=0; i<((1<<16) * 2); i++) {
		if (SZHVC_add[i] != SZHVC_addt[i]) {
			std::cout << "Error SZHVC_add[" << i << "]" << std::endl;
			std::bitset<8> a(SZHVC_add[i]);
			std::bitset<8> b(SZHVC_addt[i]);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			break;
		}

		if (SZHVC_sub[i] != SZHVC_subt[i]) {
			std::cout << "Error SZHVC_sub[" << i << "]" << std::endl;
			std::bitset<8> a(SZHVC_sub[i]);
			std::bitset<8> b(SZHVC_subt[i]);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			break;
		}
	}

}
