#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

lld gcd(lld a,lld b)
{
    if(a && b)
        while(a%=b^=a^=b^=a);
    return a+b;
}
struct R{
    lld a,b;
    R ( lld _a = 0, lld _b = 1 ) : a(_a), b(_b) { }
	bool operator<( const R& r ) const{
		return a*r.b < r.a*b;
	}
    R operator+(const R& r) const{
        lld g = gcd(b,r.b);
        return R(a*r.b/g + r.a*b/g , b/g*r.b).reduce();
    }
    R operator/(const int& r) const{
        return R(a, b*r).reduce();
    }
    R reduce(){
        lld g = gcd(a,b);
        assert( b/g != 0);
        return R(a/g, b/g);
    }
};
typedef pair<R,R> LINE;

int T,N;
lld a,b,c;
vector<LINE> lines;

int main(){
	scanf("%d",&T);
	while( T-- ){
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			scanf("%lld%lld%lld",&a,&b,&c);
			lines.push_back( LIN( R(-a,b), R(-c,b) ) );
		}
		sort( lines.begin(), lines.end() );
		for(int i=0; i<(int)lines.size(); i++) {
		

		}
	}
	return 0;
}
