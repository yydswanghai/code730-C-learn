// 进制

#include <stdio.h>

int main() {
  char c = 012;
  int i = 0x12;
  // 在计算机内部它依然是二进制
  // 进制也是我们怎么去看它，
  printf("c=%d,i=%u\n", c, i);// 用十进制去看
  printf("c=%o,i=%x\n", c, i);// 分别用8进制输出和16进制输出去看

  return 0;
}
