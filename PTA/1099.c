// 性感素数
// "性感素数"是指形如 (p, p+6) 这样的一对素数。之所以叫这个名字，是因为拉丁语管“六”叫“sex”（即英语的“性感”）。
// （原文摘自 http://mathworld.wolfram.com/SexyPrimes.html）
// 现给定一个整数，请你判断其是否为一个性感素数。

// 输入格式：
// 输入在一行中给出一个正整数 N (≤10^8 )。

// 输出格式：
// 若 N 是一个性感素数，则在一行中输出 Yes，并在第二行输出与 N 配对的另一个性感素数（若这样的数不唯一，输出较小的那个）。若 N 不是性感素数，则在一行中输出 No，然后在第二行输出大于 N 的最小性感素数。

// 输入样例 1：

// 47
// 输出样例 1：

// Yes
// 41
// 输入样例 2：

// 21
// 输出样例 2：

// No
// 23