// 使用自定义函数求素数

#include <stdio.h>

// 判断i是不是一个素数
int isPrime(int i) {
    int ret = 1;
    int k;
    for ( k = 2; k < i-1; k++) {
      if (i%k == 0) {
        ret = 0;
        break;
      }
    }
    return ret;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int cnt = 0;
  int sum = 0;

  if (m == 1) m = 2;
  int i;
  for ( i = m; i <= n; i++) {
    if ( isPrime(i) ) {
      sum += 1;
      cnt++;
    }
  }
  printf("%d %d\n", cnt, sum);

  return 0;
}