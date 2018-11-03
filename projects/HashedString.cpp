#include <cstdio>

const unsigned int offset = 2166136261u;
const unsigned int prime  = 16777619u;

constexpr unsigned int _hash(const char *str)
{
  unsigned int hash = offset;
  while (*str != '\0') {
    hash ^= *str++;
    hash *= prime;
  }

  return hash;
}

template<unsigned int hash_value>
struct fnv_hash {
  const unsigned int hash {hash_value};
};

int main(int argc, char **argv)
{
  fnv_hash<_hash("kakaroto")> a;
  fnv_hash<_hash("kakaroto Sayajin")> b;
  fnv_hash<_hash("kakaroto The Hero")> c;
  fnv_hash<_hash("kakaroto é o Goku")> d;
  //fnv_hash<_hash(argv[1])> e; //‘argv’ is not a constant expression

  printf("%x\n", a.hash);
  printf("%x\n", b.hash);
  printf("%x\n", c.hash);
  printf("%x\n", d.hash);
  //printf("%x\n", e.hash);
}
