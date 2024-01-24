// 判断素数
// 1. 从2到x-1，每次加1
// 2. 因偶数都不是素数，去掉偶数后，从3到x-1，每次加2
// 3. 判断是否能被已知的且<的素数整除
//      需要用一个数组来存放已知的素数

#include <stdio.h>
#include <math.h>

int isPrime(int x, int knowPrimes[], int numberOfKnowPrimes);

int main() {
  const int number = 10;
  int prime[number] = {2};// 2 0 0 0 ... 
  int count = 1;// prime的下标
  int i = 3;// 数字，从3开始

  while (count < number) {
    if ( isPrime(i, prime, count) ) {
      prime[count++] = i;// 每次找到一个是素数，将i写入到count下标的位置，并且将count向后移动一位
    }
    {// 调试
      printf("i=%d, cnt=%d\t", i, count);
      int i;
      printf("[");
      for ( i = 0; i < number; i++) {
        if (prime[i] > 0) {
          printf(" %d ", prime[i]);
        }
      }
      printf("]");
      printf("\n");
    }
    i++;
  }
  printf("找到的%d个素数为：", number);
  for ( i = 0; i < number; i++) {
    printf("%d ", prime[i]);
  }

  return 0;
}

int isPrime(int x, int knowPrimes[], int numberOfKnowPrimes) {
  int ret = 1;
  int i;
  for ( i = 0; i < numberOfKnowPrimes; i++) {
    if (x%knowPrimes[i] == 0) {
      ret = 0;
      break;
    }
  }
  return ret;
}