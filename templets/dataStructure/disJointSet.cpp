//#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
using namespace std;
struct DisJointSet{
    vector<int> father,rk;
    DisJointSet(int n):father(n),rk(n){
        for(int i=0;i<n;i++)father[i]=i;
    }
    
    int find(int v){
        return father[v]=father[v]==v?
        v:find(father[v]);
    }

    bool merge(int x,int y){
        int a=find(x),b=find(y);
        if(a==b)return 0;
        if(rk[a]<rk[b]){
            father[a]=b;
        }else{
            father[b]=a;
            if(rk[b]==rk[a]){
                ++rk[a];
            }
        }
        return 1;
    }
    
};
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
    int n,m;
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init(n*2);
        int flag=1;
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int a=find(x),b=find(y);
            if(a==b)flag=0;
            merge(x,y+n);
            merge(y,x+n);
        }
        if(kase>1)printf("\n");
        printf("Scenario #%d:\n",kase++);
        puts(flag?"No suspicious bugs found!"
        :"Suspicious bugs found!");
    
    }
    return 0;
}