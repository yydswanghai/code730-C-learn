// 结构初始化

#include <stdio.h>

void f1();
void f2();
struct date {// 声明结构
  int month;
  int day;
  int year;
};

int main(int argc, char const *argv[]) {
  // f1();
  f2();

  return 0;
}

void f1() {
  struct date today = {01, 24, 2024};
  struct date thismonth = {.month=1, .year=2024};

  printf("Today's date %i-%i-%i.\n", 
    today.year, today.month, today.day);
  printf("This month is %i-%i-%i.\n", 
    thismonth.year, thismonth.month, thismonth.day);
}

void f2() {
  struct date today;
  today = (struct date){24,01,2024};
  struct date day;
  day = today;
  day.year = 2020;

  printf("Today's date %i-%i-%i.\n", 
    today.year, today.month, today.day);
  printf("Day's date %i-%i-%i.\n", 
    day.year, day.month, day.day);
}
