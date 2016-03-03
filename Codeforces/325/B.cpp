#include <bits/stdc++.h>
using namespace std;
char board[3][111]; int T,N,K;
int visit[3][111];
typedef pair<int,int> ii;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		int sx;
		memset( board, 0, sizeof board );
		for(int i=0; i<3; i++){
			scanf("%s",board[i]);
			if( board[i][0] == 's' )
				sx = i;
		}
		memset(visit, 0, sizeof visit);
		queue<ii> q; q.push( ii(sx, 0) ); visit[sx][0] = 1;
		while(!q.empty()){
			int nx = q.front().first, ny = q.front().second; q.pop();
			if( board[nx][ny+1] != '.' ) continue;
			ny ++; visit[nx][ny] = 1;

			{
				int mx = nx, my = ny;
				if( board[mx][my] == '.' ){
					visit[mx][my] = 1; my++;
					if( board[mx][my] == '.' ){
						visit[mx][my] = 1; my++;
						if( board[mx][my] == '.' ){
							if( visit[mx][my] == 0 ){
								q.push( ii(mx,my) );
							}
							visit[mx][my] = 1;
						}
					}
				}
			}
			if( 0<nx ){
				int mx = nx-1, my = ny;
				if( board[mx][my] == '.' ){
					visit[mx][my] = 1; my++;
					if( board[mx][my] == '.' ){
						visit[mx][my] = 1; my++;
						if( board[mx][my] == '.' ){
							if( visit[mx][my] == 0 ){
								q.push( ii(mx,my) );
							}
							visit[mx][my] = 1;
						}
					}
				}
			}
			if( nx<2 ){
				int mx = nx+1, my = ny;
				if( board[mx][my] == '.' ){
					visit[mx][my] = 1; my++;
					if( board[mx][my] == '.' ){
						visit[mx][my] = 1; my++;
						if( board[mx][my] == '.' ){
							if( visit[mx][my] == 0 ){
								q.push( ii(mx,my) );
							}
							visit[mx][my] = 1;
						}
					}
				}
			}
		}
		bool ans = false;
		for(int i=0; i<3; i++)
			ans |= visit[i][N-1];
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
