#include <stdio.h>

int main(void)
{
   int *p; /* ponteiro para inteiro */
   int var = 10;

   char str[] = "Rodrigo D'avila";

   char **p_str = &str[0];

   p = &var; /* O ponteiro piA recebe o endereço de memória da variável iVariavel */

   printf("\nEndereço: %p", p);
   printf("\nValor   : %i", *p);

   *p = 1975; /* Indica que endereço de memória, representado pelo ponteiro, irá receber o valor 1975 */

   printf("\nValor alterado: %i", var);
   printf("\nValor         : %i", *p);

   printf ("\n%s\n", str);
   printf ("\n%p\n", p_str);

   return 0;
}
