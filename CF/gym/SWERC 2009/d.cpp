#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int vis[201];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int p1=0,p2=0;
    while(p1<s1.size()&&p2<s2.size()){
        if(s1[p1]==s2[p2])p1++,p2++;
        else p1++;
    }
    cout<<(p2==s2.size()?"YES":"NO");
}
/* 
threeyellowfurryfiends
hellofriend
 */