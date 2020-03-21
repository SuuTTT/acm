#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll cnt[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;ll p;
    cin>>n>>p;
    string s;cin>>s;int len=s.size();
    ll ans=0;
    if(p==2||p==5){
        rep(i,0,len-1)if((s[i]-'0')%p==0)ans+=i+1;
    }else{
        ll cur=0;
        cnt[0]=1;
        ll bit=1;
        rep(i,1,len){//bug 123 算成321
            int j=len-i;           
            cur+=(s[j]-'0')*bit;
            cur%=p;
            bit=bit*10%p;
            ans+=cnt[cur];
            cnt[cur]++;
        }
    }
    cout<<ans<<endl;
}
/* 
lesson：
样例要找不对称的。
“同余公式”的形式 可以通过查找来计算N^2的对数
 */