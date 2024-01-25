#include <stdio.h>
#include <stdbool.h>

struct date {
  int month;
  int day;
  int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

int main(int argc, char const *argv[]) {
  struct date today, tomorrow;

  printf("请输入今天日期，格式 (mm dd yyyy):");
  // &today.month .的优先级高 然后是&取地址
  scanf("%i %i %i", &today.month, &today.day, &today.year);
  
  if (today.day != numberOfDays(today)) {
    // day不是这个月的最后一天
    tomorrow.day = today.day +1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;
  } else if (today.month == 12) {
    // 12月并且day是这个月的最后一天
    tomorrow.day = 1;
    tomorrow.month = 1;
    tomorrow.year = today.year +1;
  } else {
    // 某个月的最后一天
    tomorrow.day = 1;
    tomorrow.month = today.month +1;
    tomorrow.year = today.year;
  }
  printf("Tomorrow's date is %i-%i-%i.\n",
    tomorrow.year, tomorrow.month, tomorrow.day);

  return 0;
}

int numberOfDays(struct date d) {
  int days;
  const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  if (d.month == 2 && isLeap(d)) {// 润年2月
    days = 29;
  } else {
    days = daysPerMonth[d.month - 1];
  }
  return days;
}
// 判断润年
bool isLeap(struct date d) {
  bool leap = false;
  if ( (d.year %4 == 0 && d.year %100 != 0) || d.year %400 == 0 ) {
    leap = true;
  }
  return leap;
}