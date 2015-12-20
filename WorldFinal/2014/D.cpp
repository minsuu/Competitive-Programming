#include <bits/stdc++.h>
using namespace std;

int N,M, adj[33][33];
char cand[33];
vector<int> opt[33];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&M);
		for(int j=0; j<M; j++){
			scanf( "%s",cand );
			int rr = 0;
			for(int k=0; cand[k]!='\0'; k++){
				rr |= 1 << ( cand[k] - 'a' );
			}
			opt[i].push_back( rr );
		}
	}
	
	memset( adj, -1, sizeof adj );
	for(int d=0; d<N; d++){
		adj[d][d] = 0;
		int av = 1 << d, nav = av;
		for(int i=1; i<N; i++){
			for(int j=0; j<N; j++){
				if( adj[j][d] != -1 ) continue;
				for( auto k : opt[j] ){
					if( ( k & (~av) ) == 0 ){
						adj[j][d] = i;
						nav |= 1 << j;
						break;
					}
				}
			}
			av = nav;
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	return 0;
}
