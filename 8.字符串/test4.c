// 查看main函数的参数好
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i;
  for ( i = 0; i < argc; i++) {
    printf("%d:%s\n", i, argv[i]);
  }

  return 0;
}
