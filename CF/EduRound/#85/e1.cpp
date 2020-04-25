#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
ll n,l,r;
vector<ll> ans;
bool inter(ll l1,ll r1,ll l2, ll r2){
    //l1 r1 l2 r2
    // l1 l2 r1 r2
    return max(l1,l2)<=min(r1,r2);
}
void cal(ll front,ll &id){
   // debug(id);
    if(front==n+1)return;
   // debug(front);
    if(inter(l,r,id,id+2*(n-front)))
        rep(i,front+1,n){
            if(id>=l&&id<=r)ans.push_back(front);
            id++;
            if(id>=l&&id<=r)ans.push_back(i);
            id++;
        }
    else id+=2*(n-front);
    cal(front+1,id);
    if(front==1){
        if(id>=l&&id<=r)ans.push_back(front);
    }
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;cin>>t;
    while(t--){
        ans.clear();
        cin>>n>>l>>r;
        ll idx=1;
        cal(1,idx);
       // debug(ans.size());
        for(auto t:ans)cout<<t<<' ';
        cout<<endl;
    }
}
/* 
wr 左开右闭和左闭右闭
2
5 1 20
5 1 1

3
25 30 30
25 30 31
25 30 32

1
5 1 1



3
2 1 3
3 3 6
99995 9998900031 9998900031

递归
 */