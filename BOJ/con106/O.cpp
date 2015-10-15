#include <bits/stdc++.h>
using namespace std;
int q[1111][1111], p[1111][1111];
int a,b,c,N, ans;

int last[1111][1111];
void rec(int x, int y, int d){
	if( d <= last[x][y] ){
		return;
	}
	last[x][y] = d; ans = max( ans, q[x][y] );

	for(int i=0; i<=d; i++){
		int dx = x+d-i, dy = y+i;
		if( dx >= 1100 || dy >= 1100 ){
			ans = N;
			break;
		}

		if( p[dx][dy] - p[x][y] > 0 ){
			rec( dx, dy, p[dx][dy] - p[x][y] );
		}
	}
}

int main(){
	scanf("%d",&N);

	int PS = 0;
	for(int i=0; i<N; i++){
		scanf("%d%d%d",&a,&b,&c);
		q[a-1][b-1] = -1;
		p[a-1][b-1] = -c;
		PS += c;
	}
	q[1100][1100] = N;
	p[1100][1100] = PS;
	for(int i=1100; i>=0; i--){
		for(int j=1100; j>=0; j--){
			q[i][j] += q[i+1][j] + q[i][j+1] - q[i+1][j+1];
			p[i][j] += p[i+1][j] + p[i][j+1] - p[i+1][j+1];
		}
	}
	assert( p[1][1] >= 0 );
	assert( q[1][1] >= 0 );

	rec(1,1,p[1][1]);
	assert( ans <= N );
	printf("%d",ans);
	return 0;
}