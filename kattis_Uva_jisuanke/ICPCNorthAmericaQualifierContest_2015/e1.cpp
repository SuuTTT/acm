#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

class Grid{
public:
    ll h,w;
    pair<Grid,Grid> cut_H(ll p)const{
        return (pair<Grid,Grid>){(Grid){p,w},(Grid){h-p,w}};
    }
    pair<Grid,Grid> cut_V(ll p)const{
        return (pair<Grid,Grid>){(Grid){h,p},(Grid){h,w-p}};
    }
};

bool dfs(vector<Grid> a,int op){
    vector<Grid> b;
    if(op==0){//H
        rep(i,0,(ll)a.size()-1){
            rep(p,1,a[i].h/2){
                b=a;
                auto sp=b[i].cut_H(p);
                b[i]=sp.first;
                b.emplace_back(sp.second);
                if(dfs(b,1-op)==false)return true;
            }
        }
        return false;
    }else{//V
        rep(i,0,(ll)a.size()-1){
            rep(p,1,a[i].w/2){
                b=a;
                auto sp=b[i].cut_V(p);
                b[i]=sp.first;
                b.emplace_back(sp.second);
                if(dfs(b,1-op)==false)return true;
            }
        }
        return false;
    }
}
bool solve(ll w,ll h,ll op){
    return dfs({(Grid){h,w}},op);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rep(w,1,6){
        rep(h,1,6){
            cout<<solve(w,h,0)<<" ";
            cout.flush();
        }
        cout<<endl;
    }
    cout<<endl;
    rep(w,1,6){
        rep(h,1,6){
            cout<<solve(w,h,1)<<" ";
            cout.flush();
        }
        cout<<endl;
    }
    return 0;
}
/*

*///
