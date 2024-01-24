// 指针

#include <stdio.h>

void f(int *p);
void g(int k);

int main() {
  int i = 6;
  printf("&i=%p\n", &i);
  f(&i);
  g(i);// 如果改变了，g函数里面输出的值会受到影响

  return 0;
}

// 得到变量i的地址
void f(int *p) {
  printf(" p=%p\n", p);
  printf("*p=%d\n", *p);// 访问地址上的变量，*p当作一个整体
  *p = 26;// 改变地址上的变量，i的值会受影响吗
}
// 得到的仅是i的值
void g(int k) {
  printf(" k=%d\n", k);
}