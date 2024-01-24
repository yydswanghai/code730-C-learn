// 结构初始化

#include <stdio.h>

struct date {// 声明结构
  int month;
  int day;
  int year;
};

int main(int argc, char const *argv[]) {
  struct date today = {01, 24, 2024};
  struct date thismonth = {.month=1, .year=2024};

  printf("Today's date %i-%i-%i.\n", 
    today.year, today.month, today.day);
  printf("This month is %i-%i-%i.\n", 
    thismonth.year, thismonth.month, thismonth.day);

  return 0;
}
