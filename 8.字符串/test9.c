// strchr使用
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f1();
void f2();
void f3();

int main(int argc, char const *argv[]) {
  // f1();
  // f2();
  f3();

  return 0;
}
// 找到字符串里的字符l以及字符l后面的字符l
// s = ['h', 'e', 'l', 'l', 'o', '\0'];
//                 p
void f1() {
  char s[] = "hello";
  char *p = strchr(s, 'l');
  printf("%s\n", p);
  p = strchr(p+1, 'l');
  printf("%s\n", p);
}
// 找到字符串里的l，并复制l后面的那段字符串
void f2() {
  char s[] = "hello";
  char *p = strchr(s, 'l');
  printf("%s\n", p);
  char *t = (char*)malloc(strlen(p)+1);// 申请动态内存，大小为p字符串长度+1，因为末尾\0
  strcpy(t, p);
  printf("%s\n", t);
  free(t);
}
// 找到字符串里的l，并复制l前面的那段字符串
// s = ['h', 'e', 'l', 'l', 'o', '\0'];
//                 p
// s = ['h', 'e', '\0', 'l', 'o', '\0']
void f3() {
  char s[] = "hello";
  char *p = strchr(s, 'l');
  printf("%s\n", p);
  char c = *p;
  *p = '\0';
  char *t = (char*)malloc(strlen(s)+1);
  strcpy(t, s);
  printf("%s\n", t);
  free(t);
}
