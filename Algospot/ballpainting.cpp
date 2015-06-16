#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MAXN = 1e3+10;
const int MOD = 1e9+7;
int N, dp[MAXN*2][MAXN];
int inv[MAXN*5], fact[MAXN*5], ifact[MAXN*5];
int main(){
	inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i=2;i<MAXN*5;i++){
        inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
        fact[i]=(long long)fact[i-1]*i%MOD;
        ifact[i]=(long long)ifact[i-1]*inv[i]%MOD;
    }
	dp[0][0] = 1;
	for(int i=1; i<MAXN*2; i++){
		for(int j=1; j<MAXN; j++){
			lld k = 2*j - i +1;
			dp[i][j] = ( dp[i-1][j] * k + dp[i-1][j-1] * 2LL ) % MOD;
		}
	}
	/* for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++)
			printf("%5d ",dp[i][j]); printf("\n"); } */
	while(1){
		scanf("%d",&N); if(N==0) break;
		if(N==1) { printf("2\n"); continue; }
		lld ans = 0;
		ans += dp[2*N][N] * 2LL % MOD;
		for(int i=2;i<N;i++){
			int ls = i, rs = N-i;
			ans += dp[ls*2][ls] * 1LL * dp[rs*2][rs] % MOD * fact[ls*2+rs*2-1] % MOD * ifact[ls*2-1] % MOD * ifact[rs*2] % MOD;
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}