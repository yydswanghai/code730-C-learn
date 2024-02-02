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

* 要访问整个结构，直接用结构变量的名字
* 对于整个结构，可以做赋值、取地址，也可以传递给函数参数
  * `p1 = (struct point){5, 10};`相当于`p1.x=5;p1.y=10;`
  * `p1=p2;`相当于`p1.x=p2.x;p1.y=p2.y;`

## 结构指针

* 和数组不同，结构变量的名字并不是结构变量的地址，必须使用&运算符
* `struct date *pDate = &today;`

## 结构作为函数参数

`int numberOfDays(struct date d)`

* 整个结构可以作为参数的值传入函数
* 这时候是在函数内新建一个结构变量，并复制调用者的结构的值
* 也可以返回一个结构
* 这些都是和数组不一样的

## 输入结构

* 没有直接的方式可以一次scanf一个结构
* 如果我们打算写一个函数来读入结构
* 但是读入的结构如何送回来呢？
* 记住C在函数调用时是传值的
  * 所以函数中的p与main中的y是不同的 (test5)
  * 在函数读入了p的数值之后，没有任何东西回到main，所以y还是{0,0}

## 解决方案

* 之前的方案，把一个结构传入了函数，然后在函数中操作，但是没有返回回去
  * 问题在于传入函数的是外面那个结构的克隆体，而不是指针
    * 传入结构和传入数组是不同的
* 在这个输入函数中，完全可以创建一个临时的结构变量，然后把这个结构返回给调用者

## 结构指针作为参数

```c
struct date {
  int month;
  int day;
  int year;
} mydate;

struct date *p = &mydate;
// (*p).month = 12;
p->month = 12;
```

* 用`->`(减号加上大于号)表示指针所指的结构变量中的成员

## 结构数组

数组的每一个元素是一个结构变量

```c
struct date dates[100];
struct date dates[] = {
  {4,5,2005},{2,4,2005}
};
```

## 结构中的结构

```c
struct dateAndTime {
  struct date sdate;
  struct time stime;
}
```

## 嵌套的结构



## 自定义数据类型 (typedef)

* C语言提供了一个叫做`typedef`的功能来声明一个已有的数据类型的新名字，比如：

```c
typedef int Length;
```

使得`Length`成为`int`的别名

* 这样，`Length`这个名字就可以代替`int`出现在变量定义和参数声明的地方了

声明新的类型的名字
  * 新的名字是某种类型的别名
  * 改善了程序的可读性

最后一个才是它的别名，中间的是它实际的东西

```c
typedef long int64_t;
typedef struct ADate {
  int month;
  int day;
  int year;
} Date;
int64_t i = 100000000000;
Date d = {9,1,2005}

typedef *char[10] Strings;// Strings是10个字符串的数组
typedef struct node {
  int data;
  struct node *next;
} aNode;
// 或
typedef struct node aNode;// 这样用aNode就可以代替struct node
```

## 联合

```c
union AnEit {
  int i;
  char c;
} elt1, elt2;

elt1.i = 4;
elt2.c = 'a';
elt2.i = 0xDEADBEEF;
```

选择：成员是
* 一个`int i`还是
* 又一个`char c`
* 这两个成员占据了相同的内存空间，仅一份

`sizeof(union ...)` = sizeof(每个成员)的最大值

