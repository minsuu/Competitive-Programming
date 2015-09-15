#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e6;
int dp[111][111][2];
int N;

int main(){
	scanf("%d",&N);
	if( N == 1 ){
		printf("1");
		return 0;
	}
	dp[1][1][0] = dp[1][1][1] = 1;
	for(int i=2; i<=N; i++){
		int ls = 0;
		for(int j=i-1; j>=1; j--){
			ls += dp[i-1][j][0];
			ls %= MOD;
			dp[i][j][1] += ls;
			dp[i][j][1] %= MOD;
		}
		int rs = 0;
		for(int j=2; j<=i; j++){
			rs += dp[i-1][j-1][1];
			rs %= MOD;
			dp[i][j][0] += rs;
			dp[i][j][0] %= MOD;
		}
	}
	int sum = 0;
	for(int i=1; i<=N; i++){
		sum += dp[N][i][0];
		sum %= MOD;
		sum += dp[N][i][1];
		sum %= MOD;
	}
	printf("%d",sum);
	return 0;
}