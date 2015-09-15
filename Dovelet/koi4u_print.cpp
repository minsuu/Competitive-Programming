// Aug 27 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int M,N, a[2222], b[2222], l[2222][2222], pre[2222][2222], post[2222][2222];
int main(){
	scanf("%d%d",&M,&N);
	for(int i=0; i<N; i++)
		scanf("%d",&a[i]);

	int dp[2222];
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++ ){
			int nl = (j ? l[i][j-1] : -1) + 1 + a[i-j];
			if( nl > M ) break;
			l[i][j] = nl; b[i] = j+1;
			if( j == i ) { dp[j] = 0; continue; }
			int k = lower_bound( l[i-j-1], l[i-j-1]+b[i-j-1], nl ) - l[i-j-1] - 1;
			dp[j] = INF;
			if( k>=0 ) dp[j] = min( dp[j], pre[i-j-1][k] + nl );
			if( k+1<b[i-j-1] ) dp[j] = min( dp[j], post[i-j-1][k+1] - nl );
		}
		for(int j=0; j<b[i]; j++){
			pre[i][j] = min( (j? (pre[i][j-1]) : INF), dp[j] - l[i][j] );
			post[i][b[i]-j-1] = min( (j? (post[i][b[i]-j]) : INF), dp[b[i]-j-1] + l[i][b[i]-j-1] );
		}
	}
	int ans = INF;
	for(int i=0; i<b[N-1]; i++)
		ans = min(ans, dp[i]);
	printf("%d\n",ans);
	return 0;
}