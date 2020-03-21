#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
//N^4的dp，折半变为N^2logN

#define NUM 1005

enum Type{
	A,
	B,
	C,
	D,
};

int N;
ll V;
ll input[NUM][4];
//Type type_array[4] = {A,B,C,D};
map<ll,ll> AB,CD;

int main(){

	scanf("%d %lld",&N,&V);
    
	for(int i = 0; i < 4; i++){
		for(int k = 0; k < N; k++){
			scanf("%lld",&input[k][i]);
		} 
	}

	//AとBの組合わせ
	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
			AB[input[i][A]+input[k][B]]++;
		}
	}

	//CとDの組合せ
	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
			CD[input[i][C]+input[k][D]]++;
		}
	}

	ll ans = 0;
	map<ll,ll>::iterator it = AB.begin();

	ll num_AB,num_CD;

	while (it != AB.end()){
	   num_AB = it->first;
	   num_CD = V-num_AB;
	   ans += AB[num_AB]*CD[num_CD];
	   it++;
	}

	printf("%lld\n",ans);

	return 0;
}

 