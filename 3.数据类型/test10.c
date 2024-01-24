// 浮点数运算的精度
// f1 == f2 可能失败
// 建议用 fabs(f1 - f2) < 1e-8
#include <stdio.h>

int main() {
  float a,b,c;
  
  // 带小数点的字面量是double而非float
  // float需要用f或者F后缀来表明身份
  a = 1.345f;
  b = 1.123f;
  c = a + b;
  if (c == 2.468)
    printf("相等\n");
  else 
    printf("不相等！c=%.10f，或%f\n", c, c);

  return 0;
}