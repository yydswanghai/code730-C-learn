#include <stdio.h>
#include <string.h>

int mystrlen (const char *s);

int main(int argc, char const *argv[]) {
  char line[] = "Hello";
  printf("strlen=%lu\n", strlen(line));// 5个字符
  printf("sizeof=%lu\n", sizeof(line));// 占据空间：6字节，末尾还有\0
  printf("sizeof=%d\n", mystrlen(line));

  return 0;
}

int mystrlen (const char *s) {
  int cnt = 0;
  int idx = 0;
  while ( s[idx] != '\0' ) {
    idx++;
    cnt++;
  }
  return cnt;
}