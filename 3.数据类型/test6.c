// 输入和输出

#include <stdio.h> 

int main() {
  char c = -1;
  int  i = -1;
  // 在计算机里存放的始终是那个东西，这和它在计算机内部是什么没有关系
  // 取决于你把它当作什么来看它，所以就会有不同的结果
  printf("c=%u,i=%u\n", c, i);

  return 0;
}
