#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const double eps=1e-7;

ll n;
double t[100005],s[100005],a[100005];
struct node{
    double angle,dk;
    bool operator < (const node &b)const{
        return angle<b.angle;
    } 
};
int dcmp(double x){
    return fabs(x)<eps?0:x>0?1:-1;
}
double safe_angle(double a){
    while(a>=2*pi)a-=2*pi;
    while(a<0)a+=2*pi;
    return a;
}
double dist(double a,double b){
    double c=safe_angle(a-b);
    if(c>pi)c=2*pi-c;
    return c;
}
double K_before(double b,double t,double s,double a){
    double k=0;
    if(dcmp(t/s-pi)<0){
        if(dcmp(safe_angle(b-a))>0 and dcmp(safe_angle(b-a)-t/s)<=0)k=-s;
        else if(dcmp(safe_angle(b-a)-t/s)>0 and dcmp(safe_angle(b-a)-(2*pi-t/s))<=0)k=0;
        else k=s;
    }else{
        if(dcmp(safe_angle(b-a))>0 and dcmp(safe_angle(b-a)-pi)<=0)k=-s;
        else k=s;
    }
    return k;
}
double solve(){
    static vector<node> d;
    d.clear();
    rep(i,1,n){
        double a_=safe_angle(a[i]+pi);
        if(s[i]*pi<t[i]){
            d.emplace_back((node){a[i],-2*s[i]});
            d.emplace_back((node){a_,2*s[i]});
        }else{
            d.emplace_back((node){a[i],-2*s[i]});
            d.emplace_back((node){safe_angle(a[i]+t[i]/s[i]),s[i]});
            d.emplace_back((node){safe_angle(a[i]-t[i]/s[i]),s[i]});
        }
    }
    sort(d.begin(),d.end());
    double ans=0,x=0,y=0,k=0;
    rep(i,1,n){
        k+=K_before(0,t[i],s[i],a[i]);
        y+=max(0.0,t[i]-s[i]*dist(a[i],0.0));
    }
    for(auto p:d){
        y+=(p.angle-x)*k;
        k+=p.dk;
        x=p.angle;
        ans=max(ans,y);
    }
    return ans;
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n){
        rep(i,1,n)cin>>t[i]>>s[i]>>a[i];
        cout<<fixed<<setprecision(10)<<solve()<<endl;
    }
    return 0;
}
/*

*///
