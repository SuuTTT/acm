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
    int n;
    cin>>n;
    rep(i,1,n){
        int xx,yy;
        cin>>xx>>yy;
        pt[i]={xx,yy};
        mp[{xx,yy}]=1;
        X.push_back(xx);
        Y.push_back(yy);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    rep(i,1,n){
        a[idx(pt[i].x)][idy(pt[i].y)]++;
        //debug(i),debug(idx(pt[i].x)),debug(idy(pt[i].y));
    }
    rep(i,1,X.size()){
        rep(j,1,Y.size()){
            //debug(i),debug(j),debug(a[i][j]),debug(a[i-1][j]),debug(a[i][j-1]),debug(a[i-1][j-1]);
            a[i][j]+=(a[i][j-1]+a[i-1][j]-a[i-1][j-1]);
            //debug(a[i][j]);
            
        }
        
    }
    int ans=0;
    rep(i,1,n)rep(j,1,n){
        if(pt[i].x==pt[j].x||pt[i].y==pt[j].y)continue;
        if(pt[i].x>pt[j].x||pt[i].y>pt[j].y)continue;
        if(mp.count({pt[i].x,pt[j].y})&&mp.count({pt[j].x,pt[i].y})&&
        a[idx(pt[j].x)][idy(pt[j].y)]+a[idx(pt[i].x)-1][idy(pt[i].y)-1]
        -a[idx(pt[i].x)-1][idy(pt[j].y)]-a[idx(pt[j].x)][idy(pt[i].y)-1]==4)ans++; 
       // debug(i),debug(j),debug(pt[i].y),debug(pt[j].x);
        //debug(mp.count({pt[i].x,pt[j].y})),debug(mp.count({pt[i].y,pt[j].x}));
        //debug(a[idx(pt[j].x)][idy(pt[j].y)]),debug(a[idx(pt[i].x)-1][idy(pt[i].y)-1]),
        //debug(a[idx(pt[i].x)-1][idy(pt[j].y)]),debug(a[idx(pt[j].x)][idy(pt[i].y)-1]);
       /*  debug(a[idx(pt[j].x)][idy(pt[j].y)]+a[idx(pt[i].x)-1][idy(pt[i].y)-1]
        -a[idx(pt[i].x)-1][idy(pt[j].y)]-a[idx(pt[j].x)][idy(pt[i].y)-1]);
        debug(ans); */
        //cout<<endl;
    }
    cout<<ans<<endl;
}
/* 
6
1 1
1 2
2 1
2 2
3 1
3 2
 */