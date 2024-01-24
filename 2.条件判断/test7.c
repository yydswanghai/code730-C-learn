// switch
// 注意：switch 是直接case到对应的值，然后走对应的代码块
// 例如输入type=3 1. 在级联的if-else中
// type会先进入第一个括号内判断，不等于，继续到第二个，也不等于，到type=3的时候关系成立，运行代码块
// 2. 在 switch 会直接跳，匹配到case 3:的位置，直接运行冒号后的代码块，遇到break退出

#include <stdio.h>

int main() {
  int type;
  
  printf("请输入type：");
  scanf("%d", &type);

  // 与级联的if-else对比
  if (type == 1) {
    printf("你好");
  } else if (type == 2) {
    printf("早上好");
  } else if (type == 3) {
    printf("晚上好");
  } else if (type == 4) {
    printf("再见");
  }

  // 注意：case只是一个站台，不会停下来
  switch (type) {// 括号内（控制表达式）只能是整数类型的结果
    case 1:// 意思：如果 type == 1，运行冒号后面的代码，直到遇到 break 为止
      printf("你好");
      break;
    case 2:// 意思：如果 type == 2，运行冒号后面的代码，直到遇到 break 为止
      printf("早上好");
      break;
    case 3:// 意思：如果 type == 3，运行冒号后面的代码，直到遇到 break 为止
      printf("晚上好");
      break;
    case 4:// 意思：如果 type == 4，运行冒号后面的代码，直到遇到 break 为止
      printf("再见");
      break;
    default:// 如果 type 不等于 1,2,3,4 中的任何一个，运行 default冒号后面的代码
      printf("啊！什么啊！");
  }

  // type=1 输出 "早上好" 
  switch (type) {
    case 1:
    case 2:
      printf("早上好");
      break;
    case 3:
      printf("晚上好");
      break;
    case 4:
      printf("再见");
      break;
    default:
      break;
  }

  return 0;
}
