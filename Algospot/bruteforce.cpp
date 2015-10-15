#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

struct Solution { int gcd, x, y; };
Solution extendedEuclid(int a, int b) {
	int q = a / b, r = a % b;
	if(r == 0) return Solution{b, 0, 1};
	Solution s = extendedEuclid(b, r);
	return Solution{s.gcd, s.y, s.x - q * s.y};
}

int modpow( int a, int n ){
	int b = a, c = 1, r = 1;
	while( c <= n ){
		if( n & c ) r = ( r * 1LL * b ) % MOD;
		c<<=1; b = ( b * 1LL * b ) % MOD;
	}
	return r;
}

int T,A,B,N;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&A,&B,&N);
		if( N == 1 ){
			printf("%d\n",B-A+1);
		}else{
			int m = modpow(N,A) * 1LL * ( modpow(N,B-A+1) - 1 ) % MOD;
			int n = ( extendedEuclid(N-1,MOD).x + 0LL + MOD ) % MOD;
			m = ( m * 1LL * n ) % MOD;
			printf("%d\n",m);
		}
	}
	return 0;
}