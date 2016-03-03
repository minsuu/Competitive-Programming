// Oct 22 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, array<int,3> > iii;

const int INF = 987654321;
const int null = 2222222;
int T,N,M, a,b,c;
iii E[100100];

struct node{
	int s, l, r;
	node (int s, int l, int r ) : s(s), l(l), r(r) {}
	int insert( int l, int r, int k, int v );
};

node* stree[2222223]; int tn, ftree[100100];
int node::insert( int l, int r, int k, int v ){
	if( l<=k && k<r ){
		if( l+1 == r ){
			int nn = tn++;
			stree[ nn ] = new node( this->s + v, this->l, this->r );
			return nn;
		}
		int m = ( l + r ) / 2, nn = tn++;
		stree[ nn ] = new node( this->s + v,
								( m <= k ) ? this->l : stree[this->l]->insert( l, m, k, v ),
						 		( k  < m ) ? this->r : stree[this->r]->insert( m, r, k, v ) );
		return nn;
	}
	return null;
}

// summation through [k..N] ; postfix sum
int query( int nw, int l, int r, int k ){
	if( l+1 == r ) return stree[nw]->s;

	int m = ( l + r ) / 2;
	if( m <= k )
		return query( stree[nw]->r, m, r, k );
	else
		return query( stree[nw]->l, l, m, k ) + stree[stree[nw]->r]->s;
}

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

bool cmp( const iii& a, const iii& b ) {
    return a.F > b.F;
}
int main(){
	stree[null] = new node( 0, null, null );
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0; i<N; i++) span[i].clear();
        assert( tn <= null );
        for(int i=0; i<tn; i++) delete stree[i];
        tn = 0;

        for(int i=0; i<M; i++){
        	scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            if( a>b ) swap(a,b);
            E[i] = { c, {a,b,M} };
        }

        sort( E, E+M, cmp );
        for(int i=0; i<M; i++){
            int f;
            if( dfs( E[i].S[0], E[i].S[1], -1, INF, f ) ){
            	// f : index of edge to be erased (maximum weight)
				E[f].S[2] = i;
                span[ E[f].S[0] ].erase( f );
                span[ E[f].S[1] ].erase( f );
            }
            span[ E[i].S[0] ][ i ] = E[i].S[1];
            span[ E[i].S[1] ][ i ] = E[i].S[0];
        }
        for(int i=0; i<M; i++){
        	ftree[i] = ( i ? stree[ftree[i-1]] : stree[null] ) -> insert( 0, M+1, E[i].S[2], E[i].F );
        }

        int Q, lsol = 0;
        scanf("%d",&Q);
        while( Q-- ){
            scanf("%d%d",&a,&b); a -= lsol; b -= lsol;
            // 0 .. b .. a
            a = lower_bound( E, E+M, iii(a-1, {0,0,0}), cmp ) - E - 1;
            b = lower_bound( E, E+M, iii(b, {0,0,0}), cmp ) - E;
            lsol = query( ftree[a], 0, M+1, a+1 ) - ( b? query( ftree[b-1], 0, M+1, a+1) : 0 );
            printf("%d\n",lsol);
        }
    }
    return 0;
 }