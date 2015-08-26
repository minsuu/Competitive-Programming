// Aug 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int X,Y,Z, A,B,C, N;
lld ans[1111], cnt[1111], cntz[1111];

void get(lld m, lld x, lld y, lld z, lld n){
	if( m == 0 || x == 0 || y == 0 || z == 0 ) return;
	memset( cnt, 0, sizeof cnt );
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			cnt[ (i+j+n)%N ]++;
	for(int i=0; i<N; i++){
		memset( cntz, 0, sizeof cntz );
		for(int j=0; j<z; j++)
			cntz[ (i+j)%N ]++;
		for(int j=0; j<N; j++)
			ans[j] += cnt[i] * cntz[j] * m;
	}
}

void go(lld x, lld y, lld z, lld n ){
	n %= N;
	if( x == 0 || y == 0 || z == 0 ) return;
	lld a = (x/N) * (y/N) * (z/N);
	for(int i=0; i<N; i++) ans[i] += a*N*N;

	get( (y/N)*(z/N), x%N, N, N, n );
	get( (x/N)*(z/N), N, y%N, N, n );
	get( (x/N)*(y/N), N, N, z%N, n );
	get( x/N, N, y%N, z%N, n );
	get( y/N, x%N, N, z%N, n );
	get( z/N, x%N, y%N, N, n );
	get( 1, x%N, y%N, z%N, n );
}

int main(){
	scanf("%d%d%d%d%d%d%d",&X,&Y,&Z, &A,&B,&C, &N);
	go( X-A, Y-B, Z-C, 0 );
	go( A, Y-B, Z-C, 1 );
	go( X-A, B, Z-C, 1 );
	go( X-A, Y-B, C, 1 );
	go( A, B, Z-C, 2 );
	go( A, Y-B, C, 2 );
	go( X-A, B, C, 2 );
	go( A, B, C, 3 );
	for(int i=0; i<N; i++)
		printf("%lld ",ans[i]);
	return 0;
}