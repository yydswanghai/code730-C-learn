// 结构变量的名字并不是结构变量的地址
#include <stdio.h>

struct date {
  int month;
  int day;
  int year;
};

int main(int argc, char const *argv[]) {
  struct date today;
  today = (struct date){24,01,2024};
  struct date *pDate = &today;// 必须要用&

  printf("Today's date %i-%i-%i.\n", 
    today.year, today.month, today.day);

  printf("pDate=%p\n", pDate);

  return 0;
}
