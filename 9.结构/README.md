## 声明结构的形式

```c
struct point {// 结构类型
  int x;
  int y;
}

struct point p1, p2;// 结构变量
```

p1和p2都是point，里面都有x值和y值。

```c
struct {
  int x;
  int y;
} p1, p2;
```

p1和p2都是一种无名结构，里面都有x值和y值。

```c
struct point {
  int x;
  int y;
} p1, p2;
```

这种是最常用的声明形式。

## 结构的初始化

```c
struct date today = {01, 24, 2024};
struct date thismonth = {.month=1, .year=2024};
```

## 结构成员

* 结构和数组有点像
* 数组用[]运算符和下标访问其成员
  * `a[0] = 10;`
* 结构用.运算符和名字访问其成员
  * `today.day`

## 结构运算

* 要访问整个结构，直接用结构变量