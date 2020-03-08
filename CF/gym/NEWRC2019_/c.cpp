#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
int T;
int n,l[1009],r[1009],p,x[2009],has[1009];
map<int,int>mp;
vector<int>ans;
int main(){
//    scanf("%d",&T);
    T=1;
    for(int cas=1;cas<=T;cas++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
        scanf("%d",&p);
        mp.clear();
        for (int i=1;i<=p;i++)scanf("%d",&x[i]),mp[x[i]]=i;
        int cnt=1;
        int f=1;
        for(int i=1;i<=p;i++){
            while(cnt<=n&&(r[cnt]<x[i]))cnt++;
            if(cnt>n)break;
            if(l[cnt]<=x[i]&&r[cnt]>=x[i])has[cnt]++;
            if(has[cnt]>2)f=0;
            if(r[cnt]==x[i]){
                cnt++;
                if(cnt<=n&&l[cnt]<=x[i]&&r[cnt]>=x[i])has[cnt]++;
                if(has[cnt]>2)f=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(has[i]>=2)continue;
            if(i<n&&has[i+1]<2&&mp[r[i]]==0){
                ans.push_back(r[i]);
                has[i]++;
                has[i+1]++;
                mp[r[i]]=i;
            }
            cnt=r[i]-1;
            while(has[i]<2){
                if(mp[cnt]==0){
                    has[i]++;
                    mp[cnt]=i;
                    ans.push_back(cnt);
                }
                cnt--;
            }
        }
        if(f==0){
            printf("impossible\n");
            return 0;
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
/*

*/