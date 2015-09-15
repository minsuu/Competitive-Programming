#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int INF = 987654321;
const int MOD = 1e6;

int tet[6][4][2] = { { 0,0, 1,0, 0,1, 1,1 }, { 0,0, 0,1, -1,1, -1,2 },
					 { 0,0, 0,1, 1,1, 1,2} , {0,0, 0,1, 1,1, 0,2},
					 { 0,0, 0,1, 0,2, -1,2}, {0,0, 0,1, 0,2, 1,2 } };
int board[3][3];

typedef pair<int,int> ii;
typedef vector<ii> vii;
set<vii> tets;
vector<int> adj[1<<6];

bool valid(int x, int y){
	return 0<=x && x<3 && 0<=y && y<3;
}

bool put( const vii& bl, int x, int y, bool un = 1 ){
	bool ys = true;
	if( un ){
		for( auto it : bl ){
			int nx = x + it.S, ny = y + it.F;
			if( !valid(nx, ny) || board[nx][ny] == 1 ) ys = false;
		}
		if( !ys ) return false;
	}

	for( auto it : bl ){
		int nx = x + it.S, ny = y + it.F;
		board[nx][ny] = un;
	}
	return true;
}

void dfs( int bg ){
	int j;
	for(j=0; j<3; j++)
		if( board[j][0] == 0 ) break;
	if( j==3 ){
		int st = 0;	
		for(int i=0; i<3; i++){
			for(int j=0; j<2; j++){
				if( board[i][j+1] )
					st |= 1<<( i*2 + j );
			}
		}
		adj[bg].push_back( st );
		return;
	}
	for( auto& it : tets ){
		if( put( it, j, 0 ) ){
			dfs( bg );
			put( it, j, 0, 0 );
		}
	}
}

int main(){
	for(int i=0; i<6; i++){
		vii ntet;
		for(int j=0; j<4; j++)
			ntet.push_back( { tet[i][j][1], tet[i][j][0] } );

		for(int j=0; j<4; j++){ //rotating
			sort( ntet.begin(), ntet.end() );
			tets.insert( ntet );

			vii nxtet; ii mm = { INF, INF };
			for(int k=0; k<4; k++){
				nxtet.push_back( { -ntet[k].S, ntet[k].F } );
				mm = min( mm, nxtet.back() );
			}
			for(int k=0; k<4; k++) nxtet[k].F -= mm.F, nxtet[k].S -= mm.S;
			nxtet.swap( ntet );
		}
	}

	for(int i=0; i<(1<<6); i++){
		memset( board, 0, sizeof board );
		for(int j=0; j<3; j++){
			for(int k=0; k<2; k++){
				if( i & ( 1<< (j*2+k) ) )
					board[j][k] = 1;
			}
		}
		/*
		printf("FROM :: \n");
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				printf("%d",board[j][k]);
			}printf("\n");
		}*/
		dfs( i );/*
		for( auto it : adj[i] ){
			printf("TO ::\n");
			for(int j=0; j<3; j++){
				printf("1");
				for(int k=0; k<2; k++){
					if( it & (1<<(j*2+k) ) )
						printf("1");
					else printf("0");
				}printf("\n");
			}
		}
		printf("\n");*/
	}
	int N;
	scanf("%d",&N);
	vector<int> dp(1<<6), ndp(1<<6);
	dp[1+4+16] = 1;

	for(int i=1; i<N+2; i++){
		vector<int>(1<<6).swap(ndp);
		for(int j=0; j<(1<<6); j++){
			for(auto it : adj[j])
				ndp[it] = ( ndp[it] + dp[j] ) % MOD;
		}
		ndp.swap(dp);
	}
	printf("%d",dp[0]);
	return 0;
}