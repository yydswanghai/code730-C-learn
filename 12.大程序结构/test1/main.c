#include <stdio.h>
#include "max.h"

int main(int argc, char const *argv[]) {
  int a=5;
  int b=6;
  printf("%d\n", max(a,b));
  printf("%d\n", max(a,gAll));

  return 0;
}
