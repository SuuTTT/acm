#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
string ve;
char ss[maxn];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string line,tmp;
    fgets(ss, sizeof(ss), stdin);
    int len=strlen(ss);
    //stringstream ss;
    string s;
    int flag=0;
    rep(i,0,len-1){
        char c=ss[i];
         if(c==' '){ 
            if(flag==0)ve+=s;
            s="";
            flag=0;
        }
        else if(((c >= 'A') && (c <= 'Z'))||((c >= 'a') && (c <= 'z'))||(c>='0'&&c<='9')){
            s+=c;
            if(c!='u'&& c!='m')
                flag=1;
        }
    };
    if(flag==0)ve+=s;
    //debug(ve);
    //int i=-1;
    string ans;
    int cur=0;
    int cnt=-1;
    
    for(auto c:ve){
        cur*=2;
        cur+=(c=='u');
        if(cnt%7==0)putchar((char)cur),cur=0;
        if(cnt==-1)cnt=1;
        cnt++;
    }
    cout<<endl;
    //ans.push_back((char)cur);
}
/* 
uu Friends m Romans ummuuummmuuuuumm countrymen mmuummmuu
umm ummm uum umm um ummmm u?

umm um1 ummm, uum umm um ummmm u?

+=
getline 有问题

 */