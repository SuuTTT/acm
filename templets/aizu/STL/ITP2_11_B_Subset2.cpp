#include<iostream>
using namespace std;
int n;

//暴力枚举b的子集
void main3()
{
	cin>>n;
	int k,m=0;
	cin>>k;
	for(;k--;)
	{
		int b;cin>>b;m|=1<<b;
	}
	for(int i=0;i<1<<n;i++)
	{
		if(i&~m)continue;
		cout<<i<<":";
		for(int j=0;j<n;j++)if(i>>j&1)cout<<" "<<j;
		cout<<endl;
	}
}
//正常枚举子集
signed main33(){
  int n;
  cin>>n;
  int k;
  cin>>k;
  int c=0;
  for(int i=0;i<k;i++){
    int x;
    cin>>x;
    c|=1<<x;
  }
  for(int b=c;;b=(b-1)&c){
    int nb=c^b;
    cout<<nb<<":";
    for(int i=0;i<n;i++)
      if((nb>>i)&1) cout<<" "<<i;
    cout<<"\n";
    if(b==0) break;
  }
  cout<<flush;
  return 0;
}

//枚举包含b的集合
main()
{
	cin>>n;
	int k,m=0;
	cin>>k;
	for(;k--;)
	{
		int b;cin>>b;m|=1<<b;
	}
	for(int i=m;i<1<<n;i=i+1|m)
	{
		cout<<i<<":";
		for(int j=0;j<n;j++)if(i>>j&1)cout<<" "<<j;
		cout<<endl;
	}
}
//枚举combination
int main4()
{
    int n,k;
    cin>>n>>k;

    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)!=k) continue;
        cout<<i<<":";
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1) cout<<" "<<j;
        }
        cout<<endl;
    }


    return 0;
}



