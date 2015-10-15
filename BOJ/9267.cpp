#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

lld gcd(lld a,lld b)
{
    if(a && b)
        while(a%=b^=a^=b^=a);
    return a+b;
}

struct Solution { lld gcd, x, y; };
Solution extendedEuclid(lld a, lld b) {
	lld q = a / b, r = a % b;
	if(r == 0) return Solution{b, 0, 1};
	Solution s = extendedEuclid(b, r);
	return Solution{s.gcd, s.y, s.x - q * s.y};
}

lld A,B,S,g;
int main(){
	scanf("%lld%lld%lld",&A,&B,&S);
	if( S == A || S == B ) { printf("YES"); return 0; }
	if( S == 0 ) { printf("NO"); return 0; }
	if( A == 0 && B == 0 ) { printf("NO"); return 0 ;}
	if( A == 0 ) A = B;
	if( B == 0 ) B = A;

	g = gcd(A,B);
	if( S % g ){
		printf("NO");
	}else{
		A /= g, B /= g, S /= g;
		Solution s = extendedEuclid( A, B );
		lld x = s.x * S, y = s.y * S;
		if( y < x ){
			swap( x,y ); swap( A, B );
		}
		bool tr = false;
		lld a = ( -x + B - 1 ) / B, b = y / A;
		printf("%lld %lld\n",s.x,s.y);
		for( lld k = a; k <= b && !tr; k++){
			lld m = x + k * B, n = y - k * A;
			assert( A*g*m + B*g*n == S*g );
			printf("%lld * %lld + %lld * %lld\n",A*g, m, B*g, n, S);
			if( m>=1 && n>=1 && gcd(m,n) == 1 ) tr = true;		
		}
		if( tr ) printf("YES");
		else printf("NO");
	}
	return 0;
}
