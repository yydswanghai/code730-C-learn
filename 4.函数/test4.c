// 类型不匹配

#include <stdio.h>

void cheer(int i) {
  printf("cheer %d\n", i);
}

int main() {
  cheer(2.4);

  cheer(2.0);

  double f = 2.4;
  cheer(f);

  return 0;
}
