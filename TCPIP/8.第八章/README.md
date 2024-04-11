## 问题

* 在浏览器地址栏输入www.orentec.co.kr，并整理出主页显示过程。假设浏览器访问的默认DNS服务器中并没有关于www.orentec.co.kr的IP地址信息

1. 用户在浏览器地址栏中输入 www.orentec.co.kr。
2. 浏览器发现本地没有该域名对应的 IP 地址信息。
3. 浏览器向操作系统发起 DNS 查询请求，询问默认的 DNS 服务器关于 www.orentec.co.kr 的 IP 地址。
4. 默认的 DNS 服务器接收到查询请求后，在自己的记录中查找 www.orentec.co.kr 的 IP 地址。
5. 如果默认的 DNS 服务器中没有 www.orentec.co.kr 的记录，则它会向根域名服务器发送查询请求，询问该域名的 authoritative name server（权威域名服务器）。
6. 根域名服务器返回给默认的 DNS 服务器一个包含 .kr 顶级域的权威域名服务器的 IP 地址。
7. 默认的 DNS 服务器向权威域名服务器发送查询请求，询问关于 orentec.co.kr 的 IP 地址。
8. 权威域名服务器返回给默认的 DNS 服务器 orentec.co.kr 的 IP 地址。
9. 默认的 DNS 服务器将 IP 地址返回给浏览器。
10. 浏览器使用获取到的 IP 地址向 orentec.co.kr 的服务器发起 HTTP 请求。
11. 服务器收到请求后，返回网站的主页内容。
12. 浏览器接收到主页内容，解析并渲染显示给用户。

* 权威域名服务器（Authoritative Name Server）：
  * 权威域名服务器是负责存储和提供特定域名的 DNS 记录信息的服务器。
  * 当需要查询某个域名的 IP 地址或其他 DNS 记录时，如果本地 DNS 服务器没有缓存或者没有该域名的信息，它将向权威域名服务器发送查询请求。
  * 权威域名服务器通常由域名的所有者或管理者维护，并包含有关该域名的所有权威信息，如 A 记录（IPv4 地址）、AAAA 记录（IPv6 地址）、CNAME 记录（别名）、MX 记录（邮件服务器）等。
  * 对于每个域名，至少应该有两个权威域名服务器，以提高可靠性和冗余性。
* 根域名服务器（Root Name Server）：
  * 根域名服务器是DNS层次结构中的顶层服务器，负责管理顶级域名服务器的信息。
  * 它们存储了顶级域名（如 .com、.org、.net 等）的 DNS 服务器的地址信息，而不是特定域名的 IP 地址。
  * 当本地 DNS 服务器无法解析特定域名时，它会向根域名服务器发送查询请求。
  * 根域名服务器不存储特定域名的 IP 地址信息，它们只返回顶级域名服务器的地址信息，以便本地 DNS 服务器继续向下查询。

```shell
# www.naver.com（某个域名）对应的IP地址信息 139页
ping www.naver.com
```

```shell
# 自己计算机中注册的默认DNS服务器地址
nslookup
server
```

```c
#include <netdb.h>
/**
 * 传递字符串格式的域名获取IP地址 141页
 * @return 成功返回 hostent结构体地址，失败返回 NULL指针
 */
struct hostent * gethostbyname(const char * hostname);
```

```c
#include <netdb.h>
/**
 * 利用IP地址获取域相关信息
 * @param addr 含有IP地址信息的in_addr结构体指针。为了同时传递IPv4地址之外的其他信息，该变量的类型声明为char指针
 * @param len 向第一个参数传递的地址信息的字节数，IPv4时为4，IPv6时为6
 * @param family 传递地址族信息，IPv4时为AF_INET，IPv6时为AF_INET6
 * @return 成功返回 hostent结构体变量地址值，失败返回 NULL指针
 */
struct hostent * gethostbyaddr(const char * addr, socklen_t len, int family);
```