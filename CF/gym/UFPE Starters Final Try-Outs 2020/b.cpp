#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=200005;
const int MAXN = 200010;
string s[maxn];
typedef long long LL;
map<string,int> mp;
struct Node {
    int l, r;
    LL lazy;
    LL sum;
} segTree[MAXN * 4];
void build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    if (l == r) {
        segTree[i].sum=mp[s[l]];
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    segTree[i].sum = segTree[i << 1].sum + segTree[i << 1 | 1].sum;
}
void push_up(int i, LL v) {
    segTree[i].sum += (segTree[i].r - segTree[i].l + 1) * v;
    segTree[i].lazy += v;
}
void push_down(int i) {
    if (segTree[i].l == segTree[i].r) return;
    push_up(i << 1, segTree[i].lazy);
    push_up(i << 1 | 1, segTree[i].lazy);
    segTree[i].lazy = 0;
}
void add(int i, int l, int r, LL v) {
    if (segTree[i].l >= l && segTree[i].r <= r) {
        push_up(i, v);
        return;
    }
    push_down(i);
    int mid = segTree[i].l + segTree[i].r >> 1;
    if (mid >= l) add(i << 1, l, r, v);
    if (mid < r) add(i << 1 | 1, l, r, v);
    segTree[i].sum = segTree[i << 1].sum + segTree[i << 1 | 1].sum;
}
LL query(int i, int l, int r) {
    if (segTree[i].l == l && segTree[i].r == r) return segTree[i].sum;
    push_down(i);
    int mid = segTree[i].l + segTree[i].r >> 1;
    if (r <= mid) return query(i << 1, l, r);
    else if (l > mid) return query(i << 1 | 1, l, r);
    else return query(i << 1, l, mid) + query(i << 1 | 1, mid + 1, r);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    
    rep(i,1,n){
        cin>>s[i];
    }
    rep(i,1,m){
        string ss;
        int x;
        cin>>ss>>x;
        mp[ss]=x;
    }
     build(1, 1, n);
    rep(i,1,q){
        int op=0;
         cin>>op;
         string ss;
         int l=0,r=0;
        if (op == 1) {
            cin>>l>>ss;
            add(1, l, l, -mp[s[l]]+mp[ss]);
            s[l]=ss;
        } else {
            cin>>l>>r;
            cout<<(query(1, l, r)*2>(r-l+1)*60?"YES":"NO")<<endl;
         
        }
    }

}
/*
6 6 5
vodka pitu beats whisky vodka cuba
vodka 30
caipirinha 10
pitu 35
beats 15
whisky 20
cuba 50
2 3 4
1 3 cuba
2 3 3
1 5 cuba
2 1 5
*/