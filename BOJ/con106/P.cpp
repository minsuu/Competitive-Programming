#include <bits/stdc++.h>
using namespace std;

const int MOD = 9901;
int N;
vector<int> dp(4), ndp(4);

int main(){
	scanf("%d",&N);
	dp[0] = 1;
	for(int i=1; i<=N; i++){
		vector<int>(4).swap(ndp);
		for(int j=0; j<4; j++){
			int a = j & 1, b = j & 2;
			ndp[0] += dp[j]; ndp[0] %= MOD;
			if( a == 0 ) ndp[1] += dp[j], ndp[1] %= MOD;
			if( b == 0 ) ndp[2] += dp[j], ndp[2] %= MOD;
		}
		ndp.swap(dp);
	}
	int ans = dp[0] + dp[1] + dp[2] + dp[3];
	ans %= MOD;
	printf("%d",ans);
	return 0;
}