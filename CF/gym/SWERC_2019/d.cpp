#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

struct node{
    int index;
    vector<node> data;
    bool operator == (const node &b)const{
        if(index!=b.index)return false;
        if(index==-1)return (data[0]==b.data[0] && data[1]==b.data[1]);
        return true;
    }
    void show(){
        if(index!=-1)cout<<(char)(9-index+'a');
        else{
            cout<<"<";
            data[0].show();
            cout<<",";
            data[1].show();
            cout<<">";
        }
    }
}temp;
class protein{
public:
    vector<node> a;
    int fail=0;
    void init(int n){
        fail=0;
        a.clear();
        a.resize(n);
        rep(i,0,(ll)a.size()-1)a[i].index=i+1;
    }
    void show(){
        for(ll i=(ll)a.size()-1;i>=0;i--){
            a[i].show();
            cout<<"-";
        }
        cout<<endl;
    }
    bool operator == (const protein &b)const{
        if(fail!=b.fail)return false;
        if(a.size()!=b.a.size())return false;
        rep(i,0,(ll)a.size()-1){
            if(!(a[i]==b.a[i]))return false;
        }
        return true;
    }
    void translate(char op){
        if(fail==1)return;
        if(op=='C'){
            a.emplace_back(a.back());
        }else if(op=='D'){
            a.pop_back();
        }else if(op=='L'){
            if(a.back().index!=-1){
                fail=1;
                a.clear();
            }else{
                temp=a.back().data[0];
                a.back()=temp;
            }
        }else if(op=='P'){
            temp=(node){-1,(vector<node>){a[(ll)a.size()-1],a[(ll)a.size()-2]}};
            a.pop_back();
            a.pop_back();
            a.emplace_back(temp);
        }else if(op=='R'){
            if(a.back().index!=-1){
                fail=1;
                a.clear();
            }else{
                a.back()=a.back().data[1];
            }
        }else if(op=='S'){
            swap(a[(ll)a.size()-1],a[(ll)a.size()-2]);
        }else if(op=='U'){
            if(a.back().index!=-1){
                fail=1;
                a.clear();
            }else{
                temp=a.back();
                a.pop_back();
                a.emplace_back(temp.data[1]);
                a.emplace_back(temp.data[0]);
            }
        }
    }
};

protein p1,p2;
string op1,op2;

void test(){
    p1.init(9);
    op1="PSDSPCRPSDUL";
    for(auto i:op1){
        p1.translate(i);
        p1.show();
    }
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    test();
    while(cin>>op1>>op2){
        ll len=(ll)max(op1.size(),op2.size())+10;
        p1.init(len);
        p2.init(len);
        for(auto i:op1)p1.translate(i);
        for(auto i:op2)p2.translate(i);
        cout<<(p1==p2?"True":"False")<<endl;
    }
    return 0;
}
/*

*///