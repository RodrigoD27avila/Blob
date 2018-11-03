#include <stdio.h>
#include <pthread.h>

void *foo();
void *update(void*);


int main ()
{
  pthread_t id;  
  pthread_create(&id, NULL, update, NULL);
  return 0;
}

void *update(void (*func)(void))
{
  if (func)
  {
    while (true)
    {
      func();
    }
  }
}

void *foo()
{
  printf ("Foo!!\n");
  update(foo);
}

