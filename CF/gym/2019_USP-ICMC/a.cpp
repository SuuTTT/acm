#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int val[maxn];
#define pii pair<int,int>
#define idx first
#define val second
pii a[maxn];
int nxt[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        cin>>a[i].val;
        a[i].idx=i;
        nxt[i]=n+1;
    }
    stack<pii> s;
    rep(i,1,n){
        
        while(!s.empty()&&s.top().val<a[i].val){
            pii tmp=s.top();
            s.pop();
            nxt[tmp.idx]=a[i].idx;
        }
        s.push(a[i]);
    }
    rep(i,1,n){
        cout<<min(a[i].val,nxt[i]-i-1)<<' ';
    }
}
/* 
6
5 2 2 3 6 2
 */