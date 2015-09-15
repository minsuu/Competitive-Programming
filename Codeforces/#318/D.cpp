#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
const long long INF = 987654321987654321;

int N,Q, a,b;
int war[33333], ih[33333]; ii hor[33333];
vector<int> toup[33333];

struct SNODE{
	long long mat[3][3]; // using [l+i, r+j) each
	int l, r; // [l, r)
	SNODE() : l(-1), r(0) {}
};

SNODE itree[133333];
int mi;

long long best_match(int l, int r){
	int perm[5] = { l, l+1, l+2, l+3, l+4 };
	long long cur = -INF;
	do {
		bool poss = true;
		long long sum = 0;
		for(int i=l; i<r && poss; i++){
			if( hor[i].S == perm[i-l] ) poss = false;
			sum += hor[i].F * 1LL * war[ perm[i-l] ];
		}
		if( poss ) cur = max( cur, sum );
	}while(next_permutation(perm, perm + (r-l) ) );
	return cur;
}

void update(int i){
	auto& p = itree[i];
	if( p.l == -1 ){
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				p.mat[i][j] = -INF;
		return;
	}
	for(int ls=0; ls<3; ls++){
		for(int rs=0; rs<3; rs++){
			int l = p.l + ls, r = p.r + rs;
			if( r>N || l>=r ) { p.mat[ls][rs] = -INF; continue; }
			long long cur = -INF;
			if( r - l <= 3 ){
				cur = max( cur, best_match( l, r ) );
			}
			if( l+1 != r ){
				auto& lc = itree[i*2];
				auto& rc = itree[i*2+1];
				for(int i = 0; i<3; i++)
					cur = max( cur, lc.mat[ls][i] + rc.mat[i][rs] );
			}
			p.mat[ls][rs] = cur;
		}
	}
}

int main(){
	scanf("%d%d",&N,&Q);
	for(int i=0; i<N; i++)
		scanf("%d",&war[i]);
	for(int i=0; i<N; i++){
		scanf("%d",&hor[i].F);
		hor[i].S = i;
	} sort( hor, hor + N );
	for(int i=0; i<N; i++){
		ih[ hor[i].S ] = i;
	}

	mi++; itree[1].l = 0, itree[1].r = N;
	for(int i=1; i<=mi; i++){
		if( itree[i].l+1 == itree[i].r ) continue;
		int m = (itree[i].l+itree[i].r)/2;
		itree[ i*2 ].l = itree[i].l, itree[ i*2 ].r = m;
		itree[ i*2+1 ].l = m, itree[ i*2+1 ].r = itree[i].r;
		mi = max( mi, i*2+1 );
	}

	for(int i=mi; i>0; i--){
		update( i );
		for(int j=itree[i].l; j<itree[i].r+2 && j<N; j++)
			toup[j].emplace_back( i );
	}

	while( Q-- ){
		scanf("%d%d",&a,&b); a--; b--;
		int ia = ih[a], ib = ih[b];
		swap( hor[ia].S, hor[ib].S );
		swap( ih[a], ih[b] );

		vector<int> upd( toup[ia].size() + toup[ib].size() );
		merge( toup[ia].begin(), toup[ia].end(),
				toup[ib].begin(), toup[ib].end(),
				upd.begin(), greater<int>() );
		upd.resize( unique(upd.begin(), upd.end() ) - upd.begin() );
		for( auto u : upd ) update(u);
		
		printf("%lld\n", itree[1].mat[0][0] );	
	}
	
	return 0;
}

