#include <stdio.h>
#include <string.h>

int mystrcmp (const char *s1, const char *s2);
int mystrcmp2 (const char *s1, const char *s2);

int main(int argc, char const *argv[]) {
  char s1[] = "abc";
  char s2[] = "abc";
  
  printf("%d\n", s1 == s2);// 0: 数组的比较永远是0（false），因为这里是对比地址是否相同
  printf("%d\n", strcmp(s1, s2));// 0
  
  char s3[] = "bbc";
  printf("%d\n", strcmp(s1, s3));// -1: s3 < s4

  char s4[] = "Abc";
  printf("%d\n", strcmp(s1, s4));// 32
  printf("%d\n", 'a'-'A');// 32

  char s5[] = "abc ";
  printf("%d\n", strcmp(s1, s5));// -32

  return 0;
}
// 用数组实现
int mystrcmp (const char *s1, const char *s2) {
  int idx = 0;
  while (s1[idx] == s2[idx] && s1[idx] != '\0') {
    // if (s1[idx] != s2[idx]) {
    //   break;
    // } else if (s1[idx] != '\0') {
    //   break;
    // }
    idx++;
  }
  return s1[idx] - s2[idx]; 
}
// 用指针实现
int mystrcmp2 (const char *s1, const char *s2) {
  while (*s1 == *s2 && *s1 != '\0') {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}