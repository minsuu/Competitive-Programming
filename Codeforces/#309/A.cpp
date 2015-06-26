// Jun 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5555;
const int MOD = 1e9+7;
int inv[MAXN], fact[MAXN], ifact[MAXN];
int mcomb(int a, int b){
    return fact[a] * 1LL * ifact[b] % MOD * ifact[a-b] % MOD;
}
int c[1111], N;
int main(){
	inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for (int i=2;i<MAXN;i++){
        inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
        fact[i]=(long long)fact[i-1]*i%MOD;
        ifact[i]=(long long)ifact[i-1]*inv[i]%MOD;
    }

	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&c[i]);
	
	int sum=0, ans = 1;
	for(int i=0;i<N;i++){
		ans = ans * 1LL * mcomb( c[i] + sum - 1, sum ) % MOD;
		sum += c[i];
	}
	printf("%d",ans);
	return 0;
}