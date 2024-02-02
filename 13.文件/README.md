## 格式化的输入输出

* printf
  * %[flags][width][.prec][hlL]type

| Flag    | 含义        |
| ------- | ---------- |
| -       | 左对齐      |
| +       | 在前面放+或- |
| (space) | 正数留空     |
| 0       | 0填充       |

| width或prec | 含义                   |
| ----------- | --------------------- |
| number      | 最小字符数              |
| *           | 下一个参数是字符数        |
| .number     | 小数点后的位数           |
| .*          | 下一个参数是小数点后的位数 |

| 类型修饰 | 含义         |
| ------- | ----------- |
| hh      | 单个字节     |
| h       | short       |
| l       | long        |
| ll      | long long   |
| L       | long double |

| type | 用于            |
| ---- | --------------- |
| i或d | int             |
| u    | unsigned int    |
| o    | 八进制           |
| x    | 十六进制         |
| X    | 字母大写的十六进制 |
| f或F | float,6         |
| e或E | 指数             |
| g    | float           |
| G    | float           |
| a或A | 十六进制浮点      |
| c    | char            |
| s    | 字符串           |
| p    | 指针             |
| n    | 读入/写出的个数   |

* scanf
  * %[flag]type

| Flag    | 含义        |
| ------- | ---------- |
| *       | 跳过        |
| 数字     | 最大字符数  |
| hh      | char       |
| h       | short      |
| l       | long,double|
| ll      | long long  |
| L       | long double|

| type    | 用于            |
| ------- | --------------- |
| d       | int             |
| i       | 整数，可能为十六进制或八进制 |
| u       | unsigned int    |
| o       | 八进制           |
| x       | 十六进制         |
| a,e,f,g | float           |
| c       | char            |
| s       | 字符串           |
| [...]   | 所允许的字符      |
| p       | 指针             |

## printf和scanf的返回值

* 读入的项目数
* 输出的字符数

* 在要求严格的程序中，应该判断每次调用scanf或printf的返回值，从而了解程序运行中是否存在问题

## 文件输入输出

* 用>和<做重定向

```shell
./test > 12.out
12345
more 12.out

cat > 12.in
12345
more 12.in

./test < 12.in
```

## FILE

* FILE* fopen(const char * restrict path, const char * restrict mode);
* int fclose(FILE *stream)
* fscanf(FILE*, ...)
* fprintf(FILE*, ...)

fopen参数二
| 参数 | 含义    |
| --- | ------- |
| r   | 打开只读 |
| r+  | 打开读写，从文件头开始 |
| w   | 打开只写，如果不存在则新建，如果存在则清空 |
| w+  | 打开读写，如果不存在则新建，如果存在则清空 |
| a   | 打开追加，如果不存在则新建，如果存在则从文件尾开始 |
| x   | 只新建，如果文件已存在则不能打开         |

```c
// 打开文件的标准代码
FILE* fp = fopen("file", "r");
if (fp) {
  fscanf(fp, ...);
  fclose(fp);
} else {
  // ...
}
```

## 二进制文件

* 其实所有的文件最终都是二进制的
* 文本文件无非是用最简单的方式可以读写的文件
  * more、tail
  * cat
  * vi
* 而二进制文件是需要专门的程序来读写的文件
* 文本文件的输入输出是格式化，可能经过转码

## 文本vs二进制

* Unix喜欢用文本文件来做数据存储和程序配置
  * 交互式终端的出现使得人们喜欢用文本和计算机“talk”
  * Unix的shell提供了一些读写文件的小程序
* Windows喜欢用二进制文件
  * DOS是草根文化，并不继承和熟悉Unix文化
  * PC刚开始的时候能力有限，DOS的能力更有限，二进制更接近底层

* 文本的优势是方便人类读写、而且跨平台
* 文本的缺点是程序输入输出要经过格式化，开销大
* 二进制的缺点是人类读写困难，而且不跨平台
  * int的大小不一致，大小端端问题
* 二进制的优点是程序读写快

## 程序为什么要文件

* 配置
  * Unix用文本，Windows用注册表
* 数据
  * 稍微有点量的数据都放数据库了
* 媒体
  * 这个只能是二进制的
* 现实是，程序通过第三方库来读写文件，很少直接读写二进制文件了

## 二进制读写

* size_t fread(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
* size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
* 参数一：指针，你要读或写的那块内存，参数二：这块内存大小，参数三：有几个这样的内存，参数四：文件指针
* 注意FILE指针是最后一个参数
* 返回的是成功读写的字节数

为什么nitem?

* 因为二进制文件的读写一般都是通过对一个结构变量的操作来进行的
* 于是nitem就是用来说明这次读写几个结构变量！

## 在文件中定位

* long ftell(FILE *stream);
* int fseek(FILE *stream, long offset, int whence);
  * SEEK_SET：从头开始
  * SEEK_CUR：从当前位置开始
  * SEEK_END：从尾开始（倒过来）

## 可移植性

* 这样的二进制文件不具有可移植性
  * 在int为32位的机器上写成的数据文件无法直接在int为64位的机器上正确读出
* 解决方案之一是放弃使用int，而是typedef具有明确大小的类型
* 更好的方案是用文本

