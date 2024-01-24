// 水仙花数 153 = 1^3 + 5^3 + 3^3
// 输入一个数字n，表示当前n位数里一共有多少个水仙花数
// 输入3
// 3位数范围 100~999 的水仙花数分别是哪些？

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int first = 1;
  int i = 1;

  while (i<n) {
    first *= 10;
    i++;
  }
  i = first;// 100
  // 循环n位数的范围 100 ~ 999
  while (i < first*10) {
    int t = i;// 例如 t=153
    int sum = 0;
    do
    {
      int d = t % 10;// 取出最后一位 1 5 3
      t /= 10;
      // 计算幂次方
      int m = d;
      int j = 1;
      while (j < n) {
        m *= d;
        j++;
      }
      sum += m;
    } while (t > 0);
    if (sum == i) {
      printf("%d\n", i);
    }
    i++;
  }

  return 0;
}
