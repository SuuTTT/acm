#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=100005;
map<string,int> score,total;
string id[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c,p,s;
    cin>>c>>p>>s;
    rep(i,1,c)cin>>id[i];
    rep(i,1,p){
        string s;int x;
        cin>>s>>x;
        score[s]=x;
    }
    rep(i,1,s){
        string a,b,c;
        cin>>a>>b>>c;
        if(c=="AC"){
            total[a]+=score[b];
        }
    }
    rep(i,1,c)cout<<id[i]<<' '<<total[id[i]]<<endl;
}
/*
2 2 4
GabrielPessoa
beza
metebronca 100
geometry 200
beza metebronca AC
ffern numbertheory AC
GabrielPessoa geometry WA
beza geometry AC
*/