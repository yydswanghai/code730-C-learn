// 传入函数的数组成了什么？

#include <stdio.h>

void minmax(int a[], int len, int *min, int *max);

int main() {
  int a[] = {2,3,4,5,6,7,9,12,13,14,16,17,21,23,55};
  int min, max;
  printf("main sizeof(a) %lu\n", sizeof(a));
  printf("main a=%p\n", a);
  minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
  printf("min=%d,max=%d,a[0]=%d\n", min, max, a[0]);

  return 0;
}

void minmax(int *a, int len, int *min, int *max) {
    int i;
    printf("minmax sizeof(a) %lu\n", sizeof(a));
    printf("minmax a=%p\n", a);
    *min = *max = a[0];
    a[0] = 1000;
    for ( i = i; i < len; i++) {
      if (a[i] < *min) {
        *min = a[i];
      }
      if (a[i] > *max) {
        *max = a[i];
      }
    }
}