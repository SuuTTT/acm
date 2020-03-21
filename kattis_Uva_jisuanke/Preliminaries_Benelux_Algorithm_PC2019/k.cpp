#include<bits/stdc++.h>
using namespace std;//[]
typedef long long ll;
const ll mod = (ll)1e9+7;
vector<int>ans;
int a[300009];
map<int,int>mp;
int judge(int x){
    for(int i=0;i<=18;i++){
        int y=1<<i;
        if(y>x)break;
        if(y==x)return 0;
    }
    return 1;
}
int main (void)
{
    int n;
    scanf("%d",&n);
    int m=(1<<n);
    for(int i=0;i<m;i++)scanf("%d",&a[i]);
    sort(a,a+m);
    if(a[0]>0){
        printf("impossible");
        return 0;
    }
    ans.push_back(a[1]);
    for(int i=2;i<m;i++){
        if(mp[a[i]]>0)mp[a[i]]--;
        else{
            ans.push_back(a[i]);
            int x=ans.size();
            for(int j=3;j<(1<<x);j++){
                if(judge(j)){
                    int y=0;
                    for(int k=0;k<x;k++){
                        if(j&(1<<k))y+=ans[k];
                    }
                    mp[y]++;
                }
            }
        }
    }
    if(ans.size()>n)printf("impossible");
    else{
        for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]);
    }
    return 0;
}