#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;

const int mod=999983;
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
inline int mul(int a,int b) {
  return (int)((long long)a*b%mod);
}
vector<int> mul(const vector<int> &p,int j){
    ///c[0]+(c[1]*x)+(c[2]*(x^2)+...)c[n-1]*(x^(n-1))
    ///(x-j)
    int n=(int)p.size();
    vector<int> s(n+1,0);
    for(int i=0;i<n;i++){
        plusle(s[i+1],p[i]);
    }
    for(int i=0;i<n;i++){
        plusle(s[i],mul(p[i],j));
    }
    return s;
}
int x[maxn];
vector<int> ans;

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k,l;cin>>n>>k>>l;
        set<int> s;int xx=0;
        rep(i,1,l){cin>>xx;s.insert(xx);}
        int i=1;
        for(auto t:s)x[i++]=t;
        ans.clear();
        ans.push_back(1);
        rep(i,1,l)ans=mul(ans,-x[i]);
        if(ans.size()-1>k)cout<<0<<endl;
        else{
            cout<<n<<endl;
            rep(j,1,n){
                cout<<ans.size();
                for(int i=ans.size()-1;i>=0;i--){
                    cout<<' '<<j*ans[i]%mod;
                }
                //debug(k),debug(ans.size());
                rep(i,1,k-ans.size()+1)cout<<' '<<0;
                cout<<endl;  
            }
              
        }
        
    }
}
/* 
L 给出多项式的l个0点，要输出n个最高次为k的多项式。 如果少于n个就有几个输出几个 %999983
1
2 4 3
0 0 0
1
1 4 4
1 2 3 5
3
1 5 4
1 2 3 5
1 3 4
1 2 3 5
1 4 3
3 7 42
 */