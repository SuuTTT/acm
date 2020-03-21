#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1001

ll POW[NUM];
ll nCm[NUM][NUM];
ll memo[NUM];

int main(){

	ll N,K;
	scanf("%lld %lld",&N,&K);

	if(N < K){
		printf("0\n");
		return 0;
	}

	//コンビネーション を求める
	nCm[0][0] = 1;
	for(int n = 1; n <= K; n++) {
		for (int k = 0; k <= N; k++) {
			if(k > 0){
				nCm[n][k] = nCm[n-1][k]+nCm[n-1][k-1];
			}else{ //k == 0
				nCm[n][k] = 1;
			}
			nCm[n][k] %= MOD;
		}
	}

	ll tmp;

	//num^Nを作っておく
	for(ll num = 1; num <= K; num++){
		tmp = 1;

		for(int i = 1; i <= N; i++){
			tmp *= num;
			tmp %= MOD;
		}
		POW[num] = tmp;
	}

	memo[1] = 1;
//减法
	for(ll num = 2; num <= K; num++){

		memo[num] = POW[num];

		for(int i = 1; i <= num-1; i++){
			memo[num] -= nCm[num][i]*memo[i];
			memo[num] %= MOD;
			if(memo[num] < 0)memo[num] += MOD;
		}
	}

	printf("%lld\n",memo[K]);

	return 0;
}
/* 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll dp[1001][1001];

int main(){
  ll n,k;
  cin>>n>>k;

  dp[0][0]=1;
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i][j]+=dp[i-1][j-1]*(k-j+1);
      dp[i][j]+=dp[i-1][j]*j;
      dp[i][j]%=mod;
    }
  }
  cout<<dp[n][k]<<endl;
  return 0;
}


 */