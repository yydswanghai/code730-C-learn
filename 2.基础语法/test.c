#include <stdio.h>

#define PI 3.14159
#define MAX_VALUE 100

// 声明 add 函数，告诉编译器它的存在
int add(int a, int b);

// 主函数的返回必须是int
int main() 
{
  int result;
  result = add(1, 2);
  printf("Result: %d\n", result);
  printf("圆周率: %f\n", PI);
  return 0;
}

// 定义一个add函数
int add(int a, int b) 
{
  return a + b;
}