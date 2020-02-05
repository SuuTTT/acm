# 知识点 - python



## 解决问题类型：

自带高精度、快速幂、gcd、Karatsuba快速乘

注意python的除法，\ 是浮点数的除，会自动将int转化为float然后丢失精度。



## 复杂度：

Karatsuba快速乘:$O(3n^{1.585})$

https://nbviewer.jupyter.org/github/lijin-THU/notes-python/tree/master/

## 例题

[E. Resistors in Parallel,2018-2019 ACM-ICPC, Asia Jiaozuo Regional Contest ](https://codeforces.com/gym/102028/problem/E)



n个电阻，编号为i的电阻阻值为 i ，但如果i可以被大于4的平方数整除，这个电阻的阻值就是$\infty$。

你现在可以选择一个$x<=n$ ，将所有编号为 $x$ 的因数的电阻并联起来。问能得到的等价电阻最小为多少？输出它的分数形式。

##### 解：

根据样例手模出来选的$x$ 就是前几个质数的乘积。

比如$n=1000$时：选$x=2*3*5*7$ 电阻为:
$$
\frac{2\ *\ 3\ *\ 5\ *\ 7}{1\ +\ 2\ +\ 3\ +\ 5\ +7+\ 2\ *\ 3\ \ +\ 2\ *\ 5+\ 2\ *\ 7\ +\ 3\ *\ 5\ +3\ *\ 7\ +\ 5\ *\ 7+2\ *\ 3\ *\ 5\ +\ 3\ *\ 5\ *\ 7\ +\ 2\ *\ 5\ *\ 7\ +\ 2\ *\ 3\ *\ 7\ \ +\ 2\ *\ 3\ *\ 5\ *\ 7}
$$
于是我们计算$x$的 等价电阻，为
$$
\frac{\prod_{p|n}p}{\prod_{p|n}(p+1)}
$$


## 代码

```python
import math
#10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
A=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257]
s=1
cnt2=0
B=[]
B.append(0)
for x in A:
    s *= x
    cnt2 = cnt2 + 1
    B.append(int(s))

T = int(input())

for kase in range(T):
    now = int(0)
    n=int(input())
    for i in range(55):
        if(int(B[i+1])>n):
            now=i
            break
    up=int(1)
    down=int(1)

    for i in range(now):
        up*=int(A[i]+1)
        down*=int (A[i])
    d=math.gcd(up,down)
    up=int(up // d)
    down=int(down // d)

    txt=str(down)+'/'+str(up)
    print(txt)

```





## 基础操作

```python
 #一行读入
 A=list(map(int,input().split()))
 #sort
 A=sorted(A)
 #   
#多维数组
a=[] 
for i in range(100): 
a.append([]) 
for j in range(100): 
a[i].append(0) 
```

压行技巧

```python
#if else 
print(s if a >= 3200 else 'red')

#sum 精度
 A = map(int, input().split())
 print('{:.16g}'.format(1 / sum(1 / x for x in A)))

# re 正则表达式 判奇数位不是L，偶数位不是R
1 import re
2
3 s = input()
4 p = re.compile(r'^([^L][^R])*[^L]?$')
5 if p.match(s):
6 print("Yes")
7 else:
8 print("No")

```



## 高级语法

输出格式。

```python
#!/usr/bin/env python 
# -*- coding:utf-8 -*-
__author__ = 'Abel'
"""
   Python中内置的%操作符和.format方式都可用于格式化字符串。先来看看这两种具体格式化方法的基本语法形式和常见用法。
   %操作符根据转换说明符所规定的格式返回一串格式化后的字符串,转换说明符的基本形式为: %[转换标记][宽度[.精确度]]转换类型。
其中常见的转换标记和转换类型分别下所示。如果未指定宽度,则默认输出为字符串本身的宽度。
转换标记       解释
   -        表示左对齐
   +        在正数之前加上+
(a space)   表示正数之前保留空格
   #        在八进制数前面显示零('0'),在十六进制前面显示'0x'或者'0X'
   0        表示转换值若位数不够则用0填充而非默认的空格
   c        转换为单个字符,对于数字将转换该值所对应的ASCⅡ码
   s        转换为字符串,对于非字符串对象,将默认调用str()函数进行转换
   r        用repr()函数进行字符串转换转换
   i d      转换为带符号的十进制数
   u        转换为不带符号的十进制数
   o        转换为不带符号的八进制
   x,X      转换为不带符号的十六进制
   e E      表示为科学计数法表示的浮点数
   f F      转成浮点数(小数部分自然截断)
   g G      如果指数大于-4或者小于精度值则和e相同,其他情况与f相同;
            如果指数大于-4或者小于精度值则和E相同,其他情况与F相同
"""
###  %操作符格式化字符串时有如下几种常见用法:
### (1)直接格式化字符或者数值。
print("score:%06.1f" % 9.5)    # score:0009.5
###（2）以元组的形式格式化
name,num = "Abel",10
print("%s today have %d classes" % (name, num))  #Abel today have 10 classes
dict = {"name":"Abel", "num":10}
print("%(name)s today have %(num)d classes" % dict) #Abel today have 10 classes
#注意上面的是%(name)s和%(num)d，不能漏了s和d。
 
"""
   format方式格式化字符串的基本语法为:[[填充符]对齐方式][符号][#][0][宽度][,][.精确度][转换类型]。
其中填充符可以是除了“{”和“}”符号之外的任意符号,对齐方式和符号分别如下所示。转换类型跟%操作符的转换类型类似。
 format方式格式化字符串的对齐方式：
对齐方式    解释
   <        表示左对齐,是大多数对象为默认的对齐方式
   >        表示右对齐,数值默认的对齐方式
   =        仅对数值类型有效,如果有符号的话,在符号后数值前进行填充,如-000029
   ^        居中对齐,用空格进行填充
format方式格式化字符串符号列表:
符号    解释
 +      正数前加+,负数前加-
 -      正数前不加符号,负数前加-,为数值的默认形式
 空格   正数前加空格,负数前加-
"""
###format方法几种常见的用法如下:
###(1)使用位置符号。
print("The number {0:,} in hex is :{0:#x}, the number {1:,} in oct is {1:#o}".format(6666,8888))
#The number 6,666 in hex is :0x1a0a, the number 8,888 in oct is 0o21270
###(2)使用名称
print("{name} has {num} classes today!".format(name = "Abel", num = 10))  #Abel has 10 classes today!
###(3)通过属性
class Customer(object):
    def __init__(self, name, gender, phone):
        self.name = name
        self.gender = gender
        self.phone = phone
    def __str__(self):
        return "Customer ({self.name},{self.phone})".format(self = self)  #Customer (Abel,698569)
print(str(Customer("Abel","male","698569")))
###(4)格式化元组的具体项
arr = (6,9,8)
print("X1:{0[0]},X2:{0[1]},X3:{0[2]}".format(arr))   #X1:6,X2:9,X3:8
"""
为什么要尽量使用 format方式而不是%操作符来格式化字符串:
理由一:fmat方式在使用上较%操作符更为灵活。使用 format方式时,参数的顺序与格式化的顺序不必完全相同,而用%方法需要使用字典形式才能达到同样的目的。
理由二: format方式可以方便地作为参数传递。
理由三:%最终会被 format方式所代替。这个理由可以认为是最直接的原因,根据Python的官方文档,format方法最终会取代%,
       在Python3.0中format方法是推荐使用的方法,而之所以仍然保留%操作符是为了保持向后兼容。
理由四:%方法在某些特殊情况下使用时需要特别小心。
"""
```



## 进阶模板

扩展CRT

```python
def Ex_Euclid(a,b):
  if 0==b:
    x=1;y=0;q=a
    return x,y,q
  xyq=Ex_Euclid(b,a%b)
  x=xyq[0];y=xyq[1];q=xyq[2]
  temp=x;x=y;y=temp-a//b*y
  return x,y,q


# 获取a的逆元(mod b)的函数，目的是为了封装获取逆元的功能
def inv(a, b):
    return Ex_Euclid(a, b)[0]


# 获取a和b的最大公约数函数，目的是为了封装获取最大公约数的功能
def gcd(a, b):
    return Ex_Euclid(a, b)[2]


A = list(map(int, input().split()))
n=A[0];a=A[1];b=A[2]

ans=0
for i in range (1,n+1,1):
    for j in range(1,i+1,1):
        if(gcd(i,j)==1):
            x=pow(i,a)-pow(j,a);y=pow(i,b)-pow(j,b)
            print(i,j,x,y,gcd(x,y))
            ans+=gcd(x,y)
mod=ans%1000000009
print(ans,mod)

#1000000009
#1000000007

```

dp

```python
L, R = map(int, input().split())
MOD = 10 ** 9 + 7
l = '{:060b}'.format(L)[::-1]
r = '{:060b}'.format(R)[::-1]

memo = [[[[-1 for l in range(2)] for k in range(2)] for j in range(2)] for i in range(60)]

def f(pos, flagX, flagY, flagZ):
    if pos == -1:
        return 1
    if memo[pos][flagX][flagY][flagZ] != -1:
        return memo[pos][flagX][flagY][flagZ]
    ret = 0
    # x 0, y 0
    if flagX or l[pos] == '0':
        ret += f(pos - 1, flagX, 1 if r[pos] == '1' else flagY, flagZ)
    # x 0, y 1
    if (flagX or l[pos] == '0') and (flagY or r[pos] == '1') and flagZ:
        ret += f(pos - 1, flagX, flagY, flagZ)
    # x 1, y 1
    if flagY or r[pos] == '1':
        ret += f(pos - 1, 1 if l[pos] == '0' else flagX, flagY, 1)
    ret %= MOD
    memo[pos][flagX][flagY][flagZ] = ret
    return ret

ans = f(59, 0, 0, 0)
print(ans)

```

