#include <stdio.h>

/**
 * 当我们说使用位运算来构建二进制值时，实际上是通过对二进制位进行操作来设置或清除特定的位，
 * 从而得到所需的二进制值。让我们用一个简单的例子来说明：
 * 假设我们要构建一个八位的二进制数，其中只有第2位、第4位和第6位是1，
 * 其他位都是0。我们可以使用位运算来实现这个目标。
 * 0010 1010
*/

int main()
{
  // 初始化一个八位的二进制数
  int binaryNumber = 0;// 0000 0000

  // |= 是按位或运算符，用于将右边的二进制数中的1设置到左边的二进制数中。
  // 设置第2位、第4位和第6位为1
  binaryNumber |= (1 << 2);  // 1左移2位，即0000 0100
  printf("step 1: %d\n", binaryNumber);

  binaryNumber |= (1 << 4);  // 1左移4位，即0001 0000
  printf("step 2: %d\n", binaryNumber);

  binaryNumber |= (1 << 6);  // 1左移6位，即0100 0000
  printf("step 3: %d\n", binaryNumber);

  // 也可以这样
  int binaryNumber2 = 0;
  binaryNumber2 = (1 << 2) | (1 << 4) | (1 << 6);
  printf("num2 %d\n", binaryNumber2);

  return 0;
}
