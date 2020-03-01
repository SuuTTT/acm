#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e3+5;
/* 
.size() is O(n)
 */
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    list<int> L[maxn];
    int n,q;
    cin>>n>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==0){
            int t,x;cin>>t>>x;
            L[t].push_back(x);
        }else{
            if(op==1){
                int t;cin>>t;
                int cnt=1;
                int len=L[t].size();
                for(auto it=L[t].begin();it!=L[t].end();it++)cout<<*it<<(cnt++==len?'\n':' ');
                if(L[t].empty())cout<<endl;
            }else{
                int s,t;
                cin>>s>>t;
                L[t].splice(L[t].end(),L[s]);
            }
        }
    }
}
/* 
- insert(tt, xx): Insert an integer xx at the end of LtLt.
- dump(tt): Print all elements in LtLt.
- splice(ss, tt):　Transfer elements of LsLs to the end of LtLt. LsLs becomes empty.
3 10
0 0 1
0 0 2
0 0 3
0 1 4
0 1 5
2 1 0
0 2 6
1 0
1 1
1 2
 */