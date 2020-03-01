#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

template <class type> class frac{
public:
    static type gcd(type a,type b){
        type c;
        while(1){
            if(b==0)return a;
            c=b,b=a%b,a=c;
        }
        return c;
    }
    static type lcm(type a,type b){
        return a*b/gcd(a,b);
    }
    type x,y;
    void norm(){assert(y!=0);type d=gcd(x,y);x/=d;y/=d;if(y<0)x=-x,y=-y;}
    frac<type> (){x=0;y=1;}
    frac<type> (ll x):x(x),y(1){}
    static frac<type> Frac(type x,type y){frac<type> c;c.x=x;c.y=y;c.norm();return c;}
    friend ostream &operator << (ostream &o,const frac<type> &b){
        if(b.y==1 || b.x==0)cout<<b.x;
        else o<<b.x<<"/"<<b.y;
        return o;
    }
    frac<type> operator + (const frac<type> &b)const{return Frac(x*b.y+b.x*y,y*b.y);}
    frac<type> operator - (const frac<type> &b)const{return Frac(x*b.y-b.x*y,y*b.y);}
    frac<type> operator * (const frac<type> &b)const{return Frac(x*b.x,y*b.y);}
    frac<type> operator / (const frac<type> &b)const{return Frac(x*b.y,b.x*y);}
    frac<type> &operator +=(const frac<type> &b){(*this)=(*this)+b;return *this;}
    frac<type> &operator -=(const frac<type> &b){(*this)=(*this)-b;return *this;}
    frac<type> &operator *=(const frac<type> &b){(*this)=(*this)*b;return *this;}
    frac<type> &operator /=(const frac<type> &b){(*this)=(*this)/b;return *this;}
    frac<type> operator -()const{frac<type> c{*this};c.x=-c.x;return c;}
    frac<type> &operator ++(){(*this)+=y;return *this;}
    frac<type> &operator --(){(*this)-=y;return *this;}
    bool operator ==(const frac<type> &b)const{return x==b.x && y==b.y;}
    bool operator !=(const frac<type> &b)const{return x!=b.x || y!=b.y;}
    bool operator < (const frac<type> &b)const{return x*b.y<y*b.x;}
    bool operator > (const frac<type> &b)const{return x*b.y>y*b.x;}
};

template <class type> class matrix{
public:
    ll n,m,r;
    type val[55][55];
    void resize(ll a,ll b){
        n=a;m=b;
        rep(i,0,n-1)rep(j,0,m-1)val[i][j]=0;
    }
    matrix(){}
    matrix(const initializer_list<initializer_list<type> > &b){
        n=0;
        for(auto i:b){
            m=0;
            for(auto j:i)val[n][m++]=j;
            n++;
        }
    }
    bool operator == (const matrix<type> &b)const{
        if(n!=b.n || m!=b.m)return false;
        rep(i,0,n-1)rep(j,0,m-1)if(val[i][j]!=b.val[i][j])return false;
        return true;
    }
    friend ostream &operator << (ostream& o,const matrix<type> &a){
        rep(i,0,a.n-1)rep(j,0,a.m-1)o<<a.val[i][j]<<" \n"[j==a.m-1];
        return o;
    }
    matrix<type> operator ()(ll u,ll d,ll l,ll r)const{
        matrix<type> b;
        b.n=d-u;b.m=r-l;
        rep(i,u,d-1)rep(j,l,r-1)b.val[i-u][j-l]=val[i][j];
        return b;
    }
    type &operator ()(ll h,ll l){
        return val[h][l];
    }
    static matrix<type> constant(ll h,ll l,type v){
        matrix<type> c;
        c.resize(h,l);
        rep(i,0,h-1)rep(j,0,l-1)c.val[i][j]=v;
        return c;
    }
    matrix<type> operator + (const matrix<type> &b)const{
        assert(n==b.n && m==b.m);
        matrix c;c.n=n;c.m=m;
        rep(i,0,n-1)rep(j,0,m-1)c.val[i][j]=val[i][j]+b.val[i][j];
        return c;
    }
    matrix<type> operator - (const matrix<type> &b)const{
        assert(n==b.n && m==b.m);
        matrix c;c.n=n;c.m=m;
        rep(i,0,n-1)rep(j,0,m-1)c.val[i][j]=val[i][j]-b.val[i][j];
        return c;
    }
    matrix<type> operator * (const matrix<type> &b)const{
        assert(m==b.n);
        matrix c;c.n=n;c.m=b.m;
        rep(i,0,c.n-1)rep(j,0,c.m-1)c.val[i][j]=0;
        rep(i,0,c.n-1)rep(k,0,m-1)if(val[i][k]!=0)rep(j,0,c.m-1)c.val[i][j]=c.val[i][j]+val[i][k]*b.val[k][j];
        return c;
    }
    matrix<type> operator * (const type &b)const{
        assert(m==b.n);
        matrix c;c.n=n;c.m=m;
        rep(i,0,n-1)rep(j,0,m-1)c.val[i][j]=val[i][j]*b;
        return c;
    }
    matrix<type> operator ^ (int b)const{
        assert(n==m);
        matrix a,c;c.n=c.m=n;a=*this;
        rep(i,0,n-1)rep(j,0,n-1)c.val[i][j]=i==j;
        while(b){if(b&1)c=c*a;a=a*a;b>>=1;}
        return c;
    }
    matrix<type> operator +=(const matrix<type> &b){(*this)=(*this)+b;return *this;}
    matrix<type> operator -=(const matrix<type> &b){(*this)=(*this)-b;return *this;}
    matrix<type> operator *=(const matrix<type> &b){(*this)=(*this)*b;return *this;}
    ll rank(){
        ll p=0;
        rep(i,0,n-1){
            while(1){
                if(val[i][p]!=0)break;
                rep(j,i+1,n-1)if(val[j][p]!=0){
                    rep(k,0,m-1)swap(val[i][k],val[j][k]);
                    break;
                }
                if(val[i][p]==0)p++;
                if(p==m-1){
                    r=i;
                    rep(j,i,n-1)if(val[j][m-1]!=0)r=-1;
                    return r;
                }
            }
            rep(k,p+1,m-1)val[i][k]/=val[i][p];
            val[i][p]=1;
            rep(j,i+1,n-1){
                rep(k,p+1,m-1)val[j][k]-=val[j][p]*val[i][k];
                val[j][p]=0;
            }
        }
        r=n;
        return r;
    }
    vector<type> solve(){
        vector<type> x;
        x.resize(m-1);
        ll p=m-2;
        for(ll i=r-1;i>=0;i--){
            ll l=0;
            for(ll j=m-2;j>=0;j--)if(val[i][j]!=0)l=j;
            while(p>l)x[p--]=1;
            x[p]=val[i][m-1];
            rep(k,p+1,m-2)x[p]-=x[k]*val[i][k];
            p--;
        }
        return x;
    }
    static matrix<type> eye(ll N){
        matrix<type> A;
        A.resize(N,N);
        rep(i,0,N-1)rep(j,0,N-1)A.val[i][j]=i==j;
        return A;
    }
    matrix<type> operator , (const matrix<type> &B)const{
        assert(n==B.n);
        matrix<type> C;
        C.n=n;C.m=m+B.m;
        rep(i,0,n-1)rep(j,0,m-1)C.val[i][j]=val[i][j];
        rep(i,0,B.n-1)rep(j,0,B.m-1)C.val[i][j+m]=B.val[i][j];
        return C;
    }
    matrix<type> reverse()const{
        matrix<type> B;
        B.resize(m,n);
        rep(i,0,n-1)rep(j,0,m-1)B.val[j][i]=val[i][j];
        return B;
    }
    matrix<type> inverse()const{
        assert(n==m);
        matrix<type> B=(*this,eye(n));
        type d;
        rep(i,0,n-1){
            ll k=-1;
            rep(j,i,n-1)if(B.val[j][i]!=0){k=j;break;}
            if(k==-1)return eye(n);
            else if(k!=i)rep(j,0,2*m-1)swap(B.val[i][j],B.val[k][j]);
            d=B.val[i][i];
            rep(j,0,2*m-1)B.val[i][j]/=d;
            rep(k,0,n-1)if(k!=i){
                d=B.val[k][i];
                rep(j,0,2*m-1)B.val[k][j]-=d*B.val[i][j];
            }
        }
        return B(0,n,n,2*n);
    }
};

class node{
public:
    vector< pair<string,ll> > data;
    ll index;
    void read_node(){
        data.clear();
        string name;
        ll p,num;
        cin>>p;
        while(p--){
            cin>>name>>num;
            data.emplace_back(pair<string,ll>{name,num});
        }
    }
}u;

matrix<frac<ll>> A;
vector<node> L,R;

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    ll n=0;
    while(1){
        cin>>s;
        if(s=="0")break;
        u.read_node();
        u.index=++n;
        if(s=="+1")L.emplace_back(u);
        else R.emplace_back(u);
    }
    /*for(auto i:R){
        for(auto j:i.data){
            cout<<j.first<<" "<<j.second<<"    ";
        }
        cout<<endl;
    }*/
    map<string,ll> mp;
    ll m=0;
    for(auto i:L)for(auto j:i.data){
        if(mp.find(j.first)==mp.end())mp[j.first]=++m;
    }
    A.resize(m,n+1);
    for(auto i:L)for(auto j:i.data){
        A.val[mp[j.first]-1][i.index-1]+=j.second;
    }
    for(auto i:R)for(auto j:i.data){
        A.val[mp[j.first]-1][i.index-1]-=j.second;
    }
    //cout<<A<<endl;
    A.rank();
    vector<frac<ll>> x=A.solve();
    ll d=1;
    for(auto i:x)d=frac<ll>::lcm(d,i.y);
    for(auto &i:x)i*=d;
    for(auto i:x)cout<<i<<" ";
    cout<<endl;
    return 0;
}
/*

*///