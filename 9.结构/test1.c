// 结构

#include <stdio.h>

struct date {// 声明结构
  int month;
  int day;
  int year;
};

int main(int argc, char const *argv[]) {

  struct date today;// 变量类型是 struct date

  today.month = 01;
  today.day = 24;
  today.year = 2024;

  printf("Today's date %i-%i-%i.\n", 
    today.year, today.month, today.day);

  return 0;
}
