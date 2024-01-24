// 动态内存分配

#include <stdlib.h>
#include <stdio.h>

int main() {
  int number;
  int *a;
  int i;
  printf("输入数量：");
  scanf("%d", &number);
  // int a[number]; C99

  a = (int*)malloc(number*sizeof(int));// C99之前
  // 之后a就可以当作数组使用了
  for ( i = 0; i < number; i++) {
    scanf("%d", &a[i]);
  }
  for ( i = number-1; i >= 0; i--) {
    printf("%d ", a[i]);
  }
  free(a);// 归还内存

  return 0;
}