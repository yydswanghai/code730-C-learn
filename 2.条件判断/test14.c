// break 跳出循环
// continue 跳过循环这一轮剩下的语句，进入下一轮
// 素数 2 3 5 7 11 13

#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);

  int i;
  int isPrime = 1;// x是素数，isPrime设置成1，是用于证伪
  for (i = 2; i < x; i++) {
    if (x % i == 0) {// ==0说明x能被i整除，x就不是素数
      isPrime = 0;// 如果证明是伪，则变量赋值为0
      continue;// 如果满足这个if 这一轮放弃，进行下一轮，不会打印i了
    }
    printf("%d", i);
  }
  if (isPrime == 1) {
    printf("是素数\n");
  } else {
    printf("不是素数\n");
  }

  return 0;
}

int main2() {
  int x;
  scanf("%d", &x);

  int i;
  for (i = 2; i < x; i++) {
    if (x % i == 0) {
      break;
    }
  }
  if (i == x) {
    printf("是素数\n");
  } else {
    printf("不是素数\n");
  }

  return 0;
}
// 100以内的素数
int main3() {
  int x;
  for ( x = 2; x < 100; x++)
  {
    int i;
    int isPrime = 1;
    for (i = 2; i < x; i++) {
      if (x % i == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime == 1) {
      printf("%d ", x);
    }
  }
  printf("\n");

  return 0;
}
// 前50个
int main4() {
  int x;
  x = 2;
  int cnt = 0;
  while ( cnt < 50)
  {
    int i;
    int isPrime = 1;
    for (i = 2; i < x; i++) {
      if (x % i == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime == 1) {
      printf("%d ", x);
      cnt++;
    }
    x++;
  }
  printf("\n");

  return 0;
}