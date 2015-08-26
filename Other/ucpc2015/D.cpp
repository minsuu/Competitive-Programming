#include <bits/stdc++.h>
using namespace std;
const int MAXN = 555;

// up 1, down 2, left 4, right 8
int f[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1};
int T,N,M,sz, mk[MAXN][MAXN];
char board[MAXN][MAXN], ans[MAXN][MAXN];

const int INF = 987654321;
int sx=-1, sy, ex, ey;
char preset[22];

int dfs( int x, int y ){
	ans[x][y] = preset[ mk[x][y] ];
	if( x == ex && y == ey ) return 1;
	
	// 0,1, 2,3
	for(int i=0; i<4; i++){
		if( mk[x][y] & (1<<i) ){
			int nx = x+f[i][0], ny = y+f[i][1];
			if( ans[nx][ny] == 0 && ( mk[nx][ny] & (1<<(i^1)) ) ){
				return dfs( nx, ny) + 1;
			}
		}
	}
	return -INF;
}
bool go(){
	// verticals
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			bool vlink = ( mk[i-1][j] & 2 );
			bool hlink = ( mk[i][j-1] & 8 );
			if( board[i][j] == 'q' ){
				mk[i][j] |= ( vlink? 1 : 2 );
				mk[i][j] |= ( hlink? 4 : 8 );
			}
			if( board[i][j] == 'l' ){
				if( vlink && hlink ) return false;
				mk[i][j] |= ( vlink? 1+2 : 4+8 );
			}
		}
	}
	memset( ans, 0, sizeof ans );
	if( dfs(sx,sy) == sz ) return true;
	else return false;
}

// up 1, down 2, left 4, right 8
int main(){
	scanf("%d",&T);
	preset[1] = 94; preset[2] = 118; preset[4] = 60; preset[8] = 62;
	preset[1+2] = 108; preset[4+8] = 45;
	preset[2+4] = 113; preset[1+4] = 100; preset[1+8] = 98; preset[2+8] = 112;

	while(T--){
		scanf("%d%d",&N,&M); sz = 0; sx = -1;
		for(int i=1; i<=N; i++){
			scanf("%s", board[i]+1 );
			for(int j=1; j<=M; j++){
				if( board[i][j] == 'O' ){
					if( sx == -1 ) sx = i, sy = j;
					else ex = i, ey = j;
				}
				sz += ( board[i][j] != '*' );
			}
		}
		bool found = false;
		for(int i=0; i<4 && (!found); i++){
			for(int j=0; j<4 && (!found); j++){
				memset( mk, 0, sizeof mk );
				mk[sx][sy] = 1<<i; mk[ex][ey] = 1<<j;

				if( go() ){
					found = true;
				}
			}
		}

		if( found ){
			printf("YES\n");
			for(int i=1; i<=N; i++){
				for(int j=1; j<=M; j++){
					if( board[i][j] == '*' )
						ans[i][j] = 42;
				}
			}
			for(int i=1; i<=N; i++)
				printf("%s\n", ans[i]+1);
		}else{
			printf("NO\n");
		}
	}
	return 0;
}