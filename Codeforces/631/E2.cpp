#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
lld gcd( lld a, lld b ){
	while( a != 0 && b != 0 ){
		lld r = a%b; a=b; b=r;
	} return a+b;
}
struct frac{
	lld p, q;
	frac( lld p = 0, lld q = 1 ) : p(p), q(q) {}
	frac norm() {
		lld g = gcd(p,q);
		if(q/g<0) return frac(-p/g, -q/g);
		return frac(p/g, q/g);
	}
	bool operator<=(const frac& r ) const{
		return (*this)<r || ( p == r.p && q == r.q );
	}
	bool operator<( const frac& r ) const{
		return (double) p * r.q < (double) q * r.p;
	}
	frac operator+( const frac& r ){
		return frac( p * r.q + q * r.p, q * r.q );
	}
};

// find the maximal value of given linear furnctions
struct ConvexOpt{
	const frac INF = frac( -987654321987654321LL, 1LL );
	typedef pair<lld,lld> Line;
	map< Line, frac > A; map< frac, Line > B;
	frac cross( Line x, Line y ) { return frac( y.second - x.second, x.first - y.first ).norm(); }
	bool chk( Line x, Line y, Line p ){
		return cross( x, p ) <= cross( x, y );
	}
	lld eval( Line l, lld x ) { return l.first * x + l.second; }
	void add( Line x ){
		if( A.count(x) ) return;
		auto it = A.insert( { x, frac(0,1) } ).first;
		if( it != A.begin() ){
			auto jt = it, kt = it; --jt; ++kt;
			if( kt != A.end() && chk( (*jt).first, (*it).first, (*kt).first ) ){
				A.erase( it );
				return;
			}
		}
		while( it != A.begin() && (--it) != A.begin() ){
			auto jt = it, kt = it; --jt; ++kt;
			if( chk( (*jt).first, (*it).first, (*kt).first ) ){
				B.erase( (*it).second );
				A.erase( it );
			}else{
				break;
			}
			it = A.find( x );
		}
		it = A.find( x );
		while( it != A.end() && (++it) != A.end() ){
			auto jt = it, kt = it; --jt; ++kt;
			if( kt != A.end() && chk( (*jt).first, (*it).first, (*kt).first ) ){
				B.erase( (*it).second );
				A.erase( it );
			}else{
				break;
			}
			it = A.find( x );
		}
		it = A.find( x );
		if( (++it) != A.end() ){
			auto jt = it; --jt;
			B.erase( (*it).second );
			(*it).second = cross( (*jt).first, (*it).first );	
			B[ (*it).second ] = (*it).first;
		}
		it = A.find( x );
		if( it == A.begin() ){
			(*it).second = INF;
			B[INF] = (*it).first;
		}else{
			auto jt = it; --jt;
			(*it).second = cross( (*jt).first, (*it).first );
			B[ (*it).second ] = (*it).first;
		}
	}
	lld query( lld x ){
		auto it = B.lower_bound( frac(x,1) );
		assert( it != B.begin() ); --it;
		return eval( (*it).second, x );
	}
	void print(){
		for( auto it : A ){
			printf("%lld %lld : %lld/%lld\n", it.first.first, it.first.second, it.second.p, it.second.q );
		}
		for( auto it : B ){
			printf("%lld/%lld : %lld %lld\n", it.first.p, it.first.q, it.second.first, it.second.second );
		}
	}
};

int N;
lld a[100100], b[100100], c[100100];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%lld",&a[i]);
	for(int i=0; i<N; i++) scanf("%lld",&b[i]);

	ConvexOpt co; co.add( { -b[0], -c[0] } );
	for(int i=1; i<N; i++){
		c[i] = co.query( a[i] );
		co.add( { -b[i], c[i] } );
	}
	printf("%lld",-c[N-1]);
	return 0;
}
