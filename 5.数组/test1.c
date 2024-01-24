// 用数组记录，哪些元素大于平均数
// 计算平均数

#include <stdio.h>

int main() {
  int x;
  double sum = 0;
  int cnt = 0;
  int number[100];
  scanf("%d", &x);
  
  while (x != -1) {
    number[cnt] = x;
    //
    {
      int i;
      printf("%d\t", cnt);
      for ( i = 0; i <= cnt; i++) {
        printf("%d\t", number[i]);
      }
      printf("\n");
    }
    //
    sum += x;
    cnt ++;
    scanf("%d", &x);
  }
  if (cnt > 0) {
    printf("%f\n", sum);
    int i;
    for ( i = 0; i < cnt; i++) {
      if ( number[i] > sum/cnt ) {
        printf("%d\n", number[i]);
      }
    }
  }

  return 0;
}