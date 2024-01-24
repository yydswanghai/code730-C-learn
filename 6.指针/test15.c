// 指针运算

#include <stdio.h>

int main() {
  char ac[] = {0,1,2,3,4,5,6,7,8,9};
  char *p = &ac[0];  
  char *p1 = &ac[5];
  printf("p=%p\n", p);  // 0x16ae3f088
  printf("p1=%p\n", p1);// 0x16ae3f08d
  printf("p1-p=%ld\n", p1-p);

  int ai[] = {0,1,2,3,4,5,6,7,8,9};
  int *q = ai;
  int *q1 = &ai[6];
  printf("q=%p\n", q);  // 0x16ae3f060
  printf("q1=%p\n", q1);// 0x16ae3f078  相差16+8=24
  printf("q1-q=%ld\n", q1-q);

  return 0;
}