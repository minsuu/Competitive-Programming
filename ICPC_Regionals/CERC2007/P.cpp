#include <bits/stdc++.h>
using namespace std;
typedef array<int,3> pts;

int N;
pts P[1010];
// 0 : N, 1 : E, 2 : W, 3 : S
char dch[4] = { 'N', 'E', 'W', 'S' };
int linkd[1010][4];
const int INF =987654321;

int main(){
	while(1){
		scanf("%d",&N);
		if( N == 0 ) break;
		memset( linkd, -1, sizeof linkd );
		
		int my = -INF, st = -1;
		for(int i=0; i<N; i++){
			scanf("%d%d", &P[i][0], &P[i][1] );
			P[i][2] = i;
			if( my < P[i][1] ){
				my = P[i][1]; st = i;
			}else if( my == P[i][1] ){
				if( P[i][0] < P[st][0] ){
					// st : y maximum x minimum
					st = i;
				}
			}
		}
		
		sort( P, P+N );
		int lst = -INF, ls = INF;
		P[N][0] = INF;
		for(int i=0; i<=N; i++){
			if( lst != P[i][0] ){
				for(int j=ls; j<i; j+=2){
					linkd[ P[j][2] ][ 0 ] = P[j+1][2];
					linkd[ P[j+1][2] ][ 3 ] = P[j][2];
				}
				lst = P[i][0]; ls = i;
			}
		}
		
		for(int i=0; i<N; i++) swap( P[i][0], P[i][1] );
		sort( P, P+N );
		lst = -INF, ls = INF;
		P[N][0] = INF;
		for(int i=0; i<=N; i++){
			if( lst != P[i][0] ){
				for(int j=ls; j<i; j+=2){
					linkd[ P[j][2] ][ 1 ] = P[j+1][2];
					linkd[ P[j+1][2] ][ 2 ] = P[j][2];
				}
				lst = P[i][0]; ls = i;
			}
		}
		
		assert( linkd[st][1] != -1 );
		vector<int> SEQ; string d;
		int zp = -1, par = st, nw = linkd[st][1];
		SEQ.push_back( st ); d.push_back( dch[1] );
		if( st == 0 ) zp = 0;
		while( nw != st ){
			SEQ.push_back( nw );
			if( nw == 0 ) zp = d.size();
			for(int i=0; i<4; i++)
				if( linkd[nw][i] != -1 && linkd[nw][i] != par ){
					d.push_back( dch[i] );
					par = nw;
					nw = linkd[nw][i]; break;
				}
		}
		printf("%s%s\n",string( d.begin() + zp, d.end() ).c_str(), string( d.begin(), d.begin() + zp ).c_str() );
	}
	return 0;
}
