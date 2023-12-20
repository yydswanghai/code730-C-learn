// if 如果
// 如果满足 (im < 0) 就运行 大括号里面的内容，否则直接跳过

#include <stdio.h>

int main()
{
  int hour1, minute1;
  int hour2, minute2;
  scanf("%d %d", &hour1, &minute1);
  scanf("%d %d", &hour2, &minute2);
  int ih = hour2 - hour1;
  int im = minute2 - minute1;
  if(im < 0){// 比如 13:50 和 14:10 发生借位
    im = 60 + im;
    ih --;
  }
  printf("时间差为%d小时%d分\n", ih, im);
  
  return 0;
}
