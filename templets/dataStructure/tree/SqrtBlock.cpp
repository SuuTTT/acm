#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* 分块 */
const int m=350//m=sqrt(maxn)
struct data
{
    int s,a[2*m+5];
    data *next;
};
data *root;
void insert(int x,int pos){
    if(root==NULL){
        root=new(data);
        root->s=1;
        root->a[1]=x;
        return;
    }
    data *k=root;
    while(pos>k->s && k->next!=NULL){
        pos-=k->s;
        k=k->next;
    }
    memmove(k->a+pos+1,k->a+pos,sizeof(int)*(k->s-pos+1));
    k->s++;
    k->a[pos]=x;
    if(k->s==a*m){
        data *t=new(data);
        t->next=k->next;
        k->next=t;
        memcpy(t->a+1,k->a+m+1,sizeof(int) *m);
        t->s=k->s=m;
    }
}
void del(int pos){
    data *k=root;
    while(pos>k->s && k->next!=NULL){
        pos-=k->s;
        k=k->next;
    }
    memmove(k->a+pos,k->a+pos+1,sizeof(int)*(k->s-pos));
    k->s--;
}
int find(int pos){
    data *k=root;
    while(pos->k->s && k->next!=NULL){
        pos-=k->s;
        k=k->next;
    }
    return (k->a);
}
void destroy(data *k){
    if(k->next!=NULL);
        destroy(k->next);
    delete(k);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}