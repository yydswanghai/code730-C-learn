// 级联的 if-else if

#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);
  // 单一出口，推荐
  int f = 0;
  if (x < 0) {
    f = -1;
  } else if (x == 0) {
    f = 0;
  } else {
    f = 2 * x;
  }
  printf("%d\n", f);

  return 0;
}

// 多个出口，不推荐，导致结果写死了，仅能做printf()，不利于后续扩展
if (x < 0) {
  printf("%d\n", -1);
} else if (x == 0) {
  printf("%d\n", 0);
} else {
  printf("%d\n", 2 * x);
}