// 都是在shell的缓冲区里面读写东西

#include <stdio.h>

int main(int argc, char const *argv[]) {
  int ch;

  while ( (ch = getchar()) != EOF ) {
    putchar(ch);
  }

  return 0;
}
