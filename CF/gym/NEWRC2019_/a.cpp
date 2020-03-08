#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
typedef long long ll;
int T;
int n,w;
set<int>se[300009];
int ls[300009];//上次统计时间
int ji[300009];//在那个集合
int rk[300009];//每个集合排名
int p[300009];//每人分数
ll sum[300009];//排名之和
int jip[300009];//集合的分数
int fr[300009];//排名前一位的是那个集合
int af[300009];//排名后一位的是那个集合
set<int>le;//有那些集合空着
ll sumji[300009];
set<int>::iterator it;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        se[1].insert(i);
        ji[i]=1;
        p[i]=0;
        le.insert(i);
    }
    rk[1]=1;jip[1]=0;fr[1]=-1;af[1]=-1;le.erase(1);sumji[1]=0;ls[1]=1;
    scanf("%d",&w);
    vector<int>v;
    for(int now=1;now<=w;now++){
        int k,c;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&c);
            int jic=ji[c];
            int frc=fr[jic];
            int rkc=rk[jic];
            se[jic].erase(c);
            sumji[jic]+=(ll)(now-ls[jic])*rk[jic];
            sum[c]+=sumji[jic];
            ls[jic]=now;
            v.push_back(jic);
            p[c]++;
            if(frc>0&&p[c]==jip[frc]){
                ls[c]=now;
//                debug(c);debug(sum[c]);
                se[frc].insert(c);
                sumji[frc]+=(ll)(now-ls[frc])*rk[frc];
                ls[frc]=now;
                sum[c]-=sumji[frc];
                ji[c]=frc;
            }
            else {
                int to=*le.begin();
                le.erase(to);
                se[to].insert(c);
                fr[to]=fr[jic];
                af[to]=jic;
                fr[jic]=to;
                if(fr[to]>0)af[fr[to]]=to;
                ji[c]=to;
                rk[to]=rkc;
                jip[to]=p[c];
                sumji[to]=0;
                ls[to]=now;
            }
        }
        for(int i=0;i<v.size();i++){
            if(se[v[i]].empty()){
                if(fr[v[i]]>0)af[fr[v[i]]]=af[v[i]];
                if(af[v[i]]>0)fr[af[v[i]]]=fr[v[i]];
                le.insert(v[i]);
            }
            rk[v[i]]++;
        }
        v.clear();
//        for(int j=1;j<=n;j++)printf("%d ",sumji[ji[j]]);
//        printf("$$$$$$$$$$\n");
//        for(int j=1;j<=n;j++)printf("%d ",ls[ji[j]]);
//        printf("&&&&&&&&&&\n");
//        for(int j=1;j<=n;j++)printf("%d ",sum[j]);
//        printf("%%%%%%%%%%\n");
//        for(int j=1;j<=n;j++)printf("%d ",rk[ji[j]]);
//        printf("^^^^^^^^^^\n");
    }
    for(int i=1;i<=n;i++){
//        debug(rk[ji[i]]);
        sum[i]+=sumji[ji[i]]+(ll)(w+1-ls[ji[i]])*(rk[ji[i]]);
//        debug(sum[i]);
        printf("%.9lf\n",(double)sum[i]/w);
    }
    return 0;
}
/*

*/