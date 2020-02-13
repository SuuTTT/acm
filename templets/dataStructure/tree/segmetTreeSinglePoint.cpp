/* 
单点修改，查询区间max
 */
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;

#define TREE_SIZE (1<<(20))
class IntervalTree{
    private:
    int Cover[TREE_SIZE],Top[TREE_SIZE];
    int size;
    int _Query(int a,int b,int l,int r,int Ind){
        if(a<=l&&b>=r)return  Top[Ind];
        int mid=(l+r)>>1,ret=Cover[Ind];
        if(a<=mid)ret=max(ret,_Query(a,b,l,mid,Ind<<1));
        if(b>mid)ret=max(ret,_Query(a,b,mid+1,r,(Ind<<1)+1));
        return ret;
    }

    void _Modify(int a,int l,int r,int Ind,int d){
        if(l==r&&l==a){
            Cover[Ind]=Top[Ind]=d;
            return;
        }
        int mid = (l+r)>>1;
        if(a<=mid)_Modify(a,l,mid,Ind<<1,d);
        else _Modify(a,mid+1,r,(Ind<<1)+1,d);
        Top[Ind]=max(Top[Ind<<1],Top[(Ind<<1)+1]);
    }
    public:
        IntervalTree(){
            memset(Cover,0,sizeof(Cover));
            memset(Top,0,sizeof(Top));
            size=(TREE_SIZE>>2)-1;

        }
        int Query(int a,int b)return _Query(a,b,1,size,1);
        void Modify(int a,int b){
            return _Modify(a,1,size,1,d);
        }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
