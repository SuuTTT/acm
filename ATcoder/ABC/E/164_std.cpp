// <head>
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    const int INF = 1002003004;
    const ll LINF = 1002003004005006007ll;
    struct preprocess{preprocess()
    {cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}}____;
// </head>

// <library>
    
// </library>

struct Edge{
    ll to, a, b;
    Edge(ll to, ll a, ll b): to(to),a(a),b(b){}
};
const ll MAXV = 50;
const ll MAXS = MAXV * 50 + 5;
vector<Edge> g[MAXV];
ll dp[MAXV][MAXS+5];

struct Data{
    ll s,v,t;
    Data(ll v, ll s, ll t) : v(v),s(s),t(t) {}
    bool operator<(const Data& a) const {
        return t> a.t;
    }
};
int main(){
    ll n,m,s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++){
        int u,v,a,b;
        cin >> u >> v >> a >> b;
        u--; v--;
        g[u].emplace_back(v,a,b);
        g[v].emplace_back(u,a,b);
    }
    vector<ll> c(n), d(n);
    for (int i = 0; i < n; i++){
        cin >> c[i] >> d[i];
    }
    for (int i = 0; i < MAXV; i++){
        for (int j = 0; j < MAXS; j++){
            dp[i][j] = LINF;
        }
    }
    s = min(s, MAXS);

    priority_queue<Data> q;
    dp[0][s]= 0;
    q.emplace(0,s,0);
    while(!q.empty()){
        Data dt = q.top(); q.pop();
        if(dp[dt.v][dt.s]<dt.t) continue;
        if(dt.s<0) continue;

        // exchange
        ll ns = min(MAXS, dt.s+c[dt.v]);
        if (dp[dt.v][ns] > dt.t+d[dt.v]){
            dp[dt.v][ns] = dt.t+d[dt.v];
            q.emplace(dt.v, ns, dt.t+d[dt.v]);
        }

        // move to other station
        for (Edge e : g[dt.v]){
            if (dt.s-e.a >=0 && dp[e.to][dt.s-e.a] > dp[dt.v][dt.s] + e.b){
                dp[e.to][dt.s-e.a] = dp[dt.v][dt.s] + e.b;
                q.emplace(e.to,dt.s-e.a,dp[e.to][dt.s-e.a]);
            }
        }
    }
    for (int i = 1; i < n; i++){
        ll ans = LINF;
        for (int j = 0; j < MAXS; j++){
            ans = min(ans, dp[i][j]);
            
        }
        cout << ans << '\n';
        
    }
    
    
}
/* 

 */
