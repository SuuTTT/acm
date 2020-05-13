#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
char mp[11][maxn];
int c[11],re,cnt;
int h,w,k;
bool f(int j,int z){
    int id=0;
    rep(i,0,h-1){
        c[id]+=mp[i][j]=='1';
        if(c[id]>k)return 0;
        if((z>>i)&1)id++;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>h>>w>>k;
    rep(i,0,h-1)cin>>mp[i];
    int ans=10000;
    for(int i=0;i<(1<<h)-1;i++){
        fill(c,c+h,0);re=1;
        cnt=__builtin_popcount(i);
        rep(j,0,w-1){
            if(!f(j,i)){
                fill(c,c+h,0);
                re=f(j,i);
                cnt++;
            }
            
        }
        if(re)ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}
/* 
3 5 4
11100
10001
00111

 */