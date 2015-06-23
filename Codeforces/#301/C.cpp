// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
char board[555][555];
int visit[555][555], f[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int n,m,r1,c1,r2,c2;
queue<ii> q;
bool valid(int x, int y){
	return 0<=x && x<n && 0<=y && y<m;
}
bool solve(){
	if( r1==r2 && c1==c2 ){
		for(int i=0; i<4; i++){
			int tx = r1 + f[i][0], ty = c1 + f[i][1];
			if( valid(tx, ty) && board[tx][ty] != 'X' ) return true;
		}
		return false;
	}
	q.push({ r1, c1 });
	while(!q.empty()){
		int hx = q.front().first, hy = q.front().second; q.pop();
		visit[hx][hy] = 2; board[hx][hy] = 'X';
		for(int i=0; i<4; i++){
			int tx = hx + f[i][0], ty = hy + f[i][1];
			if( valid(tx,ty) && visit[tx][ty] == 0){
				if( tx == r2 && ty == c2 ){
					if( board[tx][ty] == 'X') return true;
					for(int j=0; j<4; j++){
						int jx = tx + f[j][0], jy = ty + f[j][1];
						if( valid(jx, jy) && board[jx][jy] != 'X') return true;
					}
					return false;
				}
				if( board[tx][ty] != 'X' ){
					q.push( { tx, ty } );
					visit[tx][ty] = 1;
				}
			}
		}
	} return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",board[i]);
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2); r1--; c1--; r2--; c2--;
	if(solve()) printf("YES");
	else printf("NO");
	return 0;
} 