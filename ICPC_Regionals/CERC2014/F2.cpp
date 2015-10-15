#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+9;
const int MAXL = 1111111;

char A[MAXL], B[MAXL], C[MAXL];
int T,L;

long long a[MAXL], b[MAXL], c[MAXL], ab[MAXL], bc[MAXL], abc[MAXL];

inline int GR( const char& a, const char& b ) {
	if( a == '?' && b == '?' ) return 26*25/2;
	if( b == 'A' ) return 0LL;
	if( a == 'A' ) return ( b=='?' )? 26 : 1;
	if( a == '?' ) return b - 'a';
	if( b == '?' ) return 'z' - a;
	return ( a < b );
}
inline int EQ( const char& a, const char& b ){
	if( a == '?' && b == '?' ) return 26;
	if( b == 'A' ) return ( a == 'A' );
	if( a == 'A' ) return 0;
	return ( a==b ) || ( a=='?') || (b=='?');
}
inline int GRGR( const char& a, const char& b, const char& c ){
	if( c == 'A' || b == 'A' ) return 0;
	if( a == 'A' ) return GR(b,c);
	if( a == '?' && b == '?' && c == '?' ) return 26*25*24/6;
	if( a == '?' && b == '?' ) return max( 0, (c-'a')*(c-'a'-1)/2 );
	if( a == '?' && c == '?' ) return ( b - 'a' ) * ( 'z' - b );
	if( b == '?' && c == '?' ) return max( 0, ('z'-a)*('z'-a-1)/2 );
	if( a == '?' ) return (b<c)*(b-'a');
	if( b == '?' ) return (a<c)*(c - a - 1);
	if( c == '?' ) return (a<b)*('z'-b);
	return ( a < b ) && ( b < c );
}
inline int EQGR( const char& a, const char& b, const char& c ){
	if( c == 'A' ) return 0;
	if( b == 'A' ) return ( a == 'A' ) * GR( b,c );
	if( a == 'A' ) return 0;
	if( a == '?' && b == '?' && c == '?' ) return 26*25/2;
	if( a == '?' && b == '?' ) return ( c - 'a' );
	if( a == '?' && c == '?' ) return ( 'z' - b );
	if( b == '?' && c == '?' ) return ( 'z' - a );
	if( a == '?' ) return (b<c);
	if( b == '?' ) return (a<c);
	if( c == '?' ) return (a==b)*('z'-b);
	return ( a == b ) && ( b < c );	
}
inline int GREQ( const char& a, const char& b, const char& c ){
	if( c == 'A' ) return 0;
	if( b == 'A' ) return 0;
	if( a == 'A' ) return ( b != 'A' ) * EQ( b,c );
	if( a == '?' && b == '?' && c == '?' ) return 26*25/2;
	if( a == '?' && b == '?' ) return ( c - 'a' );
	if( a == '?' && c == '?' ) return ( b - 'a' );
	if( b == '?' && c == '?' ) return ( 'z' - a );
	if( a == '?' ) return (b==c)*(b-'a');
	if( b == '?' ) return (a<c);
	if( c == '?' ) return (a<b);
	return ( a < b ) && ( b == c );	
}
inline int EQEQ( const char& a, const char& b, const char& c ){
	if( a == 'A' || b == 'A' || c == 'A' ) return 0;
	if( a == '?' && b == '?' && c == '?' ) return 26;
	if( a == '?' && b == '?' ) return 1;
	if( a == '?' && c == '?' ) return 1;
	if( b == '?' && c == '?' ) return 1;
	if( a == '?' ) return (b==c);
	if( b == '?' ) return (a==c);
	if( c == '?' ) return (a==b);
	return ( a == b ) && ( b == c );	
}

int vv(int nn){
	if( nn == 0 ) return 0;
	return vv(nn-1);
}

int main(){
	scanf("%d",&T);
	while(T--){
		memset( A, 0, sizeof A ); memset( B, 0, sizeof B ); memset( C, 0, sizeof C );
		memset( ab, 0, sizeof ab ); memset( bc, 0, sizeof bc ); memset( abc, 0, sizeof abc );
		
		scanf("%s%s%s",A,B,C);
		int as = strlen(A), bs = strlen(B), cs = strlen(C); L = max( as, max( bs, cs ) );
		a[L] = b[L] = c[L] = 1LL;
		for(int i = L-1; i>=0; i-- ){
			a[i] = ( A[i] == '?' ) ? 26LL*a[i+1]%MOD : a[i+1];
			b[i] = ( B[i] == '?' ) ? 26LL*b[i+1]%MOD : b[i+1];
			c[i] = ( C[i] == '?' ) ? 26LL*c[i+1]%MOD : c[i+1];
			if( i >= as ) A[i] = 'A';
			if( i >= bs ) B[i] = 'A';
			if( i >= cs ) C[i] = 'A';
		}
		ab[L] = bc[L] = 0LL;
		for(int i = L-1; i>=0; i-- ){
			ab[i] = EQ(A[i], B[i]) * ab[i+1] % MOD
					+ GR(A[i], B[i]) * a[i+1] % MOD * b[i+1] % MOD;
			ab[i]%=MOD;

			bc[i] = EQ(B[i], C[i]) * bc[i+1] % MOD
					+ GR(B[i], C[i]) * b[i+1] % MOD * c[i+1] % MOD;
			bc[i]%=MOD;
		}
		abc[L] = 0LL;
		long long ans = 0LL, mul = 1;
		for(int i = 0; i<L; i++ ){
			ans +=( EQGR( A[i], B[i], C[i] ) * ab[i+1] % MOD * c[i+1] % MOD
					+GREQ( A[i], B[i], C[i] ) * a[i+1] % MOD * bc[i+1] % MOD
					+GRGR( A[i], B[i], C[i] ) * a[i+1] % MOD * b[i+1] % MOD * c[i+1] % MOD ) % MOD * mul % MOD;
			ans %= MOD;
			mul = mul * EQEQ( A[i], B[i], C[i] ) % MOD;
			if( mul == 0 ) break;
		}
		printf("%lld %d\n",abc[0],vv(L));
	}
	return 0;
}