#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)5e2+5;
typedef long long ll;
const long long inf=(ll)1e18;
string mp[4];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rep(i,1,3){
        cin>>mp[i];
    }
    rep(i,1,3)rep(j,0,9){
        if(mp[i][j]=='='){
            j++;
            while(j<10&&mp[i][j]=='.')j++;
            if(j==10)cout<<"You shall pass!!!"<<endl;
            else cout<<mp[i][j]<<endl;
            break;
        }
    }
   
}
/*
..........
=.........
..........
*/