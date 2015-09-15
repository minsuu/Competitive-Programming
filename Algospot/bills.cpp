// Sep 08 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int C,N,K;
int dp[10001];
int main(){
	scanf("%d",&C);
	while( C-- ){
		scanf("%d%d",&N,&K);
		int k = K, m = 10000;
		while( k%2==0 && m%2==0 ) k/=2, m/=2;
		while( k%5==0 && m%5==0 ) k/=5, m/=5;
		int ans = ( (N/m)*m ) * K; N%=m;
		
		int msum = 0;
		for(int i=0; i<=N; i++){
			msum = max( msum, (K*i/10000)*10000 + (int) ( 0.9 * K*(N-i) ) );
		}
		printf("%d\n", ans + msum );
	}
	return 0;
}