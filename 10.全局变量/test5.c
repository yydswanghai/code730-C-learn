// __func__: 当前函数的名字
// 静态本地变量
#include <stdio.h>

int f(void);

int main(int argc, char const *argv[]) {
  f();
  f();
  f();

  return 0;
}

int f(void) {
  static int all = 1;
  printf("in %s all=%d\n", __func__, all);
  all += 2;
  printf("agn in %s all=%d\n", __func__, all);
  return all;
}