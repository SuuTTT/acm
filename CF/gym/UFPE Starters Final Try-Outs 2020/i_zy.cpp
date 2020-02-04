#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
int father[4005],rk[4005];
void init(int n){
    for(int i=0;i<n;i++)father[i]=i;
}
int find(int v){
    return father[v]=father[v]==v?
    v:find(father[v]);
}

void merge(int x,int y){
    int a=find(x),b=find(y);
    if(rk[a]<rk[b]){
        father[a]=b;
    }else{
        father[b]=a;
        if(rk[b]==rk[a]){
            ++rk[a];
        }
    }
}

int main(){

}