// 如何输入'1'这个字符给char c?

#include <stdio.h>

int main() {
  char c;
  scanf("%c", &c);
  printf("c=%d\n", c);
  printf("c='%c'\n", c);

  return 0;
}

// scanf 不支持c，只能使用i，然后将i赋值给c
int main2() {
  int i;
  char c;
  scanf("%d", &i);// 1 49 65
  c = i;
  printf("c=%d\n", c);// 1 49 65
  printf("c='%c'\n", c);// '' '1' 'A'
  // 表达不出来就是 ''
  return 0;
}

int main3() {
  if (49 == '1') {
    printf("OK");
  }
  return 0;
}