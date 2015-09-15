#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii > iii;
priority_queue<iii> pq;

int f[4][2] = { 1,0, 0,1, -1,0, 0,-1 };
int N,M;
int dp[555][555], board[555][555];

bool valid( int x, int y ){
	return 0<=x && x<N && 0<=y && y<M;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N; i++){
		for(int j=0; j<M;j++){
			scanf("%d",&board[i][j]);
		}
	}
	pq.push( { -board[N-1][M-1], { N-1, M-1} } );
	dp[N-1][M-1] = 1;
	while(!pq.empty()){
		int nx = pq.top().S.F, ny = pq.top().S.S; pq.pop();
		if( dp[nx][ny] != 0 && !( nx==N-1 && ny==M-1) ) continue;
		for(int ff=0; ff<4; ff++){
			int mx = nx + f[ff][0], my = ny + f[ff][1];
			if( valid(mx,my) ){
				if( board[mx][my] < board[nx][ny] )
					dp[nx][ny] += dp[mx][my];
				if( board[mx][my] > board[nx][ny] ){
					pq.push( { -board[mx][my], { mx, my } } );
				}
			}
		}
	}/*
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}*/
	printf("%d",dp[0][0]);
	return 0;
}