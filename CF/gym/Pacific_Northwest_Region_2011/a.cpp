#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;getchar();
    rep(i,1,n){
        string s;
        getline(cin,s);
        //debug(s);
        int b=0,g=0;
        for(auto c:s){
            if(c=='b'||c=='B')b++;
            if(c=='g'||c=='G')g++;
        }
        if(b==g){
            cout<<s<<" is NEUTRAL"<<endl;
        }else if(b>g){
            cout<<s<<" is A BADDY"<<endl;
        }else cout<<s<<" is GOOD"<<endl;
    }
}
/* 
8
Algorithm Crunching Man
Green Lantern
Boba Fett
Superman
Batman
Green Goblin
Barney
Spider Pig

 */