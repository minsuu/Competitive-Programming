#include <bits/stdc++.h>
using namespace std;
char type[5];
typedef long long lld;
const lld INF = 987654321987654321;
const lld MIN = 1000000010;
// range minimum query.
// build() : build minimum segments
// build(n) : update its linkd segments
// update( j, k ) : find all [0..j) elements below k & delete it
// delete(j) : delete jth element
const int MN = 1e5+10;

struct stree{
	lld t[2*MN];
	vector<int> last;
	int h, n;
	void build(){
		h = sizeof(int)*8 - __builtin_clz(n);
		for(int i=n-1; i>0; --i) t[i] = min( t[i<<1], t[i<<1|1] );
	}
	void build(int p){
		while( p>1 ) p>>=1, t[p] = min( t[p<<1], t[p<<1|1] );
	}
	void update( int r, lld k ){
		queue<int> upd; last.clear();
		int l = 0;
		for( l+=n, r+=n; l<r; l>>=1, r>>=1 ){
			if( l&1 ){
				if( t[l] <= k ) upd.push( l );
				l++;
			}
			if( r&1 ){
				r--;
				if( t[r] <= k ) upd.push( r );
			}
		}
		while( !upd.empty() ){
			int nw = upd.front(); upd.pop();
			if( nw >= n ){
				t[nw] = INF;
				build( nw );
				last.push_back( nw - n );
				continue;
			}
			if( t[nw<<1] <= k ) upd.push( nw<<1 );
			if( t[nw<<1|1] <= k ) upd.push( nw<<1|1 );
		}
	}
	void del( int i ){
		i += n; t[i] = INF; build( i );
	}
} Wid, Nar;

typedef array<lld, 3> QUE;
QUE wids[MN], nars[MN];
int T,N, mw[MN], mn[MN], ons[MN];
lld a,b; char tps[MN];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		Wid.n = Nar.n = N;
		for(int i=0; i<N; i++){
			scanf("%lld%lld%s",&a,&b,type); a+= MIN;
			ons[i] = 0;
			tps[i] = type[0];
			wids[i] = { a+b, -a+b, -i };
			nars[i] = { 2*a+b, -2*a+b, -i };
		}
		sort( wids, wids+N ); sort( nars, nars+N );
		for(int i=0; i<N; i++){
			wids[i][2] *= -1; nars[i][2] *= -1;
			mw[ wids[i][2] ] = i;
			mn[ nars[i][2] ] = i;
			Wid.t[ i+N ] = wids[i][1];
			Nar.t[ i+N ] = nars[i][1];
		}
		Wid.build(); Nar.build();
		int ans = 0;
		for(int i=0; i<N; i++){
			int wi = mw[i], ni = mn[i];
			if( Wid.t[wi+N] == INF ){
				assert( Nar.t[ni+N] == INF );
				printf("FAIL\n");
				continue;
			}
			ons[ i ] = 1; ans ++;
			if( tps[i] == 'W' ){
				Wid.update( wi, Wid.t[wi+N] );
				for( auto it : Wid.last ){
					int ii = wids[it][2];
					if( ons[ii] == 1 ) { ans --; ons[ii] = 0; }
					Nar.del( mn[ii] );
				}
			}else if( tps[i] == 'N' ){
				Nar.update( ni, Nar.t[ni+N] );
				for( auto it : Nar.last ){
					int ii = nars[it][2];
					if( ons[ii] == 1 ) { ans --; ons[ii] = 0; }
					Wid.del( mw[ii] );
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
