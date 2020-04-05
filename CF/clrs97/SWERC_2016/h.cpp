#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

ll D,H;
bool operator < (const vector<ll> &a,const vector<ll> &b){
    rep(i,0,D-1)if(a[i]!=b[i])return a[i]<b[i];
    return false;
}
map<vector<ll>,ll> mp;
ll C(vector<ll> a){
    if(mp.find(a)!=mp.end())return mp[a];
    ll zero=0,ans=0;
    rep(i,0,D-1)if(a[i]==0)zero++;
    if(zero==D)ans=1;
    else{
        rep(i,0,D-1){
            if(a[i]>0){
                a[i]--;
                ans+=C(a);
                a[i]++;
            }
        }
    }
    mp[a]=ans;
    return ans;
}
vector<ll> x;
set<ll> se;
void dfs(ll p,ll sum){
    if(p==D-1){
        x[p]=H-sum;
        se.insert(C(x));
    }else{
        rep(i,0,min(x[p-1],H-sum)){
            if(sum+i+(H-p)*i<H)continue;
            x[p]=i;
            dfs(p+1,sum+i);
            x[p]=0;
        }
    }
}

int main(){
#ifdef ATPLAB
//freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>D>>H){
        x.resize(D);
        H--;
        mp.clear();
        se.clear();
        rep(i,0,H){
            x[0]=i;
            dfs(1,i);
            x[0]=0;
        }
        for(auto it:se)cout<<it<<endl;
    }
    return 0;
}
