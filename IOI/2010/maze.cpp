#include <bits/stdc++.h>
using namespace std;
char board[222][222];
int N, M, pl, path[222222][2], lim[222][222];
int av[4][2], avc, nlim[222][222], npath[222222][2];
inline bool inside( int x, int y ) { return 1<=x && x<N-1 && 1<=y && y<M-1; }
inline void put( int x,int y, int v, int (&l)[222][222] ){
	int f[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for(int i = 0; i< 4; i++ ){
		int nx = x + f[i][0], ny = y + f[i][1];
		if( inside(nx,ny) && ( l[nx][ny]==0 || l[nx][ny]>=v ) ) l[nx][ny] = v;
	} l[x][y]=v;
}
void go(int st){
	int f[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int now = st;
	// npath[st][0] = path[st][0]; npath[st][1] = path[st][1];
	while( 1 ){
		avc=0;
		for(int i = 0; i < 4; i++ ){
			int nx = npath[now][0] + f[i][0], ny = npath[now][1] + f[i][1];
			if( inside(nx,ny) && board[nx][ny]=='#' && ( lim[nx][ny]==0 || lim[nx][ny]>=st )
				 && ( nlim[nx][ny]==0 || nlim[nx][ny] >= now ) ){
				av[avc][0] = nx, av[avc][1] = ny; avc++;
			}
		}
		if(avc == 0) break;
		int d = rand() % avc;
		npath[++now][0] = av[d][0]; npath[now][1] = av[d][1];
		put( av[d][0], av[d][1], now, nlim );
	}
	if( now > pl ){
		for(int i=st; i<=now; i++) path[i][0] = npath[i][0], path[i][1] = npath[i][1];
		lim[ path[st+1][0] ][ path[st+1][1] ] = nlim[ path[st+1][0] ][ path[st+1][1] ];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				if( lim[i][j] > st ) lim[i][j] = 0;
				if( lim[i][j]==0 && nlim[i][j] !=0 ) lim[i][j] = nlim[i][j];
			}
		pl = now;
	}
}

int dl[222][222];
struct STS { int here, it; };
void dfs( int now ){ // set now to block, find the path
	int f[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int sx = path[now][0], sy = path[now][1];
	int dx = path[now+1][0], dy = path[now+1][1], nl;
	bool found = false;
	dl[sx][sy] = -1;
	now--; npath[now][0] = path[now][0]; npath[now][1] = path[now][1];
	stack<STS> st; st.push({ now, 0 } );
	while(!st.empty()){
		int h = st.top().here, i = st.top().it; st.top().it++;
		int hx = npath[h][0], hy = npath[h][1];
		if( i == 4 ) {
			st.pop();
			for(int ff = 0; ff<4; ff++){
				int fx = hx + f[ff][0], fy = hy + f[ff][1];
				if( inside(fx,fy) && dl[fx][fy] == h )
					dl[fx][fy]=0;
			}
			continue;
		}
		int nx = hx + f[i][0], ny = hy + f[i][1];
		if( inside(nx,ny) && nx == dx && ny == dy ){
			found = true; nl = h;
			break;
		}
		if( inside(nx,ny) && board[nx][ny]=='#' && (lim[nx][ny]==0 || lim[nx][ny]==now || lim[nx][ny]==now+2) && ( dl[nx][ny]==0 || dl[nx][ny]==h ) ){
			npath[h+1][0] = nx; npath[h+1][1] = ny;
			put(nx, ny, h+1, dl);
			st.push( { h+1, 0 } );
		}
	}
	if(found){
		for(int i = now; i <= nl; i++)
			printf("(%d, %d) - ",npath[i][0], npath[i][1]); printf("\n");
	}
}

int main(){
	srand (time(NULL));
	while( scanf("%s",board[N++]) != EOF ); N--; M = strlen(board[0]);
	pl = 0;
	// for(int iter=0; iter<100; iter++){
		memset(nlim, 0, sizeof nlim);
		int ed = rand() % 4, sx, sy;
		/*
		if( ed == 0 ) sx = 0, sy = rand() % (M-2) + 1;
		else if( ed == 1 ) sx = N-1, sy = rand() % (M-2) + 1;
		else if( ed == 2 ) sx = rand() % (N-2) + 1, sy = 0;
		else sx = rand() % (N-2) + 1, sy = M-1;
		*/
		sx = 0, sy = 1;
		// if( board[sx][sy] == 'X' ) continue;

		put(sx, sy, 1, nlim ); npath[1][0]=sx, npath[1][1]=sy;
		go(1);

		for(int jiter = 0; jiter < 10000; jiter++){
			int np;
			if( pl < 80 )
				np = 1;
			else
				np = pl - ( rand() % ( pl / 2 ) + 1 );

			memset(nlim, 0, sizeof nlim);
			npath[np][0] = path[np][0], npath[np][1] = path[np][1];
			put(path[np][0], path[np][1], np, nlim);
			go(np);
		} 
		for(int i = 3; i< pl-2; i++)
			dfs(i);
	// }
	for(int i=1;i<=pl;i++)
		board[ path[i][0] ][ path[i][1] ] = '.';
	for(int i=0;i<N;i++)
		printf("%s\n",board[i]);
	printf("ans : %d",pl);
	return 0;
}