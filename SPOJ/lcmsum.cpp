// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1111111;
int sieve[MAXN], phi[MAXN];
struct divEnum{
	int f[111], a[111], b[111], fn;
	divEnum(int n){
		fn = 0; int last = -1, c=0;
		memset( a, 0, sizeof a ); memset( b, 0, sizeof b );
		while( n!=1 && ++c!=100){
			if( last != sieve[n] ) f[fn++] = last = sieve[n];
			a[fn-1]++; n /= sieve[n];
		}
	}
	divEnum operator++(){
		b[0]++;
		for(int i=0; i<fn; i++)
			if( b[i] == a[i]+1 ) b[i]=0, b[i+1]++;
		return *this;
	}
	operator int(){
		int ret = 1;
		for(int i=0; i<fn; i++)
			ret *= pow( f[i], b[i] );
		return ret;
	}
	bool end(){
		return b[fn]!=0;
	}
};
int main(){
	for(int i=2; i*i<MAXN; i++){
		if( sieve[i] != 0 ) continue;
		for(int j=i; j<MAXN; j+=i)
			sieve[j] = i;
	} phi[1] = 1;
	// phi(x^p) = (x-1)*x^(p-1)
	for(int i=2; i<MAXN; i++){
		if( sieve[i] == 0 ) phi[i] = i-1;
		else{
			int x = sieve[i], j = i/x, p = 1;
			while( j%x == 0 ) j/=x, p*=x;
			phi[i] = phi[j] * (x-1) * p;
		}
	}
	for(divEnum d(100); !d.end(); ++d )
		printf("%d ",(int)d);
	return 0;
}