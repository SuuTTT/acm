#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string s[105];
int pos[105][256];
int tmp[256];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        if(n==0)break;
        rep(i,1,n){
            cin>>s[i];
            int j=0;
            for(auto c:s[i])pos[i][c]=j++;
        }
        string ans="ABCDE";
        string mns;
        int mn=1e9;
        do{
            int i=0;
            for(auto c:ans)
                tmp[c]=i++;
            int dis=0;
            rep(i,1,n){
                rep(c1,'A','E')rep(c2,c1+1,'E'){
                    if((pos[i][c1]<pos[i][c2])!=(tmp[c1]<tmp[c2]))dis++;
                }
            }
            if(dis<mn){mn=dis,mns=ans;}
        }while(next_permutation(ans.begin(),ans.end()));
        cout<<mns<<" is the median ranking with value "<<mn<<'.'<<endl;
    }
    
}
/* 
5!=120 *100 *5 * 5
4
ABDCE
BACDE
ABCED
ACBDE
0
 */