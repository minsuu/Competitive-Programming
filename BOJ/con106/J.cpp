#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int N,K,a[22],b[22], ten[1111];
lld cache[ 1<<15 ][ 111 ];

lld dp( int st, int k ){
	if( st == (1<<N) - 1 ){
		return (k==0);
	}

	lld& ret = cache[st][k];
	if( ret != -1 ) return ret;

	int l = 0;
	for(int i=0; i<N; i++){
		if( (1<<i) & st ){
			l += b[i];
		}
	}
	int m = ten[l];

	ret = 0LL;
	for(int i=0; i<N; i++){
		if( !( (1<<i) & st ) ){
			ret += dp( st | (1<<i), ( k + m * 1LL * a[i] ) % K );
		}
	}
	return ret;
}

lld gcd(lld a,lld b)
{
    if(a && b)
        while(a%=b^=a^=b^=a);
    return a+b;
}

char buf[22][55];
int main(){
	memset( cache, -1, sizeof cache );

	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%s",buf[i]);
		b[i] = strlen( buf[i] );
	}
	scanf("%d",&K);

	ten[0] = 1;
	for(int i=1; i<1111; i++){
		ten[i] = ( ten[i-1] * 10 ) % K;
	}

	for(int i=0; i<N; i++){
		int m = 1, l = b[i];
		for(int j=l-1; j>=0; j--){
			a[i] = ( a[i] + (buf[i][j]-'0') * 1LL * m ) % K;
			m = (m*10) % K;
		}
	}

	lld mo = 1LL;
	for(int i=1; i<=N; i++) mo*=i;
	lld ja = dp(0,0);
	lld g = gcd(mo, ja);
	mo/=g, ja/=g;
	printf("%lld/%lld",ja,mo);
	return 0;
}