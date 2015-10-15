// Oct 14 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, array<int,2> > iii;

const int INF = 987654321;
int T,N,M, a,b,c;
iii E[100100]; vector<ii> S[400100];

map<int, int> span[1111];

bool dfs( int u, const int& v, int p, int m, int& f ){
	if( u == v ){
		f = m;
		return true;
	}
	for( auto it : span[u] )
		if( it.S != p && dfs( it.S, v, u, min( m, it.F ), f ) )
			return true;
	return false;
}
void update( int l, int I, int J, const int& p, const ii& v ){
	if( I <= p && p < J ){
		if( S[l].back().F == v.F ){
			S[l].back().S += v.S;
		}else{
			S[l].emplace_back( ii( v.F, v.S + S[l].back().S ) );
		}
		if( J - I != 1 ){
			int m = ( I + J ) / 2;
			update( l*2+1, I, m, p, v );
			update( l*2+2, m, J, p, v );
		}
	}
}
int query( int l, int I, int J, int i, int j ){
	if( J <= i || j <= I ) return 0;
	if( i <= I && J <= j ){
		return ( --lower_bound( S[l].begin(), S[l].end(), ii( j, 0 ) ) )->S
			- ( --lower_bound( S[l].begin(), S[l].end(), ii( i, 0 ) ) )->S;
	}
	int m = ( I + J ) /2;
	return query( l*2+1, I, m, i, j ) + query( l*2+2, m, J, i, j );
}
bool cmp( const iii& a, const iii& b ) {
	return a.F > b.F;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0; i<N; i++) span[i].clear();
		for(int i=0; i<4*M; i++) vector<ii>(1, {-1, 0} ).swap( S[i] );

		for(int i=0; i<M; i++){
			cin>>a>>b>>c; a--;b--;
			if( a>b ) swap(a,b);
			E[i] = { c, {a,b} };
		}
		sort( E, E+M, cmp );
		for(int i=0; i<M; i++){
			int f;
			if( dfs( E[i].S[0], E[i].S[1], -1, INF, f ) ){
				update( 0, 0, M, f, ii( i, -E[f].F) );
				span[ E[f].S[0] ].erase( f );
				span[ E[f].S[1] ].erase( f );
			}
			update( 0, 0, M, i, ii( i, E[i].F) );
			span[ E[i].S[0] ][ i ] = E[i].S[1];
			span[ E[i].S[1] ][ i ] = E[i].S[0];
		}
		int Q, lsol = 0;
		cin>>Q;
		while( Q-- ){
			cin>>a>>b; a -= lsol; b -= lsol;
			a = lower_bound( E, E+M, iii(a-1, {0,0}), cmp ) - E - 1;
			b = lower_bound( E, E+M, iii(b, {0,0}), cmp ) - E;
			lsol = query( 0, 0, M, b, a+1 );
			cout<<lsol<<"\n";
		}
	}
	return 0;
 }
