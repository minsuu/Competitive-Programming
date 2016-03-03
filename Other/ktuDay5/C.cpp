#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2222;
typedef vector<int> vi;
int adj[MAXN][MAXN];
int N,M, aMatch[MAXN], bMatch[MAXN], disc[MAXN];

bool dfs(int a){
	if(disc[a]) return false;
	disc[a] = 1;
	for(int b = 0; b<M; b++){
		if( adj[a][b] )
			if( bMatch[b]==-1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
	}
	return false;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d",&adj[i][j]);
			adj[i][j] ^= 1;
		}
	}
	memset( aMatch, -1, sizeof aMatch );
	memset( bMatch, -1, sizeof bMatch );
	memset( disc, 0, sizeof disc );
	int ans = 0;
	for(int st=0; st<N; st++){
		memset( disc, 0, sizeof disc );
		if( dfs(st) ) ans ++;
	}
	
	if( N+M-ans <= max(N,M) ){
		printf("0 0\n");
		return 0;
	}

	vector<bool> aChosen(N, true), bChosen(M, false);	
	for(int i=0; i<M; i++) if(bMatch[i]==-1) bChosen[i]=true;

	while(true){
		bool changed = false;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				if( aChosen[i] && bChosen[j] && adj[i][j] ){
					aChosen[i] = false;
					bChosen[aMatch[i]] = true;
					changed = true;
				}
		if(!changed) break;
	}
	
	int ac = 0, bc = 0;
	vector<int> nac, nbc;

	for(int i=0; i<N; i++){
		if( aChosen[i] == 0 ) ac++;
	}
	for(int i=0; i<M; i++){
		if( bChosen[i] == 0 ) bc++;
	}
	
	for(int i=N-ac; i<N; i++){
		if( aChosen[i] ) nac.push_back( i );
	}
	for(int i=M-bc; i<N; i++){
		if( bChosen[i] ) nbc.push_back( i );
	}

	printf("%d %d\n", N-ac, N-bc );
	printf("%d\n", nac.size() + nbc.size() );
	
	for(int i=0; i<N-ac; i++){
		if( aChosen[i] == 0 ) printf("R %d %d\n", i+1, nac.back()+1 );
		nac.pop_back();
	}
	for(int i=0; i<N-bc; i++){
		if( bChosen[i] == 0 ) printf("C %d %d\n", i+1, nbc.back()+1 );
		nbc.pop_back();
	}
	
	return 0;
}
