#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
struct student{
    int date;
    string id;
    double temp;
    bool operator <(const student & a)const{
        if(date==a.date){
            return temp==a.temp?id<a.id:temp>a.temp;
        }
        return date>a.date;
    }
}stu[maxn];
int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int cnt=0;
    int i=1;
    while(n--){
        
        cin>>stu[i].date>>stu[i].id>>stu[i].temp;
        if(stu[i].temp<38.0)i--;else cnt++;
        i++;
    }
    sort(stu+1,stu+1+cnt);
    cout<<cnt<<endl;
    rep(i,1,cnt){
        
        cout<<stu[i].date<<' '<<stu[i].id<<' ';
        printf("%.1lf\n",stu[i].temp);
    }
}
/* 
5
20200229 17122490 37.0
20200301 17122490 38.4
20200229 17122640 39.0
20200301 17122640 38.4
20200301 16122138 38.1
 */