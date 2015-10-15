#include <bits/stdc++.h>
#define F first
#define S second
#define ABS(X) ( (X)>0 ? (X) : -(X) )
#define SGN(X) ( (X)==0 ? 0 : (X)/ABS(X) )
using namespace std;
typedef long long lld;
typedef pair<lld, lld> ll;

const int MAXN = 111111;
const lld INF = 987654321987654321LL;

lld X[MAXN], Y[MAXN], sX[MAXN], sY[MAXN], pX[MAXN], pY[MAXN], D;
int N;

lld eval( lld x, lld y ){
	if( x%2 || y%2 ) return INF;
	int a = lower_bound( sX, sX + N, x ) - sX;
	int b = lower_bound( sY, sY + N, y ) - sY;
	return ( x*a - pX[a] ) + ( pX[N] - pX[a] - x*(N-a) )
			+ ( y*b - pY[b] ) + ( pY[N] - pY[b] - y*(N-b) );
}
lld naiv( lld x, lld y ){
	lld ret = 0LL;
	for(int i=0; i<N; i++){
		ret += ABS( X[i] - x ) + ABS( Y[i] - y );
	}
	return ret;
}

vector<ll> sq;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%lld%lld",&X[i],&Y[i]); X[i]*=2LL; Y[i]*=2LL;
		sX[i] = X[i], sY[i] = Y[i];
	}
	scanf("%lld",&D); D*=2LL;
	sort( sX, sX + N ); sort( sY, sY + N );
	for(int i=1; i<=N; i++){
		pX[i] = pX[i-1] + sX[i-1];
		pY[i] = pY[i-1] + sY[i-1];
	}

	lld mpx = INF, Mpx = -INF, mnx = INF, Mnx = -INF;
	for(int i=0; i<N; i++){
		// -x + ( +x_i + y_i ) +_ D = y
		//  x + ( -x_i + y_i ) +_ D = y
		mpx = min( mpx, (-X[i] + Y[i] + D ) );
		Mpx = max( Mpx, (-X[i] + Y[i] - D ) );
		mnx = min( mnx, (+X[i] + Y[i] + D ) );
		Mnx = max( Mnx, (+X[i] + Y[i] - D ) );
	}
	sq.push_back( { ( Mnx - Mpx ) / 2, ( Mnx - Mpx )/2 + Mpx } ); // A
	sq.push_back( { ( mnx - Mpx ) / 2, ( mnx - Mpx )/2 + Mpx } ); // B
	sq.push_back( { ( mnx - mpx ) / 2, ( mnx - mpx )/2 + mpx } ); // C
	sq.push_back( { ( Mnx - mpx ) / 2, ( Mnx - mpx )/2 + mpx } ); // D
	bool poss = true;

	for(int i=0; i<(int)sq.size(); i++){
		if( !( sq[0].S <= sq[i].S ) )
			poss = false;
	}
	for(int i=0; i<(int)sq.size(); i++){
		if( !( sq[1].F >= sq[i].F ) )
			poss = false;
	}
	for(int i=0; i<(int)sq.size(); i++){
		if( !( sq[2].S >= sq[i].S ) )
			poss = false;
	}
	for(int i=0; i<(int)sq.size(); i++){
		if( !( sq[3].F <= sq[i].F ) )
			poss = false;
	}

	if( poss ){
		long long ans = INF;

		sq.push_back( sq[0] );
		for( int j=1; j<(int)sq.size(); j++){
			ans = min( ans, eval( sq[j-1].F, sq[j-1].S ) );
			ans = min( ans, eval( sq[j-1].F + SGN(sq[j].F - sq[j-1].F ),
								  sq[j-1].S + SGN(sq[j].S - sq[j-1].S ) ) );
			ans = min( ans, eval( sq[j].F + SGN(sq[j-1].F - sq[j].F ),
								  sq[j].S + SGN(sq[j-1].S - sq[j].S ) ) );
		}

		for( int i=0; i<N; i++){
			for( int j=1; j<(int)sq.size(); j++){
				ll a = sq[j-1], b = sq[j];
				if( a.S > b.S ) swap(a,b);

				if( a.S < Y[i] && Y[i] < b.S ){
					lld nX = a.F + SGN( b.F - a.F ) * ( Y[i] - a.S );
					ans = min( ans, eval( nX, Y[i] ) );
				}

				if( a.F > b.F ) swap(a,b);
				if( a.F < X[i] && X[i] < b.F ){
					lld nY = a.S + SGN( b.S - a.S ) * ( X[i] - a.F );
					ans = min( ans, eval( X[i], nY ) ) ;
				}
			}
		}
		printf("%lld\n",ans/2);
	}else{
		printf("impossible\n");
	}
	return 0;
}