// 链表合并

// 给定两个单链表 L1=a1→a2→⋯→an−1→an 和 L2=b1→b2→⋯→bm−1→bm。如果 n≥2m，你的任务是将⽐较
// 短的那个链表逆序，然后将之并⼊⽐较⻓的那个链表，得到⼀个形如 a1→a2→bm→a3→a4→bm−1⋯ 的结果。
// 例如给定两个链表分别为 6→7 和 1→2→3→4→5，你应该输出 1→2→7→3→4→6→5。

// 输⼊格式：
// 输⼊⾸先在第⼀⾏中给出两个链表 L1 和 L2 的头结点的地址，以及正整数
// N (≤105)，即给定的结点总数。⼀个结点的地址是⼀个 5 位数的⾮负整数，空地址 NULL ⽤ -1 表示。
// 随后 N ⾏，每⾏按以下格式给出⼀个结点的信息：

// Address Data Next

// 其中 Address 是结点的地址，Data 是不超过 10^5 的正整数，Next 是下⼀个结点的地址。题⽬保证没有空链表，
// 并且较⻓的链表⾄少是较短链表的两倍⻓。

// 输出格式：
// 按顺序输出结果链表，每个结点占⼀⾏，格式与输⼊相同。

// 输⼊样例：

// 00100 01000 7
// 02233 2 34891
// 00100 6 00001
// 34891 3 10086
// 01000 1 02233
// 00033 5 -1
// 10086 4 00033
// 00001 7 -1

// 输出样例：

// 01000 1 02233
// 02233 2 00001
// 00001 7 34891
// 34891 3 10086
// 10086 4 00100
// 00100 6 00033
// 00033 5 -1