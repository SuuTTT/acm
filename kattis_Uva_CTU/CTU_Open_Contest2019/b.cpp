#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    long long tot=0;
    while(cin>>s){
        if(s[0]=='|')tot+=s.size()*42;
        else {
            int p=0;
            int price=0;
            while(s[p]>='0'&&s[p]<='9'){
                price*=10;
                price+=s[p]-'0';
                p++;
            }
            p+=2;
            if(s.size()>p){price*=(s.size()-p);}
            tot+=price;
            //debug(price);
        }
        
    }
    debug(tot);
    if(tot%10>=5)tot+=10;
    tot/=10,tot*=10;
    if(tot==0)tot=10;
    cout<<tot<<','<<'-'<<endl;
}
/* 

1,-
|代表一杯酒

4,-||

||||
123,-|||

|||
12,-|
|||
12,-||
10,-|

|
8,-|

 */