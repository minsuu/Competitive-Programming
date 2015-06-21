// Jun 21 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m, adj[22][22], minr[22];
int dp[1<<20], group[22][33], cost[22][33], maxi[22][33];
char str[22][22];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	for(int i=0;i<n;i++){
		minr[i] = INF;
		for(int j=0;j<m;j++){
			scanf("%d",&adj[i][j]);
			minr[i] = min( minr[i], adj[i][j] );
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int c = str[j][i]-'a';
			group[i][c] |= (1<<j);
			cost[i][c] += adj[j][i];
			maxi[i][c] = max(maxi[i][c], adj[j][i]);
		}
		for(int j=0;j<33;j++){
			cost[i][j] -= maxi[i][j];
		}
	}
	for(int i=1;i<1<<n;i++){
		int ctz = __builtin_ctz(i);
		dp[i] = dp[i & ~(1<<ctz)] + minr[ctz];
		for(int j=0;j<m;j++){
			int c = str[ctz][j]-'a';
			dp[i] = min(dp[i], dp[i & ~(group[j][c]) ] + cost[j][c] );
		}
	}
	printf("%d",dp[(1<<n)-1]);
	return 0;
} 