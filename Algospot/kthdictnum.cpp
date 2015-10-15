// Oct 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long lld;
lld A,B;
lld pre(lld X, lld k){
	if( k == 0 ) return 0ULL;
	if( X == 0 ) return 1ULL;

    lld r = X/10, dig = 1ULL, ret = 0ULL;
    while( r ) r/=10, dig*=10;

    r = k;
    while( r < dig ) r*=10;
    while( r/10 >= dig ) r/=10;

    while( dig ){
        lld l = min( X, r );
        if( l >= k && l == r ) l--;
        ret += max( 0ULL, l - dig + 1 );
        dig /= 10; r /= 10;
    }
    return ret+1;
}
lld cal(lld k){
	if( A == 0 ) return pre(B,k);
	return pre(B, k) - pre(A-1, k);
}

int T;
lld k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%llu%llu%llu",&A,&B,&k);

		lld r = 0ULL;
		while( !(A<=r && r<=B) || cal(r) != k ){
			int d = 0; r*=10ULL;
			while( d<=9 && cal(r+d)<=k ) d++;
			r += d-1;
		}
		printf("%llu\n",r);
	}
	return 0;
}