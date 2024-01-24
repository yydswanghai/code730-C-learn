/**
 * 猜数游戏
 * 1. 让计算机来想一个数，然后让用户来猜
 * 用户每输入一个数，就告诉它是大了还是小了
 * 直到用户猜中为止，最后还要告诉用户它猜了多少次
 * 2. 因为需要不断的重复，所以需要用到循环
 * 3. 在实际写出程序之前，可以用文字描述程序的思路
 * 4. 核心重点是循环条件
 * 思路：
 * 1. 计算机随机想一个数，记做变量number
 * 2. 一个负责计数的变量count初始化为0
 * 3. 让用户输入一个数字a
 * 4. count递增（加一）
 * 5. 判断a和number的大小，如果a大，就输出"大"，如果a小，则输出"小"
 * 6. 如果a和number不相等（无论大还是小），程序回到第3步
 * 7. 否则，程序输出"猜中"和次数，然后结束
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int number = rand()%100;// 取 100 内的数
  int count = 0;
  int a;
  
  printf("我已经想好了一个1到100之间到数\n");

  do {
    printf("请猜这个1到100之间到数：\n");
    scanf("%d", &a);
    count ++;
    if(a > number) {
      printf("a大\n");
    } else if(a < number) {
      printf("a小\n");
    }
  } while (a != number);
  
  printf("太好了，你用了%d次，猜中这个数字为%d", count, number);
  return 0;
}
