#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
vector<string> input;
vector<char> ans;
char a='A',b='B',c='C';

map<char,int> num;
string not_zero(){
    if(num[a]==1)return "A";
    if(num[b]==1)return "B";
    if(num[c]==1)return "C";
    return "";
}
void mod(char a,char b){
    num[a]++,num[b]--;
    ans.push_back(a);
}
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n>>num[a]>>num[b]>>num[c];
    while(n--){
        string s;cin>>s;input.push_back(s);
    }
    if(num[a]+num[b]+num[c]==0)puts("No");
    if(num[a]+num[b]+num[c]==1){
        for(auto ss:input){
            if(ss.find(not_zero())!=ss.npos){
                int tmp=(int)ss.find(not_zero());
                //debug(tmp);
                mod(ss[1-tmp],ss[tmp]);
               
            }else{
                puts("No");
                return 0;
            }
        }
        puts("Yes");
        for(auto ss:ans){ cout<<ss<<endl;}
    }else{
        auto t=input.front();
        if(num[t[0]]+num[t[1]]==0){puts("No");return 0;}
        for (int i=0;i<input.size();i++){
            auto ss=input[i];
            if(num[ss[0]]==0)mod(ss[0],ss[1]);
            else if(num[ss[1]]==0)mod(ss[1],ss[0]);
            else if(num[ss[0]]==1||num[ss[1]]==1){
                if(i==input.size()-1){
                    mod(ss[0],ss[1]);
                }else{
                    auto nxt=input[i+1];
                    char c1=ss[0],c2=ss[1];
                    if(num[ss[1]]==1)swap(c1,c2);
                    if(nxt.find(c1)!=nxt.npos)mod(c1,c2);
                    else mod(c2,c1);// 1 1
                } 
            }else{
               mod(ss[0],ss[1]);
            }
        }
        puts("Yes");
        for(auto ss:ans){ cout<<ss<<endl;}
    }
}
/* 
new: string, char, find, npos
type: construct& code
0 0 1
0 1 1
0 0 2
0 0 3

hard 1638
3 1 0 0
AB
BC
AB

3 1 0 0
AB
BC
CA
5 2 0 0 
AB
AB 
AB
AB
AB
 */