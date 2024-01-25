// 输入结构
#include <stdio.h>

struct point {
  int x;
  int y;
};
void getStruct(struct point);
void output(struct point);
int main(int argc, char const *argv[]) {
  struct point y = {0, 0};
  getStruct(y);
  output(y);
  return 0;
}
// getStruct 里只有y的值，这和数组完全不一样
// 所以在 getStruct 作赋值，和外面的y已经没有任何关系
void getStruct(struct point p){
  scanf("%d", &p.x);
  scanf("%d", &p.y);
  printf("getStruct函数里的x=%d,y=%d\n", p.x, p.y);
}
// 输出y
void output(struct point p){
  printf("main函数里的x=%d,y=%d\n", p.x, p.y);
}