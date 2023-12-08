#include <stdio.h>
/**
 * sizeof 是一个运算符，而不是函数。sizeof 运算符
 * 用于计算数据类型或对象的大小（以字节为单位）。它的语法形式是：
 * sizeof (type)
 * 其中，type 可以是数据类型、变量名或表达式。sizeof 
 * 返回一个 size_t 类型的值，表示所提供类型或对象的存储空间大小。
*/
int main()
{
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of double: %zu bytes\n", sizeof(double));
  printf("Size of char: %zu bytes\n", sizeof(char));

  int x = 3.14;
  float y = 12 * 2;
  printf("%d\n", x);
  printf("%d\n", y);
  return 0;
}
