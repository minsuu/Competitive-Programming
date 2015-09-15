#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int dp[11111], c[111], N,K;
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++)
		scanf("%d",&c[i]);

	dp[0] = 0;
	for(int i=1; i<=K; i++)
		dp[i] = INF;

	for(int i=0; i<N; i++){
		for(int j=K-c[i]; j>=0; j--){
			if( dp[j]==INF ) continue;
			int l = 1;
			for(int k=j+c[i]; k<=K; k+=c[i], l++)
				dp[k] = min( dp[k], dp[j] + l );
		}
	}
	if( dp[K] == INF ) printf("-1");
	else printf("%d",dp[K]);
	return 0;
}