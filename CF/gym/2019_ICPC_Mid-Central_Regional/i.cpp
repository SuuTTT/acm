#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

char trans(char c){
    if ((c >= 'A') && (c <= 'Z'))
		return c + ('a' - 'A');
    if ((c >= 'a') && (c <= 'z'))
		return c + ('A' - 'a');
    return c;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int flag=0;
    if(s1==s2)flag=1;
    string s3=s1[0]+s2;
    if(s1[0]>='0'&&s1[0]<='9'&&s3==s1)flag=1;
    s3=s2+s1.back();
    if(s1.back()>='0'&&s1.back()<='9'&&s3==s1)flag=1;
    
    s3="";
    for(auto t:s2){
        s3+=trans(t);
    }
   //debug(s3);
    if(s3==s1)flag=1;
    cout<<(flag?"Yes":"No")<<endl;
}

/* 
1234
123

123a
123

a123
123

c0deninja5
c0deninja

abc
ABC

pa55WORD
PA55word
 */