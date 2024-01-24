#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char s1[] = "abc";
  char s2[] = "abc";
  strcpy(s1, s2);

  return 0;
}
// 数组实现
char mystrcpy (char *restrict dst, const char *restrict src) {
  int idx = 0;
  while (src[idx] != '\0') {
    dst[idx] = src[idx];
    idx++;
  }
  dst[idx] = '\0';
  return dst;
}
// 指针实现
char mystrcpy (char *restrict dst, const char *restrict src) {
  char *ret = dst;
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';

  return ret;
}