// 强制类型转换

#include <stdio.h>

// 32768=10...0(15个0)
int main() {
  printf("%d\n", (short)32768);

  printf("%d\n", (char)32768);// 而 char 只有8bit，32768 取了最低的那8bit，刚好就是0

  return 0;
}

// 强制类型转换不会去改变这个变量的值
int main2() {
  int i = 32768;
  short s = (short)i;
  printf("%d\n", i);

  return 0;
}

// 先转换，再运算
int main3() {
  double a = 1.0;
  double b = 2.0;
  int i = (int)a/b;// 如果要先运算 (int)(a/b)
  printf("i=%d,a=%f,b=%f\n", i, a, b);

  return 0;
}