// 1120 过了 110分钟时多少

#include <stdio.h>

int main()
{
  int cm = 0;
  scanf("%d", &cm);
  int foot = cm/30.48;// c里可以帮你转换
  int inch = (cm/30.48 - foot)*12;
  
  printf("%d\n", foot);
  
  return 0;
}
