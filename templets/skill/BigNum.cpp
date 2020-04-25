#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
using namespace std;
typedef long long ll;

const ll W=9,B=(ll)pow(10,W);
void norm(vector<ll> &a){
    ll last=0;
    rep(i,0,(ll)a.size()-1){
        a[i]+=last;
        if(a[i]<0)last=-1,a[i]+=B;
        else last=a[i]/B,a[i]%=B;
    }
    while(last>0)a.push_back(last%B),last/=B;
    while(a.size()>0 && a.back()==0)a.pop_back();
}
vector<ll> pls(const vector<ll> &a,const vector<ll> &b){
    vector<ll> c=a;
    c.resize(max(a.size(),b.size()));
    rep(i,0,(ll)b.size()-1)c[i]+=b[i];
    norm(c);
    return c;
}
vector<ll> mns(const vector<ll> &a,const vector<ll> &b){
    vector<ll> c=a;
    rep(i,0,(ll)b.size()-1)c[i]-=b[i];
    norm(c);
    return c;
}
ll cmp(const vector<ll> &a,const vector<ll> &b){
    if(a.size()!=b.size())return a.size()>b.size()?1:-1;
    for(ll i=(ll)a.size()-1;i>=0;i--)if(a[i]!=b[i])return a[i]>b[i]?1:-1;
    return 0;
}
vector<ll> x_mul(const vector<ll> &a,const vector<ll> &b){
    vector<ll> c(a.size()+b.size()+1,0);
    rep(i,0,(ll)a.size()-1){
        rep(j,0,(ll)b.size()-1){
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/B;
            c[i+j]%=B;
        }
    }
    while(c.size()>0 && c.back()==0)c.pop_back();
    return c;
}
vector<ll> low(const vector<ll> &a,ll shift){
    return vector<ll>(a.begin(),a.begin()+shift);
}
vector<ll> high(const vector<ll> &a,ll shift){
    return vector<ll>(a.begin()+shift,a.end());
}
vector<ll> k_mul(const vector<ll> &a,const vector<ll> &b){
    if(a.size()<70 || b.size()<70)return x_mul(a,b);
    ll shift=max(a.size(),b.size())>>1;
    vector<ll> al=low(a,shift),ah=high(a,shift),bl=low(b,shift),bh=high(b,shift);
    vector<ll> z0=k_mul(al,bl),z2=k_mul(ah,bh),z1=mns(k_mul(pls(al,ah),pls(bl,bh)),pls(z0,z2));
    z0.resize(max((ll)z0.size(),max((ll)z2.size()+shift*2,(ll)z1.size()+shift)));
    rep(i,0,(ll)z1.size()-1)z0[i+shift]+=z1[i];
    rep(i,0,(ll)z2.size()-1)z0[i+shift*2]+=z2[i];
    norm(z0);
    return z0;
}
vector<ll> inv(const vector<ll> &a,ll w){
    vector<ll> two(w+1,0),ni(w-a.size()-1,0),last=ni;
    two.back()=2;
    ni.back()=1;
    while(1){
        ni=k_mul(ni,mns(two,k_mul(a,ni)));
        if(ni.size()>=w)ni=vector<ll>(ni.begin()+w,ni.end());
        else ni.clear();
        if(last.size()==ni.size()){
            ll flag=-1;
            for(ll i=(ll)ni.size()-1;i>=0;i--)if(last[i]!=ni[i]){flag=i;break;}
            if(flag==-1)break;
        }
        last=ni;
    }
    return ni;
}
void print(const vector<ll> &a){
    rep(i,0,(ll)a.size()-1)cout<<" "<<a[i];
    cout<<endl;
}
vector<ll> div(const vector<ll> &a,const vector<ll> &b){
    assert(b.size()!=0);
    ll w=a.size()+b.size()+2;
    vector<ll> c=k_mul(a,inv(b,w));
    if(c.size()>=w)c=vector<ll>(c.begin()+w,c.end());
    else c.clear();
    vector<ll> res=mns(a,k_mul(b,c));
    while(cmp(res,b)!=-1){
        res=mns(res,b);
        if(c.size()==0)c.push_back(1);
        else c[0]++,norm(c);
    }
    return c;
}
vector<ll> mod(const vector<ll> &a,const vector<ll> &b){
    return mns(a,k_mul(div(a,b),b));
}

class ubigint{
public:
    #define ed(a) ((ll)a.size()-1)
    vector<ll> a;
    ubigint(){}
    ubigint(vector<ll> x):a(x){}
    ubigint(ll x){
        a.clear();
        while(x>0)a.push_back(x%B),x/=B;
    }
    ubigint(const string &s){
        a.clear();
        ll w=1,b=1,num=0;
        for(ll i=ed(s);i>=0;i--,w++){
            num+=b*(s[i]-'0');
            b*=10;
            if(w==W || i==0)a.push_back(num),w=0,b=1,num=0;
        }
        while(a.size()>0 && a.back()==0)a.pop_back();
    }
    friend istream &operator >> (istream &in,ubigint &a){
        static string s;
        in>>s;
        a=s;
        return in;
    }
    friend ostream &operator << (ostream &o,const ubigint &b){
        if(b.a.size()==0)o<<"0";
        else{
            o<<*(b.a.end()-1);
            for(ll i=ed(b.a)-1;i>=0;i--)o<<setfill('0')<<setw(W)<<b.a[i];
        }
        return o;
    }
    bool operator < (const ubigint &b)const{return cmp(a,b.a)==-1;}
    bool operator > (const ubigint &b)const{return cmp(a,b.a)==1;}
    bool operator ==(const ubigint &b)const{return cmp(a,b.a)==0;}
    bool operator !=(const ubigint &b)const{return cmp(a,b.a)!=0;}
    bool operator <=(const ubigint &b)const{return cmp(a,b.a)!=1;}
    bool operator >=(const ubigint &b)const{return cmp(a,b.a)!=-1;}
    ubigint operator + (const ubigint &b)const{return ubigint(pls(a,b.a));}
    ubigint operator - (const ubigint &b)const{return ubigint(mns(a,b.a));}
    ubigint operator * (const ubigint &b)const{return ubigint(k_mul(a,b.a));}
    ubigint operator / (const ubigint &b)const{return ubigint(div(a,b.a));}
    ubigint operator % (const ubigint &b)const{return ubigint(mod(a,b.a));}
    ubigint &operator +=(const ubigint &b){a=pls(a,b.a);return *this;}
    ubigint &operator -=(const ubigint &b){a=mns(a,b.a);return *this;}
    ubigint &operator *=(const ubigint &b){a=k_mul(a,b.a);return *this;}
    ubigint &operator /=(const ubigint &b){a=div(a,b.a);return *this;}
    ubigint &operator %=(const ubigint &b){a=mod(a,b.a);return *this;}
    ubigint &operator ++(){
        if(a.size()==0)a.push_back(0);
        else a[0]++,norm(a);
        return *this;
    }
    ubigint &operator --(){
        a[0]--,norm(a);
        return *this;
    }
};
class bigint{
public:
    ubigint val;
    bool sig;
    bigint(){sig=1;}
    bigint(ll x){
        sig=x>=0;
        val=x>0?x:-x;
    }
    bigint(string s){
        if(s[0]=='-')sig=0,s.erase(s.begin());
        else sig=1;
        val=s;
    }
    friend istream &operator >> (istream &in,bigint &a){
        string s;
        in>>s;
        a=s;
        return in;
    }
    friend ostream &operator << (ostream &o,const bigint &b){
        if(!b.sig)o<<"-";
        o<<b.val;
        return o;
    }
    bigint &operator +=(const bigint &b){
        if(!(sig^b.sig)){
            val+=b.val;
        }
        else if(sig && !b.sig){
            if(val<b.val)sig=0,val=b.val-val;
            else sig=1,val-=b.val;
        }
        else{
            if(b.val<val)sig=0,val-=b.val;
            else sig=1,val=b.val-val;
        }
        return *this;
    }
    bigint &operator -=(const bigint &b){
        bigint c=b;
        c.sig^=1;
        (*this)+=c;
        return *this;
    }
    bigint &operator *=(const bigint &b){
        if(val.a.size()==0 || b.val.a.size()==0)sig=1,val.a.clear();
        else sig=!(sig^b.sig),val*=b.val;
        return *this;
    }
    bigint &operator /=(const bigint &b){
        assert(b.val.a.size()>0);
        if(val.a.size()==0)sig=1,val.a.clear();
        else sig=!(sig^b.sig),val/=b.val;
        return *this;
    }
    bigint &operator %=(const bigint &b){
        assert(b.val.a.size()>0);
        val%=b.val;
        if(val.a.size()==0)sig=1;
        return *this;
    }
    bigint &operator++(){
        if(sig)++val;
        else{
            --val;
            if(val.a.size()==0)sig=1;
        }
        return *this;
    }
    bigint &operator--(){
        if(!sig)++val;
        else if(val.a.size()==0)sig=0,val=1;
        else --val;
        return *this;
    }
    bigint operator -()const{bigint c{*this};c.sig^=1;return c;}
    bigint operator + (const bigint &b)const{bigint c{*this};return c+=b;}
    bigint operator - (const bigint &b)const{bigint c{*this};return c-=b;}
    bigint operator * (const bigint &b)const{bigint c{*this};return c*=b;}
    bigint operator / (const bigint &b)const{bigint c{*this};return c/=b;}
    bigint operator % (const bigint &b)const{bigint c{*this};return c%=b;}
    bool operator < (const bigint &b)const{
        if(sig^b.sig)return sig<b.sig;
        else if(sig)return val<b.val;
        else return b.val<val;
    }
    bool operator ==(const bigint &b)const{
        return sig==b.sig && val==b.val;
    }
    bool operator !=(const bigint &b)const{return !(*this==b);}
    bool operator > (const bigint &b)const{return b<(*this);}
};
ll char2int(char c){
    if(c>='0' and c<='9')return c-'0';
    else return c-'a'+10;
}
char int2char(ll x){
    if(x>=0 and x<=9)return x+'0';
    else if(x>=10 and x<=35)return x-10+'a';
    else return '0';
}
bigint translate(string s,ll base){
    bigint x=0;
    for(auto c:s){
        ll now=char2int(c);
        if((base!=1 and now>=base) or (base==1 and now!=1))return bigint(-1);
        x=x*base+now;
    }
    return x;
}
string a,b,c,op,temp;
bigint maxn=(1ll<<32)-1;
void solve(){
    string ans="";
    rep(base,1,36){
        bigint x=translate(a,base),y=translate(b,base),z=translate(c,base);
        if(x==-1 or y==-1 or z==-1 or x>maxn or y>maxn or z>maxn)continue;
        if(op=="+"){
            if(x+y==z)ans+=int2char(base);
        }else if(op=="-"){
            if(x-y==z)ans+=int2char(base);
        }else if(op=="*"){
            if(x*y==z)ans+=int2char(base);
        }else if(op=="/"){
            if(x==y*z)ans+=int2char(base);
        }
    }
    if(ans=="")cout<<"invalid"<<endl;
    else cout<<ans<<endl;
}

int main(){
#ifdef ATPLAB
freopen("local_input.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        cin>>a>>op>>b>>temp>>c;
        solve();
    }
    return 0;
}
/*

*///