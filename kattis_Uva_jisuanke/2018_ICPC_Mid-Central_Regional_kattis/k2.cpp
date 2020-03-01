#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define LL long long
#define pill pair<int,int>
const int N = 1e5+4;

int x[N];
int wa[N],wb[N],wv[N],Ws[N];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

/* str,sa,len+1,max(ASCII)+1 */
void da(int r[],int sa[],int n,int m){
      int i,j,p,*x=wa,*y=wb,*t;
      for(i=0; i<m; i++) Ws[i]=0;
      for(i=0; i<n; i++) Ws[x[i]=r[i]]++;//以字符的ascii码为下标
      for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
      for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
      for(j=1,p=1; p<n; j*=2,m=p){
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) Ws[i]=0;
            for(i=0; i<n; i++) Ws[wv[i]]++;
            for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
            for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                  x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
      }
}

int sa[N],Rank[N],height[N];
//求height数组
/**< str,sa,len */
void calheight(int *r,int *sa,int n){
      int i,j,k=0;
      for(i=1; i<=n; i++) Rank[sa[i]]=i;
      for(i=0; i<n; height[Rank[i++]]=k)
            for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
      for(int i=n;i>=1;--i) ++sa[i],Rank[i]=Rank[i-1];
}

int str[N];
int n,k;
bool check(int len){
    for(int i=2,co=1;i<=n;i++){
        if(height[i]>=len){
            co++;
        }
        else{
            co=1;
        }
        if(co>=k){
            return true;
        }
    }
    return false;
}
vector<int> ans;
int getPos(int len){
    int res=-1;
    int tmpres=-1;
    for(int i=2,co=1;i<=n;i++){
        if(height[i]>=len){
            co++;
            tmpres=max(tmpres,max(sa[i],sa[i-1]));
            if(co>=k)
                ans.push_back(tmpres);
        }
        else{
            co=1;
            tmpres=-1;
        }
    }
    return res;
}


char tmp[N],s[N];
int main(){
    k=2;
    scanf("%s",tmp);
    n=strlen(tmp);
   
    int len=n;

    
    int ma=-1;
    for(int i=0;i<n;i++){
        str[i]=tmp[i];
        ma=max(ma,str[i]);
    }
    str[n]=0;
    da(str,sa,n+1,ma+1);
    calheight(str,sa,n);
    int l=0,r=n+1;
    while(r-l>1){
        int mid=l+r>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    getPos(l);
     int mn=ans[0]-1;
    for(auto t:ans){
        t--;
        int flag=0;
        int p1=mn,p2=t;
        while(p2<len&&p1<len&&tmp[p1]==tmp[p2])p1++,p2++;
        if(p2==len)continue;
        if(tmp[p2]<tmp[p1])mn=t;
    }
    rep(i,mn,mn+l-1)cout<<tmp[i];
    cout<<endl;
   
    
}
/* 
acacababa
ababacaca
bbcaadbbeaa

abcefgabc

abcbabcba

abcdabab

bbcaadbbeaaee

aabbccddeef

aabbaac

bbcaabbdaacccaad
 */