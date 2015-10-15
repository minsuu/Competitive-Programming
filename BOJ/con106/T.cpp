#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef pair<int,int> ii;

bool av[1<<16][161];
int sz[1<<16][161];

vector<int> made[161];
vector<ii> dmade;
int N, st[22];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&st[i]);
	}
	av[0][0] = 1;
	for(int i=1; i<(1<<N); i++){
		av[i][0] = 1;
		int j;
		for( j=N-1; j>=0; j-- )
			if( i & (1<<j) ) break;

		int l = i ^ (1<<j);
		for( int k = 1; k<=160; k++ ){
			av[i][k] = av[l][k];
			sz[i][k] = sz[l][k];
			if( k>st[j] ){
				av[i][k] |= av[l][k-st[j]];
				if( av[l][k-st[j]] ) sz[i][k] = sz[l][k-st[j]] + 1;
			}
		}
		av[i][st[j]] = 1; sz[i][st[j]] = 1;
	}
	for(int i=1; i<=160; i++){
		for( int j=1; j<(1<<N); j++){
			if( av[j][i] ){
				int s = 0, k = j;
				while( k ){
					s += (k&1);
					k/=2;
				}
				if( s != sz[j][i] ) continue;
				made[i].push_back( j );
			}
		}
	}
	
	for(int i=1; i<=160; i++){
		int n = made[i].size();
		for(int j=0; j<n; j++){
			for(int k=j+1; k<n; k++){
				if( ( made[i][j] & made[i][k] ) == 0 ){
					dmade.push_back( { made[i][j] | made[i][k] , i } );
				}
			}
		}
	}
	
	int n = dmade.size(), ans = -1;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if( ( dmade[i].F & dmade[j].F ) == 0 ) {
				ans = max( ans , dmade[i].S * dmade[j].S );
			}
		}
	}
	printf("%d",ans);
	return 0;
}