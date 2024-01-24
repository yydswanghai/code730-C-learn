#include <stdio.h>
// do-while循环

int main() {
  int num;
  int count = 0;
  printf("请输入数字：");
  scanf("%d", &num);

  // 输入0的情况
  do {
    num /= 10;
    count ++;
  } while (num > 0);

  printf("是一个%d位数\n", count);

  return 0;
}
