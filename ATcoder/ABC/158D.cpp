#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int rev=0;
    string head,tail;
    int n;cin>>n;
    rep(i,1,n){
        int op=0;
        cin>>op;
        if(op==1)rev=!rev;
        else{
            int flag;
            char c;
            cin>>flag>>c;
            if(flag==1&&rev==0||flag==2&&rev==1){head+=(char)c;}
            else tail+=(char)c;
        }  
    }
    reverse(head.begin(),head.end());
    s=head+s;
    s+=tail;
    if(rev)reverse(s.begin(),s.end());
    cout<<s<<endl;
}
/* 
a
4
2 1 p
1
2 2 c
1
 */