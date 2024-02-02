// 返回本地变量的地址是危险的
#include <stdio.h>

int* f(void);
void g(void);

int main(int argc, char const *argv[]) {
  int *p = f();
  printf("*p=%d\n", *p);
  g();
  printf("*p=%d\n", *p);// *p变成24了

  return 0;
}

int* f(void) {
  int i = 12;
  printf("i的地址:%p\n", &i);
  return &i;
}
void g(void) {
  int k = 24;
  printf("k的地址:%p\n", &k);
  printf("k=%d\n", k);
}