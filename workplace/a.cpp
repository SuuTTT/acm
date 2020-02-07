#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int val[maxn];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        string s;
        cin>>s;
        val[i]=(s[0]=='T'?1:0);
    }
    string s;
    stack<int> res;
    while(cin>>s){
        //debug(s);
        if(s[0]>='A'&&s[0]<='Z')res.push(val[s[0]-'A'+1]);
        else{
            if(s[0]=='-'){
                int num1=res.top();res.pop();
                num1=!num1;
                res.push(num1);
            }
            else{
                int num1=res.top();res.pop();
                int num2=res.top();res.pop();
                if(s[0]=='+')num1|=num2,res.push(num1);
                if(s[0]=='*')num1&=num2,res.push(num1);
            } 
        }
        //if(!res.empty())debug(res.top());
    }
    cout<<(res.top()?'T':'F');
}
/* 
4
T F T F
A B * C D + - +
 */