#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
using namespace std;
typedef array<int,2> pts;
typedef long long lld;
const double EPS = 1e-9;

int T,N;
bool cmp( pts p, pts a, pts b ){
	return (double) a[1]*b[0]*(p[0]-a[0])*(p[1]-b[1]) - (double) a[0]*b[1]*(p[1]-a[1])*(p[0]-b[0]) > 0;
}
bool cmp( int a, int b, int c, int d ){  // true if a/b - c/d > 0
	if( b < 0 ) a*=-1, b*=-1;
	if( d < 0 ) c*=-1, d*=-1;
	return a*1LL*d - c*1LL*b > 0LL;
}
bool cmp( lld a, lld b, lld c, lld d ){
	if( b < 0 ) a*=-1, b*=-1;
	if( d < 0 ) c*=-1, d*=-1;
	return (double)a*d - (double)c*b > 0.0;
}

struct stree{
	int lim;
	vector<pts> t[270000];
	void init( int n ){
		for( lim = 1; lim <= n; lim<<=1 );
		for( int i = 0; i<=2*lim; i++ ){
			t[i].clear();
		}
	}
	void m(){
 		for( int i = lim-1; i > 0; i-- ){
 			for( int j = 0 ; j < SZ(t[i*2]); j ++ ){
 				while( SZ(t[i]) >=2 && cmp( t[i][SZ(t[i])-2], t[i].back(), t[i*2][j] ) )
 					t[i].pop_back();
 				t[i].emplace_back( t[i*2][j] );
 			}
 			for( int j = 0 ; j < SZ(t[i*2+1]); j ++ ){
 				if( SZ(t[i])>=1 && t[i].back() == t[i*2+1][j] ) continue;
 				while( SZ(t[i]) >=2 && cmp( t[i][SZ(t[i])-2], t[i].back(), t[i*2+1][j] ) ){
 					t[i].pop_back();
 				}
 				t[i].emplace_back( t[i*2+1][j] );
 			}
		}
	}
	int q( int x ){
		x += lim;
		pts a = t[x][0], b = t[x][1];
		for( ; x > 0; x>>=1 ){
			if( (x & 1) == 0 ){
				// search brother
				if( search_hull( a,b, t[x+1] ) ){
					int r;
					for( r = x+1; r < lim; ){
						r<<=1;
						if( !search_hull( a,b, t[r] ) ) r++;
					}
					return r-lim+1;
				}
			}
		}
		return 0;
	}
	bool search_hull( pts A, pts B, const vector<pts>& hull ){
		if( SZ(hull) <= 1 ) return false;
		int a = A[1] - B[1], b = A[0] - B[0];
		lld ya = -A[0] * 1LL * a + b * 1LL * A[1], yb = b;
		int lo = 0, hi = SZ(hull)-1;
		if( cmp( a, b, hull[0][1] - hull[1][1], hull[0][0] - hull[1][0] ) ){
			hi = 0;
		}
		while( lo + 1 < hi ){
			int m = ( lo + hi )/2;
			int c = hull[m][1] - hull[m+1][1], d = hull[m][0] - hull[m+1][0];
			if( cmp( a, b, c, d ) ) hi = m;
			else lo = m;
		}
		lld ma = -hull[hi][0] * 1LL * a + b * 1LL * hull[hi][1];
		if( yb < 0 ) ma *= -1, b *= -1;
		return ma > ya;
	}
}stree;

int main() {
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>N; stree.init( N - 1 );
		pts a,b;
		cin>>a[0]>>a[1];
		for(int i=0; i<N-1; i++){
			cin>>b[0]>>b[1];
			stree.t[ i + stree.lim ].push_back( a );
			stree.t[ i + stree.lim ].push_back( b );
			a = b;
		}
		stree.m();
		for(int i=0; i<N-1; i++){
			cout<< stree.q( i ) << " ";
		}
		cout << "\n";
	}
	return 0;
}