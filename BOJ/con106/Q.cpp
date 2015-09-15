#include <bits/stdc++.h>
using namespace std;
int board[111111][3];

vector<int> dp(3), ndp(3);
int N;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &board[i][j]);
		}
	}

	for(int i=N-1; i>=0; i--){
		ndp[0] = max( dp[0] , dp[1] ) + board[i][0];
		ndp[1] = max( dp[0] , max( dp[1], dp[2] ) ) + board[i][1];
		ndp[2] = max( dp[1] , dp[2] ) + board[i][2];
		ndp.swap( dp );
	}
	printf("%d ", max( dp[0], max( dp[1], dp[2] ) ) );

	vector<int>(3).swap(dp);	
	for(int i=N-1; i>=0; i--){
		ndp[0] = min( dp[0] , dp[1] ) + board[i][0];
		ndp[1] = min( dp[0] , min( dp[1], dp[2] ) ) + board[i][1];
		ndp[2] = min( dp[1] , dp[2] ) + board[i][2];
		ndp.swap( dp );
	}
	printf("%d", min( dp[0], min( dp[1], dp[2] ) ) );
	return 0;
}