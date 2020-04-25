#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
int cnt[10],ans[10],sum;
int k;
bool dfs(int num,int bit){//返回是否有解 num=9~1，当前数字  bit=还要选几个数
    if(num==-1){
        if(bit!=0)return 0;
        if(sum%3!=0)return 0;
        return 1;
    }
    int tmp=min(bit,cnt[num]);
    for(ans[num]=tmp;ans[num]>=max(0,tmp-2);ans[num]--){
        sum+=ans[num]*num;
        if(dfs(num-1,bit-ans[num]))return 1;
        sum-=ans[num]*num;
    }
    return 0;//递归下去都无解，本层也无解
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--){
        string s;
        cin>>s>>k;
        rep(i,0,9)cnt[i]=ans[i]=0;
        for(auto c:s)cnt[c-'0']++;
        sum=0;
        if(!dfs(9,k)){
            cout<<-1<<endl;
        }else{
            int flag=0;
            rep(i,1,9)flag+=ans[i];
            if(!flag&&ans[0]>1)cout<<-1<<endl;
            else{
                for(int i=9;i>=0;i--)rep(j,1,ans[i])cout<<i;
                cout<<endl;
            }
        }
    }
}
/* 
枚举
贪心+mod3 性质：
越大的越多，每个拿的数量是num-num%3,最后只会剩下0,1,2三种情况，
暴力枚举9~0剩这些数的情况。
O(3^9)
3
000 1
000 2
000 3
 */