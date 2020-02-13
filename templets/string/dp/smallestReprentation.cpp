#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* 
https://vjudge.net/problem/SPOJ-BEADS
错的
 */
int smallestRepresentation(string s){
    int i,j,k,l;
    int N=s.length();
    s+=s;
    for(i=0;j=1;j<N){
        for(k=0;k<N&& s[i+k]==s[j+k];k++);
        if(k>=N)break;
        if(s[i+k]<s[j+k]){
            j+=k+1;
        }else{
            l=i+k;
            i=j;
            j=max(l,j)+1;
        } 
    }
    return i;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<smallestRepresentation(s)<<endl;
    }
}