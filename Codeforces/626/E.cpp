#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

lld gcd( lld a, lld b ){
	while( a!=0 && b!=0 ){
		lld r = a%b; a=b; b=r;
	}
	return a+b;
}
struct FR{
	lld a,b;
	FR( lld a = 0 , lld b = 1 ) : a(a), b(b) {}
	FR norm() const{
		lld g = gcd(a,b);
		return FR( a/g, b/g );
	}
	FR operator+( const FR& rhs ) const{
		FR aa = (*this).norm(), bb = rhs.norm();
		return FR( aa.a * bb.b + aa.b * bb.a, aa.b*bb.b ).norm();
	}
	FR operator-( const FR& rhs ) const{
		return (*this) + FR( -rhs.a, rhs.b );
	}
	bool operator<( const FR& rhs ) const{
		return a * rhs.b < b * rhs.a;
	}
};

int N;
int a[200200]; lld p[200200];

FR f( int i, int j ){
	lld s = p[i] - p[i-j-1] + p[N-1] - p[N-1-j];
	return FR( s, 1+2*j ).norm(); 
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	sort( a, a + N );
	for(int i=0; i<N; i++){
		p[i] = a[i] + ( i ? p[i-1] : 0 );
	}
	
	FR ans = FR(0,1); int ai = 0, bi = 0;
	for(int i=0; i<N; i++){
		int lo = -1, hi = min( i, N-i-1 );
		while( lo + 1 < hi ){
			int mid = (lo+hi)/2;
			if( f(i,mid) < f(i,mid+1) ) lo = mid;
			else hi = mid;
		}
		FR t = f(i,lo+1) - FR(a[i],1);
		if( ans < t ){
			ans = t; ai = i; bi = lo+1;
		}
	}
	printf("%d\n", 1+2*bi);
	for(int i=ai-bi; i<=ai; i++) printf("%d ",a[i]);
	for(int i=N-bi; i<N; i++) printf("%d ",a[i]);
	return 0;
}
