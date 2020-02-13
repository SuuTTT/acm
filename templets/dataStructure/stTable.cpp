#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int stTable[maxn][32],stTable2[maxn][32];
int preLog2[maxn],a[maxn];

void st_prepare(int n,int *array){
    preLog2[1]=0;
    rep(i,2,n){
        preLog2[i]=preLog2[i-1];
        if((1<<preLog2[i]+1)==i){
            ++preLog2[i];
        }
    }
    for(int i=n-1;i>=0;i--){
        stTable[i][0]=array[i];
        for(int j=1;(i+(1<<j)-1)<n;++j){
            stTable[i][j]=min(stTable[i][j-1],
            stTable[i+(1<<j-1)][j-1]);
        }
    }

     for(int i=n-1;i>=0;i--){
        stTable2[i][0]=array[i];
        for(int j=1;(i+(1<<j)-1)<n;++j){
            stTable2[i][j]=max(stTable2[i][j-1],
            stTable2[i+(1<<j-1)][j-1]);
        }
    }
}

int query_min(int l,int r){
    int len=r-l+1,k=preLog2[len];
    return min(stTable[l][k],stTable[r-(1<<k)+1][k]);
}

int query_max(int l,int r){
    int len=r-l+1,k=preLog2[len];
    return max(stTable2[l][k],stTable2[r-(1<<k)+1][k]);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    rep(i,0,n-1)cin>>a[i];
    st_prepare(n,a);
    rep(i,1,q){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<query_max(l,r)-query_min(l,r)<<endl;
    }
}
/* 
6 3
1
7
3
4
2
5
1 5
4 6
2 2
 */