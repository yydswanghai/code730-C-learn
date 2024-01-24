// 一个字符加一个数字得到的是ASCll码表中的那个数之后的字符
// 两个字符的减，得到它们在表中的距离

#include <stdio.h>

int main() {
  char c = 'A';
  c++;
  printf("%c\n", c);

  int i = 'Z' - 'A';
  printf("%d\n", i);

  return 0;
}