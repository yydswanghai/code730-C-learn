// 输入结构
#include <stdio.h>

struct point {
  int x;
  int y;
};
struct point* getStruct(struct point *);
void output(struct point);
void print(const struct point *p);
int main(int argc, char const *argv[]) {
  struct point y = {0, 0};
  getStruct(&y);
  output(y);
  output(*getStruct(&y));// *运算符取出它右边那个所指的变量 *getStruct(&y)
  print(getStruct(&y));// getStruct得到的指针传递给print
  *getStruct(&y) = (struct point){1, 2};

  return 0;
}

struct point* getStruct(struct point *p){
  scanf("%d", &p->x);
  scanf("%d", &p->y);
  printf("getStruct函数里的x=%d,y=%d\n", p->x, p->y);
  return p;// 返回指针
}
// 输出y
void output(struct point p){
  printf("main函数里的x=%d,y=%d\n", p.x, p.y);
}
void print(const struct point *p){
  printf("x=%d,y=%d\n", p->x, p->y);
}