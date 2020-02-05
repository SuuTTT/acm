# 知识点 - 线性丢番图方程   Linear Diophantine Equations



## 解决问题类型：

对于不定方程(a,b,c是给定参数，x,y为系数)
$$
ax + by = c
$$

1. ###### 找到一个解

2. ###### 找到所有解

3. ###### 找到给定区间内的解的个数和解集

4. ###### 找到x+y最小的解



## 推导、代码及复杂度

###### 	0. a = b = 0特判；a=0 or b=0 也特判

1. ###### 找到一个解

   $O(logn)$

   对ab使用扩展gcd得到$g ,x_g, y_g$
   $$
   a x_g + b y_g =g
   $$
   如果$g|c$,则有解。两边乘$\frac{c}{g}$
   $$
   a \cdot x_g \cdot \frac{c}{g} + b \cdot y_g \cdot \frac{c}{g} = c\\
   $$
   得到一组特解
   $$ {cases}
   x_0 = x_g \cdot \frac{c}{g}\\
   y_0 = y_g \cdot \frac{c}{g}.
   $$ {cases}

   ```cpp
   int gcd(int a, int b, int &x, int &y) {
       if (a == 0) {
           x = 0; y = 1;
           return b;
       }
       int x1, y1;
       int d = gcd(b%a, a, x1, y1);
       x = y1 - (b / a) * x1;
       y = x1;
       return d;
   }
   
   bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
       g = gcd(abs(a), abs(b), x0, y0);
       if (c % g) {
           return false;
       }
   
       x0 *= c / g;
       y0 *= c / g;
       if (a < 0) x0 = -x0;
       if (b < 0) y0 = -y0;
       return true;
   }
   ```

   

2. ###### 找到所有解

   我们将一组特解带回方程
   $$
   a \cdot x_0 + b \cdot y_0 = c
   $$
     $x_0+=b / g$ 的同时  $y_0-=a / g$ ，方程右边不变
   $$
   a \cdot \left(x_0 + \frac{b}{g}\right) + b \cdot \left(y_0 - \frac{a}{g}\right) = a \cdot x_0 + b \cdot y_0 + a \cdot \frac{b}{g} - b \cdot \frac{a}{g} = c
   $$
   于是得到所有情况的解集
   $$
   x = x_0 + k \cdot \frac{b}{g}\\
   y = y_0 - k \cdot \frac{a}{g}
   $$
   

3. ###### 找到解的个数和在给定区间的解

   现在$xy$有限制： $[min_x; max_x]$ $[min_y; max_y]$。

   首先$O(1)$地找到最小的$x$使得$x \ge min_x$ ，以及最大的$x$使得$x \le max_x$，记为$l_{x1}，r_{x1}$。

   然后类似地找到最小的$y$使得$y \ge min_y$ ，以及最大的$y$使得$y \le max_y$,并找到对应的x值记为$l_{x2}，r_{x2}。$

   最后对区间 $[l_{x1}, r_{x1}]$ 和 $[l_{x2}, r_{x2}]$求交集得到 $[l_x, r_x]$。

   模板中用 $\frac{a}{g} x + \frac{b}{g} y = \frac{c}{g}$来使$\gcd(\frac{a}{g}, \frac{b}{g}) = 1$以简化计算。

   ```cpp linear_diophantine_all
   void shift_solution(int & x, int & y, int a, int b, int cnt) {
       x += cnt * b;
       y -= cnt * a;
   }
   
   int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
       int x, y, g;
       if (!find_any_solution(a, b, c, x, y, g))
           return 0;
       a /= g;
       b /= g;
   
       int sign_a = a > 0 ? +1 : -1;
       int sign_b = b > 0 ? +1 : -1;
   
       shift_solution(x, y, a, b, (minx - x) / b);
       if (x < minx)
           shift_solution(x, y, a, b, sign_b);
       if (x > maxx)
           return 0;
       int lx1 = x;
   
       shift_solution(x, y, a, b, (maxx - x) / b);
       if (x > maxx)
           shift_solution(x, y, a, b, -sign_b);
       int rx1 = x;
   
       shift_solution(x, y, a, b, -(miny - y) / a);
       if (y < miny)
           shift_solution(x, y, a, b, -sign_a);
       if (y > maxy)
           return 0;
       int lx2 = x;
   
       shift_solution(x, y, a, b, -(maxy - y) / a);
       if (y > maxy)
           shift_solution(x, y, a, b, sign_a);
       int rx2 = x;
   
       if (lx2 > rx2)
           swap(lx2, rx2);
       int lx = max(lx1, lx2);
       int rx = min(rx1, rx2);
   
       if (lx > rx)
           return 0;
       return (rx - lx) / abs(b) + 1;
   }
   ```

    

4. ###### 找到x+y最小的解

   将通解带入$x+y$
   $$
   x' + y' = x + y + k \cdot \left(\frac{b}{g} - \frac{a}{g}\right) = x + y + k \cdot \frac{b-a}{g}
   $$
   If $a < b$, 找最小的 $k$. If $a > b$, 找最大的$k$. If $a = b$,  $x + y$为定值.



## 例题

[LightOj - Solutions to an equation](http://www.lightoj.com/volume_showproblem.php?problem=1306)

 find the number of solutions of the following equation: Ax + By + C = 0 where x1 ≤ x ≤ x2 and y1 ≤ y ≤ y2.

习题

- [Spoj - Crucial Equation](http://www.spoj.com/problems/CEQU/)

- [SGU 106](http://codeforces.com/problemsets/acmsguru/problem/99999/106)

- [Codeforces - Ebony and Ivory](http://codeforces.com/contest/633/problem/A)

- [Codechef - Get AC in one go](https://www.codechef.com/problems/COPR16G)

  

## 代码

```cpp
//https://blog.csdn.net/yjf3151731373/article/details/70048595?locationNum=1&fps=1
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1, y=0;
        return a;
    }
    LL ans=exgcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-a/b*y;
    return ans;
}
LL F(LL x)
{
    if(x==0) return 0;
    if(x>0) return 1;
    else return -1;
}
int main()
{
    int t, ncase=1;
    scanf("%d", &t);
    while(t--)
    {
        LL a, b, c, ax1,ax2, ay1, ay2;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &ax1, &ax2, &ay1, &ay2);
        printf("Case %d: ",ncase++);
        if(a==0&&b==0)
        {
            if(c==0) printf("%lld\n",(ay2-ay1+1)*(ax2-ax1+1));
            else printf("0\n");
            continue;
        }
        else if(a==0)
        {
            if(c%b!=0) printf("0\n");
            else
            {
                LL z=-c/b;
                if(z>=ay1&&z<=ay2) printf("%lld\n",(ax2-ax1+1));
                else printf("0\n");
            }
            continue;
        }
        else if(b==0)
        {
            LL z=-c/a;
            if(c%a!=0) printf("0\n");
            else if(z>=ax1&&z<=ax2) printf("%lld\n",(ay2-ay1+1));
            else printf("0\n");
            continue;
        }
        LL x, y;
        LL g=exgcd(a,b,x,y);
        if(c%g!=0) printf("0\n");
        else//加和减没有区别因为都可以改变k的值得到，注意处理不等式乘以负数的符号变换，公式中的b为b/gcd(a,b)因为这样可以扩大k值
        {
            LL k1, k2, k3, k4;
            if(b*g<0) swap(ax1,ax2);
            k1=(ax1*g+c*x)/b;
            if((ax1*g+c*x)% b!=0 && F(ax1*g+c*x)*F(b) > 0) k1+=1;
            k2=(ax2*g+c*x)/b;
            if((ax2*g+c*x)% (b)!=0 && F(ax2*g+c*x)*F(b) < 0) k2-=1;
            if(-a*g<0) swap(ay1,ay2);
            k3=(ay1*g+c*y)/(-a);
            if((ay1*g+c*y)%(-a)!=0 && F(ay1*g+c*y)*F(-a)>0) k3+=1;
            k4=(ay2*g+c*y)/(-a);
            if((ay2*g+c*y)%(-a)!=0 && F(ay2*g+c*y)*F(-a)<0) k4-=1;
            if(k3>k2||k4<k1) printf("0\n");
            else printf("%lld\n",mint(k2,k4)-maxt(k1,k3)+1);
        }
    }
    return 0;


```

