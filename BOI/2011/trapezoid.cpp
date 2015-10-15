#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;

const int MAXN = 111111;
const int MOD = 30013;

struct TRAPE{
	int a,b,c,d;
	bool operator<(const TRAPE& rhs){
		return b < rhs.b;
	}
};
int N;
TRAPE z[MAXN];
map<int,int> comp;

ii res[8*MAXN];
ii merge( const ii& a, const ii& b ){
	if( a.F == b.F ) return { a.F, ( a.S + b.S )%MOD };
	return (a.F > b.F)? a : b;
}
void update( int i, int I, int J, int p, ii v ){
	if( p < I || J <= p ) return;

	if( J - I == 1 ){
		res[i] = v;
	}else{
		int M = ( I + J ) / 2;
		update( i*2+1, I, M, p, v );
		update( i*2+2, M, J, p, v );
		res[i] = merge( res[i*2+1], res[i*2+2] );
	}
}
ii query( int i, int I, int J, int p ){
	if( J <= p ) return {0,0};
	if( p < I || J - I == 1 ) return res[i];
	int M = ( I + J ) / 2;
	return merge( query(i*2+1, I, M, p) , query(i*2+2, M, J, p ) );
}

int disj[MAXN], disp[MAXN];
int main(){
	scanf("%d",&N); N++; z[0] = { 0,0,0,0 };
	for(int i=1; i<N; i++){
		scanf("%d%d%d%d",&z[i].a, &z[i].b, &z[i].c, &z[i].d );
		comp[ z[i].c ]; comp[ z[i].d ];
	}
	int cp = 0;
	for( auto& it : comp ){
		it.S = cp++;
	}
	for(int i=0; i<N; i++){
		z[i].c = comp[ z[i].c ];
		z[i].d = comp[ z[i].d ];
	}

	sort( z, z+N );
	priority_queue< pair<int,int> > pq;
	for(int i=N-1; i>=0; i--){
		while( !pq.empty() && z[i].b < pq.top().F ){
			int j = pq.top().S;
			update( 0, 0, cp, z[j].c, { disj[j] , disp[j] } );
			pq.pop();
		}
		ii r = query( 0, 0, cp, z[i].d );
		if( r.F == 0 ){
			disj[i] = disp[i] = 1;	
		}else{
			disj[i] = r.F + 1;
			disp[i] = r.S;
		}
		pq.push( { z[i].a, i} );
	}
	printf("%d %d",disj[0]-1,disp[0]);
	return 0;
}