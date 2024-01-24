// 整数求逆 12345 => 54321
// 700 => 7
// 700 => 007

#include <stdio.h>

int main() {
  int x = 700;
  // scanf("%d", &x)
  
  int digit;
  int ret = 0;
  
  while (x > 0)
  {
    digit = x%10;// 5 4 3 2 1 
    printf("%d", digit);
    ret = ret * 10 + digit;// 5 54 543 5432 54321
    // printf("x=%d, digit=%d, ret=%d\n", x, digit, ret);
    x /= 10;// 12345 1234 123 12 1
  }

  return 0;
}
