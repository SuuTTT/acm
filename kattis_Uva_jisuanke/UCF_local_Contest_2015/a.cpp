#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int z=0,m=0;
        rep(i,1,10){
            int x;
            cin>>x;
            cout<<x;
            cout<<(i==10?'\n':' ');
            if(x==17)z=1;
            if(x==18)m=1;
        }
        if(z&&m){cout<<"both\n"<<endl;continue;}
       if(z){cout<<"zack\n"<<endl;continue;} 
       if(m){cout<<"mack\n"<<endl;continue;} 
       {cout<<"none\n"<<endl;continue;} 
    }
}
/* 
4 
11 99 88 17 19 20 12 13 33 44 
11 12 13 14 15 16 66 88 19 20 
20 18 55 66 77 88 17 33 44 11 
12 23 34 45 56 67 78 89 91 18 
 */