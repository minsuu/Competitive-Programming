// Jun 20 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD=1e9+7;
int N, inv[22], fact[22], ifact[22];
lld S, F[22], ans;
int main(){
    inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i=2;i<=20;i++){
        inv[i]=(lld)(MOD-MOD/i)*inv[MOD%i]%MOD;
        fact[i]=(lld)fact[i-1]*i%MOD;
        ifact[i]=(lld)ifact[i-1]*inv[i]%MOD;
    }

	scanf("%d%lld",&N,&S);
	for(int i=0;i<N;i++) scanf("%lld",&F[i]);
	for(int i=0;i<1<<N;i++){
		lld sum = 0LL; int m=0;
		for(int j=0;j<N;j++)
			if( 1<<j & i ) sum+=F[j]+1LL, m++;
		if( sum <= S ){
			lld k = S-sum, comb = 1LL;

			int a = (lld)(N+k-1)%MOD;
			for(int j=0; j<N-1; j++){
				comb *= ( a - j + MOD ) % MOD;
				comb %= MOD;
			}
			comb *= ifact[N-1]; comb %= MOD;

			if(m%2) ans -= comb;
			else ans += comb;
			ans %= MOD;
			if( ans<0 ) ans+=MOD;
		}
	}
	printf("%lld",ans);
	return 0;
} 