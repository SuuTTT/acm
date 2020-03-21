#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

struct Point{
    ll x,y;
    Point(){}
    Point(ll x,ll y):x(x),y(y){}
    bool operator < (const Point &b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
};

const ll M=1e17;
Point P[100005],A,B;
ll n;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        rep(i,1,n)cin>>P[i].x>>P[i].y;
        sort(P+1,P+1+n);
        if(n&1){
            A=P[n/2+1];
            B=Point(P[n/2+1].x-1,M);
        }else{
            A=Point(P[n/2].x-1,P[n/2].y+M);
            B=Point(P[n/2].x+1,P[n/2].y-M+1);
        }
        cout<<A.x<<" "<<A.y<<endl;
        cout<<B.x<<" "<<B.y<<endl;
    }
    return 0;
}
/*

*///
