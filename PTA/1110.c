// 区块反转

// 给定一个单链表 L，我们将每 K 个结点看成一个区块（链表最后若不足 K 个结点，也看成一个区块），请编写程序将 L 中所有区块的链接反转。例如：给定 L 为 1→2→3→4→5→6→7→8，K 为 3，则输出应该为 7→8→4→5→6→1→2→3。

// 输入格式：
// 每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、以及正整数 K (≤N)，即区块的大小。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

// 接下来有 N 行，每行格式为：

// Address Data Next

// 其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

// 输出格式：
// 对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

// 输入样例：

// 00100 8 3
// 71120 7 88666
// 00000 4 99999
// 00100 1 12309
// 68237 6 71120
// 33218 3 00000
// 99999 5 68237
// 88666 8 -1
// 12309 2 33218

// 输出样例：

// 71120 7 88666
// 88666 8 00000
// 00000 4 99999
// 99999 5 68237
// 68237 6 00100
// 00100 1 12309
// 12309 2 33218
// 33218 3 -1