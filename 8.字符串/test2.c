// 字符串输入输出

#include <stdio.h>

int main(void) {
  // f();
  // f2();
  f3();

  return 0;
}
void f() {
  char word[8];
  scanf("%s", word);
  printf("%s##\n", word);
}

void f2() {
  char word[8];
  char word2[8];
  scanf("%s", word);
  scanf("%s", word2);
  printf("%s##%s##\n", word, word2);
}

// 不安全，会发生数组越界
void f3() {
  char word[8];
  char word2[8];
  scanf("%7s", word); // 最多只让读7个字符
  scanf("%7s", word2);
  printf("%s##%s##\n", word, word2);
}