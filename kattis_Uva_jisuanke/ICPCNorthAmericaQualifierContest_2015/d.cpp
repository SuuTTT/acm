#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;
const int MAXN = (int)2e3+7;
const int INF = (int)0x3f3f3f3f;

ll dp[45][809][809];
set< pair<int,int> >fr,nx;
set< pair<int,int> >::iterator it;
int n;
pair<int,int>pi[45];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>pi[i].first>>pi[i].second;
    }
    fr.insert(make_pair(400,400));
    dp[0][400][400]=1;
    for(int i=0;i<n;i++){
//        debug(i);
//        debug(fr.size());
        for(it=fr.begin();it!=fr.end();it++){
            //printf("%d: %d %d\n",i,(*it).first,(*it).second);
            dp[i+1][(*it).first][(*it).second]+=dp[i][(*it).first][(*it).second];
            nx.insert(*it);
            dp[i+1][(*it).first+pi[i+1].first][(*it).second+pi[i+1].second]+=dp[i][(*it).first][(*it).second];
            nx.insert(make_pair((*it).first+pi[i+1].first,(*it).second+pi[i+1].second));
        }
        fr=nx;
    }
    printf("%lld\n",dp[n][400][400]-1);
}
/*

*/
/* 
40个向量 可以组成几个环
向量大小<10
宽搜？
 */