
#include <stdlib.h>
#include <stdio.h>

// 1024 = 1K
// 1024*1024 = 1MB

int main() {
  void *p;
  int cnt = 0;
  // 地址不是0，就会继续循环，得到的地址是0，退出循环
  while (p = malloc(100*1024*1024)) {
    cnt++;
  }
  printf("分配了%d00MB的空间\n", cnt);

  return 0;
}