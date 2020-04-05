#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int a[maxn];
priority_queue<int>Q;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        rep(i,1,n){
            cin>>a[i];
            Q.push(-a[i]);
        }
        //sort(a+1,a+1+n);
        int ans=0;
        while(!Q.empty()){
            if(Q.size()==1){Q.pop();}
            else{
                int x1=Q.top();Q.pop();
                int x2=Q.top();Q.pop();
                ans+=x1+x2;
                Q.push(x1+x2);
            }
        }
        cout<<-ans<<endl;
    }
}
/* 
4
6
2 3 4 4 5 7
5
5 15 40 30 10
10
3 1 5 4 8 2 6 1 1 2
9
3 2 1 6 5 2 6 4 3
 */