#include <bits/stdc++.h>
using namespace std;

int T,N,K, dp[222222][22];
pair<int,int> item[222222];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		for(int i=0; i<N; i++){
			scanf("%d%d",&item[i].first, &item[i].second );
		}
		sort( item, item+N );
		memset( dp, 0, sizeof dp );
		for(int k=0; k<=K; k++)
			for(int i=N-1; i>=0; i--){
				if( k ){
					dp[i][k] = max( dp[i+1][k], min( dp[i+1][k-1] - item[i].second, item[i].first - item[i].second ) );
				}else{
					dp[i][k] = max( dp[i+1][k], item[i].first - item[i].second );
				}
			}
		printf("%d\n",dp[0][K]);
	}
	return 0;
}