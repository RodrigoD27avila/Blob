#include <stdio.h>
#include <malloc.h>
#include <stdint.h>  // gcc needs this for intptr_t.  

typedef struct xorll {
   int  value;
   struct xorll  *np;
}  xorll;


// traverse the list given either the head or the tail
void traverse( xorll *start )  // point to head or tail
{
   xorll *prev, *cur;

   cur = prev = start;
   while ( cur )
      {
      printf( "value = %d\n", cur->value );
      if ( cur->np == cur )
         // done
         break;
      if ( cur == prev )
         cur = cur->np;   // start of list
      else {
         xorll *save = cur;
         cur = (xorll*)((uintptr_t)prev ^ (uintptr_t)cur->np);
         prev = save;
         }
      }
}

// create a new node adding it to the given end and return it
xorll* newnode( xorll *prev, xorll *cur, int value )
{
   xorll *next;

   next = (xorll*)malloc( sizeof( xorll ));
   next->value = value;
   next->np = cur;  // end node points to previous one

   if ( cur == NULL )
      ; // very first node - we'll just return it
   else if ( prev == NULL ) {
      // this is the second node (they point at each other)
      cur->np = next;
      next->np = cur;
      }
   else {
      // do the xor magic
      cur->np = (xorll*)((uintptr_t)prev ^ (uintptr_t)next);
      }

   return next;
}



int main( int argc, char* argv[] )
{
   xorll *head, *tail;
   int   value = 1;

   // the first two nodes point at each other.  Weird param calls to
   // get the list started
   head = tail = newnode( NULL, NULL, value++ );
   tail = newnode( NULL, tail, value++ );

   // now add a couple to the end
   tail = newnode( tail->np, tail, value++ );
   tail = newnode( tail->np, tail, value++ );

   // this is cool - add a new head node
   head = newnode( head->np, head, 999 );


   printf( "Forwards:\n" );
   traverse( head );
   printf( "Backwards:\n" );
   traverse( tail );


}
