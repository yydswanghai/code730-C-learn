// 返回值
#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int a, b, c;
  a = 5;
  b = 6;
  c = max(10,12);
  c = max(a,b);
  c = max(c,23);
  max(1, 2);// 有可能调用函数，只是需要它的副作用
  printf("%d\n", max(a,b));

  return 0;
}