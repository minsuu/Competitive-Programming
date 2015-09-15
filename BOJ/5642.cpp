#include <bits/stdc++.h>
using namespace std;

const int MC = 2e4;
const int MR = 25;

int b[MR][MC];
int T,R,C,N;

int rm[MR];

set<int> rs[MR];

int main(){

	freopen( "5642.out", "w", stdout );

	for(int i=1; i<MR; i++){
		b[i][0] = 1;
		rs[i].insert( 1 );
	}

	for(int i=1; i<MC; i++){
		b[0][i] = 1;
		for(int j=1; j<MR; j++){
			while( rs[j].count(rm[j]) ) rs[j].erase(rm[j]), rm[j]++;

			set<int> s( rs[j].begin(), rs[j].end() );

			int k = i, l = j;
			l--; while( l>=0 ) s.insert( b[l][k] ), l--;

			k = i, l = j;
			k--; l--; while( k>=0 && l>=0 ) s.insert( b[l][k] ), k--, l--;

			int g = rm[j];
			while( s.count(g) != 0 ) g++;
			b[j][i] = g;

			rs[j].insert(g);
		}
	}

	for(int i=0; i<MR; i++){
		for(int j=0; j<MC; j++){
			printf("%d ",b[i][j] );
		} printf("\n");
	}

	fclose( stdout );
	return 0;
}