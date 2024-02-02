// 错误定义的宏
#include <stdio.h>

#define RADTOOEG1(x) (x*57.29578)
#define RADTOOEG2(x) (x)*57.29578

int main(int argc, char const *argv[]) {
  printf("%f\n", RADTOOEG1(5+2));
  printf("%f\n", 180/RADTOOEG2(1));

  return 0;
}
// 编译的临时文件里的代码
// int main(int argc, char const *argv[]) {
//   printf("%f\n", (5+2*57.29578));
//   printf("%f\n", 180/(1)*57.29578);

//   return 0;
// }
