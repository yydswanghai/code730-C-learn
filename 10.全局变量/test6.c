// __func__: 当前函数的名字
// 静态本地变量，全局生存期、本地作用域
#include <stdio.h>

int f(void);
int gAll = 12;

int main(int argc, char const *argv[]) {
  f();

  return 0;
}

// gAll 和 all 的地址紧挨着一起，说明静态本地变量它就是全局变量
int f(void) {
  static int all = 1;
  int k = 0;
  printf("&gAll=%p\n", &gAll);
  printf("&all =%p\n", &all);
  printf("&k   =%p\n", &k);
  printf("in %s all=%d\n", __func__, all);
  all += 2;
  printf("agn in %s all=%d\n", __func__, all);
  return all;
}