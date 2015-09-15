#include <bits/stdc++.h>
using namespace std;

int T,N; long long dp[111];
int main(){
	scanf("%d",&T);
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for(int j=6; j<111; j++){
		dp[j] = dp[j-1] + dp[j-5];
	}
	while(T--){
		scanf("%d",&N);
		printf("%lld\n",dp[N]);
	}
	return 0;
}