/**
 * for循环
 * 小套路：
 * 做求和的程序时，记录结果的变量应该初始化为0，
 * 而做求积的程序时，记录结果的变量应该初始化为1
*/

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int fact = 1;

  // 1. 需要c99编译器
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  // 2. 或者你这样写
  int i = 1;
  for (i = 2; i <= n; i++) {
    fact *= i;
  }
  // 3. 也可以从 n 开始 n*n-1 ...
  for (i = n; i > 1; i--) {
    fact *= i;
  }
  
  printf("%d!=%d\n", n, fact);

  return 0;
}


int main2() {
  int n;
  scanf("%d", &n);
  int fact = 1;

  int i = n;
  // 4. 相当于让n自己去减，可以省掉初始化
  for (; i > 1; i--) {
    fact *= i;
  }
  
  printf("%d!=%d\n", i, fact);

  return 0;
}
