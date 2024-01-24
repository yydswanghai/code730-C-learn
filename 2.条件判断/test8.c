// 计算 352 是 3位数的数字
// 利用while循环

#include <stdio.h>

int main() {
  int num;
  int count = 0;
  printf("请输入数字：");
  scanf("%d", &num);

  // if(num > 0) {
  //   num /= 10;
  //   count ++;
  // }
  // if(num > 0) {
  //   num /= 10;
  //   count ++;
  // }
  // if(num > 0) {
  //   num /= 10;
  //   count ++;
  // }

  // 输入0的情况
  count++;
  num /= 10;
  while (num > 0) {
    num /= 10;
    count ++;
  }

  printf("是一个%d位数\n", count);

  return 0;
}
