#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int T,N, b[111], d[111][111]; // [i, j) :: 1 : one-kill 2 : lose 3 : win
inline int calc(int st, int rem){
	if( st==1 ) return 2;
	if( st==2 ) return (rem%2==1) ? 2 : 3;
	if( st==3 ) return (rem%2==1) ? 3 : 2;
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<N; i++)
			scanf("%d",&b[i]);
		memset( d, 0, sizeof d );
		for(int l=1; l<=N; l++){
			for(int i=0; i<N-l+1; i++){
				int val = false;
				for(int j=i; j<i+l; j++){
					if( b[j] == 1 ) val = true;
				}
				if( !val ) continue;
				for(int j=i; j<i+l; j++){
					int le = ( j==i )? -INF : b[j-1];
					int ri = ( j==i+l-1 )? -INF : b[j+1];
					if( le < b[j] && ri < b[j] ){ // can be selected
						if( b[j] == 1 ){ // one-kill!
							d[i][i+l] = 1; break;
						}
						if( !d[i][j] ){ // one in right
							d[i][i+l] = max( d[i][i+l], calc( d[j+1][i+l], j-i) );
						}else if( !d[j+1][i+l] ){ // one in left
							d[i][i+l] = max( d[i][i+l], calc( d[i][j], i+l-j-1) );
						}
					}
				}
			}
		}
		printf("%d %d\n",d[0][N], d[0][N-1]);
		if( d[0][N] == 1 || d[0][N] == 3 ) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}