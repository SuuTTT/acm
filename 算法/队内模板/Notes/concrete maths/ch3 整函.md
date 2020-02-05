# ch3 整函

## 1.上下取整

- 符号，图像和性质

![1567514838165](C:\Users\acm-14\AppData\Roaming\Typora\typora-user-images\1567514838165.png)

- 性质公式(P68 3.3~3.6)

$$
\lfloor -x\rfloor=-\lceil x\rceil,\lceil -x\rceil=-\lfloor x\rfloor\\
\lfloor x\rfloor=n \leftrightarrow x-1\lt n \le x\\
\lfloor x+n\rfloor=\lfloor x\rfloor +n\\
\lfloor nx\rfloor!=n\lfloor x\rfloor\\
\lfloor x+y\rfloor=\lfloor x\rfloor+\lfloor y\rfloor+\lfloor \{x\}+\{y\}\rfloor\\
\lceil\lfloor x\rfloor\rceil=\lfloor x\rfloor
$$



## 

## 2.应用

1. n的二进制位数m
   $$
   \because 2^{m-1}\le n \lt 2^m\\
\therefore m=\lfloor \lg n\rfloor+1
   $$

2. 证明
   $$
\lfloor\sqrt{\lfloor x\rfloor}\rfloor=\lfloor \sqrt x\rfloor
   $$

3. 推广：若f是单调连续函数且：
   $$
   \ f(x)=integer \rightarrow\ x=integer\\
   then\ \lfloor f({\lfloor x\rfloor)}\rfloor=\lfloor f(x)\rfloor\\
e.g.\lfloor \frac{x+m}{n}\rfloor=\lfloor \frac{\lfloor x\rfloor+m}{n}\rfloor
   $$

4. 插叙数学问题的五个层次从

5. 左闭右开的区间比全闭或全开好处理
   $$
\#integers\  in\ [a,b)=\lceil b\rceil-\lceil a\rceil
   $$

6. 计算有几个n<N：
   $$
n| \lfloor n^{1/3}\rfloor
   $$

7. 谱spectrum
   $$
   Spec(a) =\{\lfloor a\rfloor,\lfloor 2a\rfloor,\lfloor 3a\rfloor ,...\}
   $$
   
   
   求小于n的谱的大小

   ## 3.取整递归

   1. 习题25

$$
 K_0=1\\
  k_{n+1}=1+min(2K_{\lfloor n/2\rfloor},3K_{\lfloor n/3\rfloor})
 
$$



   2. 习题34 快排
$$
      f(1)=0\\
      f(n)=f(\lfloor n/2\rfloor)+f(\lceil n/2\rceil)+n-1
$$

   3. 扩展约瑟夫

   

## 4.mod

分配律：c(x mod y) = (cx) mod (cy)，可以用来解释负模数

排版应用，递归的正确性以及整除分块？P98

## 5.取整求和

8. 
   $$
   \sum_{0\le k\lt n}\lfloor \sqrt{k}\rfloor
   $$

9. 若a是无理数，则{ka\}是均匀分布在0,1之间的
   $$
   \sum_{0\le k\lt n}[ \{ka\}<v]
   $$

10. $$
      \sum_{0\le k\lt n}\lfloor {\frac{nk+x}{m}}\rfloor
   $$

   













