#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

vector<string> split(string &s){
    s+=' ';
    vector<string> x;
    int last=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]==' ' || s[i]=='=' || s[i]=='+')x.emplace_back(s.substr(last,i-last)),last=i+1;
    }
    return x;
}
typedef vector<string> code;
class prog{
public:
    vector<code> a;
    map<string,ll> mp;
    ll tot=0;
    void read(){
        ll n;
        cin>>n;
        string s;
        getline(cin,s);
        while(n--){
            getline(cin,s);
            a.emplace_back(split(s));
        }
    }
    void show(){
        for(auto c:a){
            if(c.size()==2)cout<<" "<<c[0]<<" "<<mp[c[1]]<<endl;
            else{
                for(auto i:c)cout<<" "<<mp[i];
                cout<<endl;
            }
        }
    }
    void add_variable(string name){
        if(mp.find(name)==mp.end())mp[name]=++tot;
    }
    void rename(){
        for(auto c:a){
            if(c.size()==2)add_variable(c[1]);
            else{
                add_variable(c[0]);
                add_variable(c[1]);
                add_variable(c[2]);
            }
        }
    }
};
bool equal(prog &x,prog &y){
    if(x.a.size()!=y.a.size())return false;
    rep(i,0,(ll)x.a.size()-1){
        if(x.a[i].size()!=y.a[i].size())return false;
        if(x.a[i].size()==2){
            if(x.a[i][0]!=y.a[i][0])return false;
            if(x.mp[x.a[i][1]]!=y.mp[y.a[i][1]])return false;
        }else{
            if(x.mp[x.a[i][0]]!=y.mp[y.a[i][0]])return false;
            if(x.mp[x.a[i][1]]!=y.mp[y.a[i][1]])return false;
            if(x.mp[x.a[i][2]]!=y.mp[y.a[i][2]])return false;
        }
    }
    return true;
}
prog a,b;

int main(){
#ifdef ATPLAB
//freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    a.read();
    b.read();
    a.rename();
    b.rename();
    //a.show();
    //b.show();
    cout<<(equal(a,b)?"YES":"NO")<<endl;
    return 0;
}
/*

*///