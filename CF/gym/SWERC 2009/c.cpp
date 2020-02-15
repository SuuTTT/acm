#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)2005;
typedef pair<int,int> pii;
#define x first
#define y second
map<pii,int> mp;
pii pt[maxn];
vector<int> X,Y;
int idx(int x){
    return lower_bound(X.begin(),X.end(),x)-X.begin()+1;
}
int idy(int x){
    return lower_bound(Y.begin(),Y.end(),x)-Y.begin()+1;
}
int a[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int d;
    cin>>d;
    int n,s;
    
    rep(D,1,d){
        cin>>n>>s;
        int ans=-2e9;
        rep(i,1,n){
            int f,t;
            cin>>f>>t;
            if(t<=s)ans=max(ans,f);
            else ans=max(ans,f-(t-s));
        }
        cout<<"Case #"<<D<<": "<<ans<<endl;
    }
}
/* 
2
2 5
3 3
4 5

1 5
1 7
 */