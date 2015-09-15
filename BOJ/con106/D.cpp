#include <bits/stdc++.h>
using namespace std;
int dp[11111], c[111], N,K;
int main(){
	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++)
		scanf("%d",&c[i]);
	dp[0] = 1;
	for(int i=0; i<N; i++){
		int kk = K/c[i]; kk*=c[i];
		for(int j=K-c[i]; j>=0; j--){
			if( dp[j]==0 ) continue;
			for(int k=j+c[i]; k<=K; k+=c[i])
				dp[k] += dp[j];
		}
	}
	printf("%d",dp[K]);
	return 0;
}