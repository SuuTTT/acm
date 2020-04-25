#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll n,k,M,C,t,d;
ll lc,pc,lm,pm;
ll a[maxn];
ll numCar[maxn],numMotor[maxn];
ll needCar[maxn],needMotor[maxn];
ll usableCar[maxn],usableMotor[maxn],usablePassenger[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>k;
    
    cin>>lc>>pc>>lm>>pm;cin>>t>>d;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    rep(i,1,n){
        if(a[i]>=lc-d)numCar[i]=1;
        if(a[i]>=lm-d)numMotor[i]=1;
        if(a[i]<lc&&a[i]>=lc-d)needCar[i]=lc-a[i];
        if(a[i]<lm&&a[i]>=lm-d)needMotor[i]=lm-a[i];
        if(a[i]>lc)usableCar[i]=min(a[i]-lc,d);
        if(a[i]>lm)usableMotor[i]=min(a[i]-lm,d);
        if(a[i]>1)usablePassenger[i]=min(a[i]-1,d);
        numCar[i]+=numCar[i-1];
        numMotor[i]+=numMotor[i-1];
        needCar[i]+=needCar[i-1];
        needMotor[i]+=needMotor[i-1];
        usableCar[i]+=usableCar[i-1];
        usableMotor[i]+=usableMotor[i-1];
        usablePassenger[i]+=usablePassenger[i-1];
    }
    ll ans=1e18;
    rep(i,0,n){
        if(numCar[i]<i)break;
        ll l=i+1,r=n-i*(k-1);
        if(l>r){//第一次全乘车 要特判
            ll needs=needCar[i];
            ll usable=usableCar[i]+usablePassenger[n]-usablePassenger[i];//i not r
            if(needs<=usable)
                ans=min(ans,i*pc+needs*t);
            break;
        }
        if(l<=r&&numMotor[r]-numMotor[l-1]<r-l+1)continue;//
        ll needs=needCar[i]+needMotor[r]-needMotor[l-1];
        ll usable=usableCar[i]+usableMotor[r]-usableMotor[l-1]+usablePassenger[n]-usablePassenger[r];
        //debug(i),debug(needs),debug(usable);
        if(needs>usable)continue;
        ans=min(ans,i*pc+(r-l+1)*pm+needs*t);
    }
    cout<<(ans==1e18?-1:ans)<<endl;
    
}
/* 
2 2
18 1000 16 1
5 3
16 15

k个人 选择坐车或摩托车。
开车的人至少lc岁，载k-1人，花费pc
开摩托车的人至少lm岁，载1人,花费pm

可以转换年龄,一单位花费t，最多转换d，不能小于1

求全部有车座的最小花费
 (1≤lm<lc≤105, 1≤pm<pc≤105) 
 ana 
 1.摩托车的数量M确定后，汽车的数量C也可以确定，枚举M。
 2.lm<lc，贪心地让最老的C个开车，次老M个的开摩托车。
 3.四个分界线，
 lc+d,lc,lc-d,
 lm+d,lm,lm-d,
 d+1

 wr
 题意看错，摩托车不能载人!
 ll lcc,lcpd,lcmd,lmm,lmpd,lmmd,dd;//太鬼畜了
const ll inf=(ll)1e18;
ll check(ll c,ll m){
    ll req=0,cur=0;
    if(c+m>n)return inf;
    //需要转化多少
    if(c>lcmd)return inf;
    if(m>lmmd)return inf;
    if(c>lcc)req+=lc*(c-lc)-(s[c]-s[lcc]);
    if(m>lmm)req+=lm*(m-lm)-(s[m]-s[lmm]);
    //可以转化多少
    if(c>lcpd)cur+=d*(lcpd);
    if(c>lcc)cur+=(s[lcc]-s[lcpd])-lc*(lcc-lcpd);
    if(m>lmpd)cur+=d*(lmpd);
    if(m>lmm)cur+=(s[lmm]-s[lcmd])-lm*(lmm-lcmd);
    if(c+m>d)cur+=s[dd]-s[m+c]-(d-m-c);
    if(cur>=req)return req*t;
    else return inf;
}
 rep(i,1,n)s[i]=s[i-1]+a[i],debug(s[i]);
    rep(i,1,n){
        vector<int> flag(8,0);
        if(!flag[1]&&a[i]<lc+d)lcpd=i+1,flag[1]=1;
        if(!flag[2]&&a[i]<lc-d)lcmd=i-1,flag[2]=1;
        if(!flag[3]&&a[i]<lm+d)lmpd=i+1,flag[3]=1;
        if(!flag[4]&&a[i]<lm-d)lmmd=i-1,flag[4]=1;
        if(!flag[5]&&a[i]<dd+1)dd=i+1,flag[5]=1;
        if(!flag[6]&&a[i]<lc)lcc=i+1,flag[6]=1;
        if(!flag[7]&&a[i]<lm)lmm=i+1,flag[7]=1;
    }
    ll ans=inf;
    rep(M,1,(n+1)/2){
        C=max((ll)ceil((double)(n-2*M)/k),0ll);
        ans=min(ans,check(C,M));
        
    }
    cout<<(ans==inf?-1:ans)<<endl;
 */