// scanf("%d %c", &i, &c);
// scanf("%d%c", &i, &c);
// 有无空格是不一样的

#include <stdio.h>

// 输入：12 1
// 输出：i=12,c=49,c='1'
// 输入：12 a
// 输出：i=12,c=97,c='a'
// 输入：12  1
// 输出：i=12,c=49,c='1'
int main() {
  int i;
  char c;
  scanf("%d %c", &i, &c);
  printf("i=%d,c=%d,c='%c'\n", i, c, c);

  return 0;
}

// 输入：12 1
// 输出：i=12,c=32,c=' '
// 输入：12 a
// 输出：i=12,c=32,c=' '
// 输入：12  1
// 输出：i=12,c=32,c=' '
int main() {
  int i;
  char c;
  scanf("%d%c", &i, &c);
  printf("i=%d,c=%d,c='%c'\n", i, c, c);

  return 0;
}