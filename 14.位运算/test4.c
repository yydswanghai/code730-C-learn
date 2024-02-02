// 输出一个二进制数
#include <stdio.h>

// mask 1000 0000 0000 0000
// mask 0100 0000 0000 0000
// mask 0010 0000 0000 0000
// mask 0001 0000 0000 0000
// &
// num  1101 0010 ...
// =    
int main(int argc, char const *argv[]) {
  int number;
  scanf("%d", &number);
  // 1u 表示无符号整数 1
  // 左移 31 位后，得到的结果是 2147483648，这是一个 32 位系统中整数的最大正整数值
  unsigned mask = 1u<<31;
  for ( ; mask; mask >>=1) {
    printf("%d", number & mask ? 1:0);
  }
  printf("\n");

  return 0;
}
