#include <stdio.h>

void f(void);
void f2(void);
void f3(void);
void f4(void);

int main(int argc, char const *argv[]) {
  f4();

  return 0;
}

void f() {
  printf("%9d\n", 123);
  printf("%-9d\n", 123);
  printf("%+9d\n", 123);
  printf("%-9d\n", -123);

  printf("%09d\n", 123);
}
void f2() {
  // 9整个输出占据9位，.2小数点后面有两位
  printf("%9.2f\n", 123.0);
  // 占据6位
  printf("%*d\n", 6, 123);
}
void f3(){
  printf("%hhd\n", (char)12345);// 0x3039 只取后面的39，转换成10进制就是 57
}
void f4() {
  int num;
  printf("%dty%n\n", 12345, &num);
  printf("%d\n", num);
}