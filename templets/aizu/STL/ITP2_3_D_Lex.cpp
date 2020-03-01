    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
    #define debug(x) cerr<<#x<<":"<<x<<endl
    const int maxn=(int)1e6+5;
    int main(){
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n1,n2;
        vector<int> v1,v2;
        cin>>n1;
        rep(i,1,n1){int x;cin>>x; v1.push_back(x);}
        cin>>n2;
        rep(i,1,n2){int x;cin>>x; v2.push_back(x);}
        cout<<lexicographical_compare(v1.begin(),v1.end(),v2.begin(),v2.end())<<endl;
    }