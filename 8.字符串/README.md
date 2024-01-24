## 字符数组

这不是C语言的字符串，因为不能用字符串的方式做计算

```c
char word[] = {'H', 'E', 'L', 'L', 'O', '!'};
```

## 字符串

最后加入了一个特殊的单引号，里面是反斜杠和数字0
* C语言的字符串是以字符数组的形态存在的
  * 不能用运算符对字符串做运算
  * 通过数组的方式可以遍历字符串
* 唯一特殊的地方是字符串字面量可以用来初始化字符数组
* 以及标准库提供了一系列字符串函数

```c
char word[] = {'H', 'E', 'L', 'L', 'O', '!', '\0'};
```

* 以0（整数0）结尾的一串字符
  * 0或'\0'是一样的，但是和'0'不同
* 0标志字符串的结束，但它不是字符串的一部分
  * 计算字符串长度的时候不包含这个0
* 字符串以数组的形式存在，以数组或指针的形式访问
  * 更多的是以指针的形式
* string.h 里有很多处理字符串的函数

## 字符串变量

* `char *str = "hello";`
* `char word[] = "hello";`
* `char line[10] = "hello";`

## 字符串常量

* "Hello"
* "Hello"会被编译器变成一个字符数组放在某处，这个数组的长度是6，结尾还有表示结束的0
* 两个相邻的字符串常量会被自动连接起来

```c
char *s = "Hello world";// 这是指针
```

* s是一个指针，初始化为指向一个字符串常量
  * 由于这个常量所在的地方，所以实际上s是`const char *s`，但由于历史的原因，编译器接受不带const的写法
  * 但是试图对s所指的字符串做写入会导致严重的后果
* 如果需要修改字符串，应该用数组：

```c
char s[] = "Hello world";// 这是数组
```

## 指针还是数组？

* `char *str = "hello";`
* `char str[] = "hello";`
* 数组：这个字符串在这里
  * 作为本地变量空间自动被回收
* 指针：这个字符串不知道在哪里
  * 处理参数
  * 动态分配空间

## 字符串赋值

```c
char *t = "title";
char *s;
s = t;
```

* 并没有产生新的字符串，只是让指针s指向了t所指的字符串，对s的任何操作就是对t做的

## 字符串输入输出

* `scanf("%s", string);`
* `printf("%s", string);`

* scanf读入一个单词（到空格、tab或回车为止）
* scanf是不安全的，因为不知道要读入的内容的长度
* 在%和s之间的数字表示最多允许读入的字符的数量，这个数字应该比数组的大小小一

## 常见错误

```c
char *string;
scanf("%s", string);
```

* 以为char*是字符串类型，定义了一个字符串类型的变量string就可以直接使用了
  * 由于没有对string进行初始化为0，所以不一定每次运行都出错
* `char buffer[100] = "";`
  * 这是一个空的字符串，`buffer[0] = "\0";`
* `char buffer[] = "";`
  * 这个数组的长度只有1！

## 字符串数组

* `char **a;`
  * a是一个指针，指向另一个指针，那个指针指向一个字符（串）
* `char a[][]`
  * a是一个二维数组，二维数组定义时，第二维一定是要有确定的大小
  
## 程序参数

```c
int main(int argc, char const * argv[]);
```

argc用来告诉你argv有多大
* argv[0]是命令本身
  * 当使用Unix的符号链接时，反映符号链接的名字

## putchar

* int putchar(int c);
* 向标准输出写一个字符
* 返回写了几个字符，EOF（-1）表示写失败

## getchar

* int getchar(void);
* 从标准输入读入一个字符
* 返回类型是int是为了返回EOF（-1）
    * Windows --> Ctrl+Z
    * Unix --> Ctrl+D

## string.h

* strlen
  * `size_t strlen(const char *s)` 
  * 返回s的字符串长度（不包括结尾的0）
* strcmp
  * `int strcmp(const char *s1, const char *s2)`
  * 比较两个字符串，返回：
    * 0：s1 == s2
    * 1：s1 > s2
    * -1：s1 < s2
* strcpy
  * `char * strcpy(char *restrict dst, const char *restrict src)`
  * 把src（源）的字符串拷贝到dst（目的）
    * restrict表明src和dst不重叠（C99）
  * 返回dst
    * 为了能链起代码来
  * 复制一个字符串
* strcat
  * `char * strcat(char *restrict s1, char *restrict s2)`
  * 把s2拷贝到s1的后面，接成一个长的字符串
  * 返回s1
  * s1必须具有足够的空间
* strchr
  * `char * strchr(const char *s, int c)`
  * `char * strrchr(const char *s, int c)`
    * 寻找字符c第一次出现的位置（指针）
    * 返回NULL表示没有找到
    * 如何寻找第2个？
* strstr
  * `char * strsrt(const char *s1, const char *s2)`
  * `char * strcasestr(const char * s1, const char * s2)`
  * 在字符串中寻找字符串

* 不安全的
  * strcpy和strcat都可能出现安全问题
  * 如果目的地没有足够的空间？
* 安全版本
  * `char * strncpy(char *restrict dst, const char *restrict src, size_t n)`
  * `char * strncat(char *restrict s1, char *restrict s2, size_t n)`
  * `int strncmp(const char *s1, const char *s2, size_t n)`

## 枚举

* 枚举是一种用户定义的数据类型，它用关键字 enum 以如下语法来声明：

```c
enum 枚举类型名 {名字0, ... , 名字n};
```

* 枚举类型名字通常并不真多使用，要用的是在大括号里的名字，因为它们就是常量符号，它们的类型是int，值依次是从0到n。如：
* 就创建了三个常量，red的值是0，yellow是1，而green是2。
* 当需要一些可以排列起来的常量值时，定义枚举的意义就是给了这些常量值名字。

```c
enum color {red, yellow, green};
```

* 枚举可以作为值
* 枚举类型可以跟上 enum 作为类型
* 但是实际上是以整数来做内部计算和外部输入输出的

## 枚举量

* 声明枚举量的时候可以指定值
  * `enum COLOR {RED=1, YELLOW, GREEN=5};`

## 枚举只是int

```c
enum COLOR {RED=1, YELLOW, GREEN=5, NumCOLORS};
int main () {
  enum COLOR color = 0;
  printf("code for GREEN is %d\n", GREEN);
  printf("and color is %d\n", color);
}
```

* 即使给枚举类型的变量赋值不存在的整数值也没有任何warning或error
* 虽然枚举类型可以当作类型使用，但是实际上很(bu)少(hao)用
* 如果有意义上排比的名字，用枚举比`const int`方便
* 枚举比宏（macro）好，因为枚举有int类型

