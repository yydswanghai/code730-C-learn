// 9x9乘法表

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  i = 1;

  // 1 ~ n
  while (i <= n) {
    j = 1;
    while (j <= i) {
      printf("%d*%d=%d ", j, i, i*j);
      if (i*j < 10) {
        printf("  ");
      } else {
        printf(" ");
      }
      j++;
    }
    printf("\n");
    i++;
  }

  return 0;
}
