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
int n,k,a[200009];
int has[200009];
vector<int>ve;
int vis[200009];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]=0;
        has[a[i]]++;
	}
	for(int i=1;i<=n;i++){
        has[a[i]]--;
        if(vis[a[i]])continue;
        while(ve.size()>0&&ve[ve.size()-1]>a[i]&&has[ve[ve.size()-1]]>0){
            vis[ve[ve.size()-1]]=0;
            ve.pop_back();
        }
        ve.push_back(a[i]);
        vis[a[i]]=1;
	}
	for(int i=0;i<k;i++)cout<<ve[i]<<(i==k-1?"\n":" ");
    return 0;
}
/*
10 5
4 2 5 3 1 2 4 2 1 3
*/
