#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
const int MAXN = 2e5+4;
int a[MAXN];
int sa[MAXN];
int Rank[MAXN];
int height[MAXN];
int len;
//char s[MAXN];
int r[MAXN];
int wa[MAXN*3],wb[MAXN*3],wv[MAXN*3]; //这四个数组和str要开3倍
int wws[MAXN*3];
void sort(int *r,int *a,int *b,int n,int m)
{
      int i;
      for(i=0;i<n;i++) wv[i]=r[a[i]];
      for(i=0;i<m;i++) wws[i]=0;
      for(i=0;i<n;i++) wws[wv[i]]++;
      for(i=1;i<m;i++) wws[i]+=wws[i-1];
      for(i=n-1;i>=0;i--) b[--wws[wv[i]]]=a[i];
     return;
}
int c0(int *r,int a,int b)
{return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}
int c12(int k,int *r,int a,int b)
{if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}

void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1;i<tbc;i++)
          rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
          else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
          sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];
    return;
}
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for (i = 0; i <= n; ++i) Rank[sa[i]] = i;
    for (i = 0; i < n; height[Rank[i++]] = k)
        for (k ? k-- : 0, j = sa[Rank[i] - 1]; r[i + k] == r[j + k]; ++k);
    return;
}
void da(int *str,int *sa,int *rk,int *ht,int n,int m){
    //debug(n);cout<<1<<endl;
    rep(i,n,n*3-1)str[i]=0;
    dc3(str,sa,n+1,m);
    calheight(str,sa,n);
}

int stTable[maxn][32],stTable2[maxn][32];
int preLog2[maxn];


int rmq(int l,int r){
    if(l>r)swap(l,r);l++;
    int len=r-l+1,k=preLog2[len];
    return min(stTable[l][k],stTable[r-(1<<k)+1][k]);
}


void rmq_init(int n,int *array){
    preLog2[1]=0;
    rep(i,2,n){
        preLog2[i]=preLog2[i-1];
        if((1<<preLog2[i]+1)==i){
            ++preLog2[i];
        }
    }
    for(int i=n-1;i>=0;i--){
        stTable[i][0]=array[i];
        for(int j=1;(i+(1<<j)-1)<n;++j){
            stTable[i][j]=min(stTable[i][j-1],
            stTable[i+(1<<j-1)][j-1]);
        }
    }
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;int kase=1;
    while(cin>>s){
        
        int len=s.size();
        
        if(s[0]=='#')break;
        for(int i=0;i<len;i++)a[i]=s[i]-'a'+1;
        
        a[len]=0;
        da(a,sa,Rank,height,len,28);
        
        rmq_init(len,height);
        
         //for(int i=0;i<=len;i++)debug(height[i]);rep(i,0,len)debug(Rank[i]);rep(i,0,len)debug(sa[i]);
        int ans=0,anspos=-1,anslen=0;//ans repetation number
        rep(i,1,len/2)for(int j=0;j+i<len;j+=i){
            if(a[j]!=a[j+i])continue;
            
            int tmp = rmq(Rank[j],Rank[j+i]);
            //debug(i),debug(j),debug(tmp),debug(Rank[j]),debug(Rank[j+i]);
            int k=j-1,p = j;//k pointer, p anspos of current loop
            while(k>=0&&k+i>j and a[k]==a[k+i]){
                tmp++; //debug(tmp);
                if(tmp%i==0){// ans++
                    p=k;
                }else if(Rank[k]<Rank[p])p=k; //lex less
                k--;
            }
            if(tmp/i+1>ans or (tmp/i+1==ans and Rank[p]<Rank[anspos]))ans=tmp/i+1,anspos=p,anslen=i*ans;
        }
        cout<<"Case "<<kase++<<": ";
        if(ans<2){
            cout<<*min_element(s.begin(),s.end())<<endl;
            continue;
        }
        cout<<s.substr(anspos,anslen)<<endl;
    }
}
/* 
baccdbaccdbacbdbacbd
xbcabcab

abaab
sa=23041 523041
rk=35124 351240
ht=      001201
aabaaaab
sa=45617283
rk=
输出重复次数最多的重复串, 字典序最小
 */