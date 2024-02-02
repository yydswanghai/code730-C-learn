// x86的机器小端：内存中低位在前

#include <stdio.h>

typedef union {
  int i;
  char ch[sizeof(int)];
} CHI;

int main(int argc, char const *argv[]) {
  CHI chi;
  int i;
  chi.i = 1234;// 04D2
  for ( i = 0; i < sizeof(int); i++) {
    printf("%02hhX", chi.ch[i]);
  }
  printf("\n");

  return 0;
}
