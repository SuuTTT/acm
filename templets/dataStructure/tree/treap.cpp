#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
/* 
treap is 平衡化二叉搜索树，
key[]满足二叉搜索树要求，
priority满足堆的需求。
如果priority[]是随机的，treap的期望深度为O(logN)

插入：先把节点插入到二叉树相应位置，并随机赋权值，
然后类似堆，每次比较其及其父亲，不满足就交换

删除，把prority修改成足够大，然后进行堆序维护，删除叶子即可。

child[0] child[1] 表示左右儿子，简化旋转操作，
 */
const int maxNode=444444;
struct Treap{
    int root,treapCnt,key[maxNode],priority[maxNode],
    childs[maxNode][2],cnt[maxNode],size[maxNode];

    Treap(){
      root=0;
      treapCnt=1;
      priority[0]=INT_MAX;
      size[0]=0;   
    }

    void update(int x){
        size[x]=size[childs[x][0]]+cnt[x]+size[childs[x][1]];
    }

    void rotate(int &x,int y){
        int y=childs[x][t];
        childs[x][t]=childs[y][1-t];
        childs[y][1-t]=x;
        update(x);
        update(y);
        x=y;
    }

    void __insert(int &x,int k){
        if(x){
            if(key[x]==k){
                cnt[x]++;
            }else{
                int t=dey[x]<k;
                __insert(childs[x][t],k);
                if(priority[childs[x][t]]<priority[x]){
                    rotate(x,t);
                }
            }
        }else{
            x=treapCnt++;
            key[x]=k;
            cnt[x]=1;
            priority[x]=rand();//srand??
            childs[x][0]=childs[x][1]=0;
        }
        update(x);
    }

    void __erase(int &x,int k){
        if(key[x]==k){
            if(cnt[x]>1){
                cnt[x]--;
            }else{
                if(childs[x][0]==0&&childs[x][1]==0){
                    x=0;
                    return;
                }
                int t=priority[childs[x][0]]>priority[childs[x][1]];
                rotate(x,t);
                __erase(x,k);
            }
        }else{
            __erase(childs[x][key[x]<k],k);
        }
        update(x);
    }
    
    void insert(int k){
        __insert(root,k);
    }

    void erase(int k){
        __erase(root,k);
    }

    int getKth(int k){
        return __getKth(root,k);
    }
}

int __getKth(int &x,int k){
    if(k<=size[childs[x][0]]){
        return __getKth(childs[x][0],k);
    }
    k-=size[childs[x][0]]+cnt[x];
    if(k<=0){
        return key[x];
    }
    return __getKth(childs[x][1],k);
}
int main(){
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}