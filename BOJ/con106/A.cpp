#include <bits/stdc++.h>
using namespace std;
int N, dp[111][11];
const int MOD = 1e9;
int main(){
	scanf("%d",&N);
	for(int i=1; i<10; i++)
		dp[0][i] = 1;

	for(int i=1; i<N; i++){
		dp[i][0] = dp[i-1][1];
		for(int j=1; j<9; j++){
			dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) % MOD;
		}
		dp[i][9] = dp[i-1][8];
	}
	
	int sum = 0;
	for(int i=0; i<10; i++)
		sum = ( sum + dp[N-1][i] ) % MOD;
	printf("%d",sum);
	return 0;
}