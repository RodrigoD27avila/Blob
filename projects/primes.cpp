#include <stdio.h>
#include <stdint.h>

bool MillerRabin(uint64_t n, uint64_t k)
{
   if(n == k) return true;
   uint64_t s, d, b, e, x;
 
   // Factor n-1 as d 2^s
   for(s = 0, d = n - 1; !(d & 1); s++)
      d >>= 1;
 
   // x = k^d mod n using exponentiation by squaring
   // The squaring overflows for n >= 2^32
   for(x = 1, b = k % n, e = d; e; e >>= 1) {
      if(e & 1)
         x = (x * b) % n;
      b = (b * b) % n;
   }
 
   // Verify k^(d 2^[0…s-1]) mod n != 1
   if(x == 1 || x == n-1)
      return true;
   while(s-- > 1) {
      x = (x * x) % n;
      if(x == 1)
         return false;
      if(x == n-1)
         return true;
   }
   return false;
}

int main()
{
	int i;
	for (i=3; i<=104729; i++) {
		if (MillerRabin(i, 2)) {
			printf("%i\n", i);
		}
	}

	return 0;
}
