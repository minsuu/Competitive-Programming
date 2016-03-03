#include <bits/stdc++.h>
using namespace std;

int N, col[510], adj[510][510], rem;

void dfs( int u, int cc ){
	for(int v=0; v<N; v++){
		if( adj[u][v] == 0 ){
			if( col[v] == -1 ){
				rem -- ;
				adj[u][v] = adj[v][u] = cc;
				col[v] = col[u]^1;
				dfs( v, cc );
			}else if( col[u] != col[v] ){
				rem -- ;
				adj[u][v] = adj[v][u] = cc;
			}
		}
	}
}

int main(){
	freopen("avia2.in","r", stdin );
	freopen("avia2.out","w", stdout );
	
	printf("started\n");

	scanf("%d",&N);
	rem = N*(N-1)/2;
	for(int cc=1; rem; cc++){
		memset( col, -1, sizeof col );
		col[0] = 1;
		dfs( 0, cc );
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ",adj[i][j]);
		} printf("\n");
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
