#include <bits/stdc++.h>
using namespace std;
int f[4][2] = { 0,1, 1,0, 0,-1, -1,0 };
int T,L,a,b,c, brd[111][111];
char cmd[222];
int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		memset( brd, 0, sizeof brd );
		c = 0;

		scanf("%d%d%s",&a,&b,cmd);
		L = strlen( cmd );
		
		brd[a][b] = 1;
		int dir = 0;
		for(int i=0; i<L; i++){
			if( cmd[i] == 'L' ) dir = (dir+3)%4; 
			else if( cmd[i] == 'R' ) dir = (dir+1)%4;
			else{
				a += f[dir][0], b += f[dir][1];
				brd[a][b]++;
			}
		}
		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				if( brd[i][j] > 1 ) c++;
			}
		}
		printf("Case #%d: %d %d %d\n", t, a, b, c ); 
	}
	return 0;
}
