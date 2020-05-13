#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define per(i,j,k) for(int i = (int)j;i >= (int)k;i --)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define pb push_back

typedef double db;
typedef long long ll;
const int MAXN = (int)2e3 + 7;
const int INF = (int)0x3f3f3f3f;
int e[509][509];
int match[509];
int book[509];
int n;

int dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(book[i]==0&&e[u][i]==1)
        {
            book[i]=1;
            if(match[i]==0||dfs(match[i]))
            {
                //cout<<u<<" "<<i<<endl;
                match[i]=u;
                //match[u]=i;
                return 1;
            }
        }
    }
    return 0;
}
string str[509];
map<string,int>mp;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>str[i],mp[str[i]]=i;
    for(int i=1;i<=n;i++){
        for(int j=0;j<str[i].size();j++)
            for(int k=j+1;k<str[i].size();k++){
                swap(str[i][j],str[i][k]);
                if(mp[str[i]])e[i][mp[str[i]]]=1;
                swap(str[i][j],str[i][k]);
            }
    }
    //for(int i=1;i<=n;i++){ for(int j=1;j<=n;j++)cout<<e[i][j]<<" ";cout<<endl;}

    for(int i=1;i<=n;i++)match[i]=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)book[j]=0;
        if(dfs(i))sum++;
    }


    //for(int i=1;i<=n;i++)cout<<match[i]<<endl;
    printf("%d\n",n-sum/2);
    return 0;
}

/* 
最大的集合使得 任意两个串都不能通过交换一对字母获得
 */