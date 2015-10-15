#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef pair<int, iii> STATE;
const int INF = 987654321;

int N,M, f[4][2]={0,1, 1,0, 0,-1, -1,0}, kx, ky, kf[4][4]={0,2, 1,2, 2,0, 2,1, 0,-1, 1,-1, -1,0, -1,1};
int dist[55][55], sp[2][2], sn, ans[55][55][4]; // came from [0, 4) : blank there
char board[55][55];

bool valid(int x, int y){
	return 0<=x && x<N && 0<=y && y<M && !( (x == kx || x == kx+1 ) && (y == ky || y == ky+1 ) ) && board[x][y] != '*';
}
int bfs( int sx, int sy, int ex, int ey ){
	if( !valid(ex,ey) ) return INF;
	queue<ii> q; q.push( {sx, sy} );
	memset( dist, -1, sizeof dist ); dist[sx][sy] = 0;
	while( !q.empty() && dist[ex][ey] == -1){
		int nx = q.front().F, ny = q.front().S; q.pop();
		for(int g=0; g<4; g++){
			int fx = nx + f[g][0], fy = ny + f[g][1];
			if( valid(fx,fy) && dist[fx][fy] == -1 ){
				dist[fx][fy] = dist[nx][ny] + 1;
				q.push( { fx,fy} );
			}
		}
	}
	if( dist[ex][ey] == -1 ) return INF;
	return dist[ex][ey];
}

int main(){
	while( 1 ){
		scanf("%d%d",&N,&M);
		if( N == 0 && M == 0 ) break;
		for(int i=0; i<N; i++){
			scanf("%s",board[i]);
		}
		kx = ky = -1; sn = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if( board[i][j]=='X' && kx == -1 ){
					kx = i, ky = j;
				}
				if( board[i][j]=='.' ){
					sp[sn][0] = i;
					sp[sn++][1] = j;
				}
			}
		}
		if( kx==0 && ky==0 ) { printf("0\n"); continue; }

		priority_queue<STATE> pq;
		memset( ans, -1, sizeof ans );
		for(int g=0; g<4; g++){
			int d = INF;
			for(int i=0; i<2; i++)
				d = min(d, bfs( sp[i][0], sp[i][1], kx + kf[g][0], ky + kf[g][1] )
						  +bfs( sp[i^1][0], sp[i^1][1], kx + kf[g][2], ky + kf[g][3] ));
			if( d != INF ){
				ans[kx][ky][g] = d;
				pq.push( { -d, { g, { kx, ky } } } );
			}
		}
		while( !pq.empty() ){
			int nc = -pq.top().F, b = pq.top().S.F;
			kx = pq.top().S.S.F, ky = pq.top().S.S.S;
			sp[0][0] = kx + kf[b][0], sp[0][1] = ky + kf[b][1];
			sp[1][0] = kx + kf[b][2], sp[1][1] = ky + kf[b][3];
			pq.pop();

			if( ans[kx][ky][b] < nc ) continue;
			for(int g=0; g<4; g++){
				int d = INF, nkx = kx + f[g][0], nky = ky + f[g][1];
				for(int i=0; i<2; i++)
					d = min(d, bfs( sp[i][0], sp[i][1], kx + kf[g][0], ky + kf[g][1] )
							  +bfs( sp[i^1][0], sp[i^1][1], kx + kf[g][2], ky + kf[g][3] ));
				if( d==INF ) continue;
				if( ans[nkx][nky][g^2] == -1 || ans[nkx][nky][g^2] > nc + d + 1 ){
					ans[nkx][nky][g^2] = nc + d + 1;
					pq.push( { -(nc+d+1), { g^2, { nkx, nky} } } );
				}
			}
		}
		int fans = INF;
		for(int i=0; i<4; i++){
			if( ans[0][0][i] == -1 ) continue;
			fans = min( fans, ans[0][0][i] );
		}
		if( fans==INF ) fans = -1;
		printf("%d\n",fans);
	}
	return 0;
}