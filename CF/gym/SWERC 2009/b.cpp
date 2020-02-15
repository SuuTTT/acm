#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
typedef long long ll;
inline ll gcd(ll a, ll b) {return b? gcd(b, a%b): a;}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        if(n==0)break;
        string s;int m;
        int p1=0,p2=0;
        rep(i,1,n){
            cin>>s>>m;
            if(s[0]=='D'){
                cout<<"DROP 1 "<<m<<endl;
                p1+=m;
            }
            else{
                int tmp=min(m,p2);
                p2-=tmp;
                if(p2==0){
                    if(tmp)cout<<"TAKE 2 "<<tmp<<endl;
                    if(p1)cout<<"MOVE 1->2 "<<p1<<endl;
                    p2+=p1;
                    p1=0;
                    tmp=m-tmp;
                    if(tmp)cout<<"TAKE 2 "<<tmp<<endl;
                    p2-=tmp;
                }else{
                    if(tmp)cout<<"TAKE 2 "<<tmp<<endl;  
                }
                
            }
        }
        cout<<endl;
    }
   
}
/* 
4
D 10
T 5
D 10
T 15
3
DROP 100
TAKE 50
TAKE 20
3
DROP 3
DROP 5
TAKE 8
0

 */