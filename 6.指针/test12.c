// 

#include <stdio.h>

void minmax(int *a);

int main() {
  int a[] = {2,3,4,5,6,7,9,12,13,14,16,17,21,23,55};

  minmax(a);
  printf("*a=%d\n", *a);

  return 0;
}

void minmax(int a[]) {
  a[0] = 1000;
}