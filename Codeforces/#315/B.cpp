// Aug 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MAXN = 4444;
const int MOD = 1e9+7;
int dp[MAXN], dp2[MAXN];
int N;
int main(){
	scanf("%d",&N);
	dp[0] = 1;
	for(int i=1; i<=N; i++){
		for(int j=N; j>=1; j--){
			dp[j] = ( dp[j] + dp[j-1] + (lld) dp[j] * j ) % MOD;
		}
	}

	dp2[1] = 1;
	for(int i=2; i<=N; i++){
		for(int j=N; j>=1; j--){
			dp2[j] = ( dp2[j-1] + (lld) dp2[j] * j ) % MOD;
		}
	}

	int ans = dp[0];
	for(int i=1; i<=N; i++){
		ans = ( ans + 0LL + dp[i] - dp2[i] + MOD ) % MOD;
	}
	printf("%d",ans);
	return 0;
} 