#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
const int maxn=(int)1e6+5;
struct Info{
    int to,cost;
    Info(int _to,int _cost){
        to=_to,cost=_cost;
    }
    bool operator< (const Info& arg){
        return cost>arg.cost;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int V,E,st;
    cin>>V>>E>>st;
    
}

/* 
0 1 2
0 2 3
1 2 -5
1 3 1
2 3 2

1 ≤ |V| ≤ 1000
0 ≤ |E| ≤ 2000
-10000 ≤ di ≤ 10000
There are no parallel edges
There are no self-loops

|V| |E| r
s0 t0 d0
s1 t1 d1
:
s|E|−1 t|E|−1 d|E|−1
 */