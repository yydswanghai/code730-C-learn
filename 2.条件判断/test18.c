// 求最大公约数
#include <stdio.h>

// 1.枚举
int main2() {
  int a,b;
  int min;

  scanf("%d %d", &a, &b);
  if (a < b) {
    min = a;
  } else {
    min = b;
  }
  int ret = 0;
  int i;
  for ( i = 1; i < min; i++) {
    if (a % i == 0) {
      if (b % i == 0) {
        ret = i;
      }
    } 
  }
  printf("%d %d %d", a, b, ret);

  return 0;
}

// 2. 辗转相除法
// a   b   t  
// 12  18
// 12  18  12  // 1. a/b的余数，也就是a%b，余数给t
// 18  12      // 2. 让a=b b=t
// 18  12  6   // 3. 回到第一步
// 12  6       // 4. 让a=b b=t
// 12  6   0   // 5. 回到第一步
// 6   0       // b=0了，这个6就是最大公约数

int main() {
  int a,b;
  int t;
  scanf("%d %d", &a, &b);
  while (b != 0) {
    t = a % b;
    a = b;
    b = t;
    printf("a=%d,b=%d,t=%d\n", a, b, t);
  }
  printf("gcd=%d\n", a);

  return 0;
}