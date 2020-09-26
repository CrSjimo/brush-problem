# ST表用来解决什么问题

ST表是用于解决满足结合律的可重复贡献问题的数据结构。

可重复贡献问题是指对于运算$\operatorname{opt}$，满足$x \operatorname{opt} x=x$，则对应的区间询问就是一个可重复贡献问题。

例如，$\max(x,x)=x$，$\operatorname{gcd}(x,x)=x$ ，所以RMQ和区间GCD都是可重复贡献问题。

# ST表的思想

倍增。以区间最大值为例，用$ST_{i,j}$表示左端点为$i$，长度为$2^j$的区间的最大值。初始化时有如下递推关系：

$$
ST_{i,j+1}=\max(ST_{i,j},ST_{i+2^j,j})
$$

对于区间$[l,r]$的最大值，设区间长度的对数$L=2^{\lfloor\log_{2}r-l+1\rfloor}$，则可以用以$l$为左端点长度为$2^L$和以$r$为右端点长度为$2^L$的区间覆盖。则有：

$$
\operatorname{query}(l,r)=\max(ST_{l,L},ST_{r-2^L+1,L})
$$

