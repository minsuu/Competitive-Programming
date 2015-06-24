// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1111111;
int sieve[MAXN], phi[MAXN]; long long phisum[MAXN];
int main(){
	for(int i=2; i*i<MAXN; i++){
		if( sieve[i] != 0 ) continue;
		for(int j=i; j<MAXN; j+=i)
			sieve[j] = i;
	} phi[1] = 1;
	// phi(x^p) = (x-1)*x^(p-1) : http://oeis.org/A000010
	for(int i=2; i<MAXN; i++){
		if( sieve[i] == 0 ) phi[i] = i-1, sieve[i] = i;
		else{
			int x = sieve[i], j = i/x, p = 1;
			while( j%x == 0 ) j/=x, p*=x;
			phi[i] = phi[j] * (x-1) * p;
		}
	}
	// phisum(x) = sum{d|n} d*phi(d) : http://oeis.org/A057660
	for(int i=1; i<MAXN; i++)
		for(int j=i; j<MAXN; j+=i)
			phisum[j] += i * 1LL * phi[i];
	int N=0,T;
	scanf("%d",&T);
	// sum{k=1..n} LCM(n,k) = n*(1+phisum(n))/2 : http://oeis.org/A051193
	while(T--){
		scanf("%d",&N);
		printf("%lld\n", N*(1+phisum[N])/2 );
	}
	return 0;
}