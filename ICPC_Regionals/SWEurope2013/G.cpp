#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool adj2[111][111];
vvi adj;
int cnt[111][4], ani[111], N,a,b;

bool rec(int n){
	if( n == N ) return true;
	for(int i=0; i<4; i++){
		if(cnt[n][i] != 0 ) continue;
		ani[n] = i+1;
		for(auto j : adj[n])
			cnt[j][i]++;
		if( rec(n+1) ) return true;
		for(auto j : adj[n])
			cnt[j][i]--;
		ani[n] = -1;
	}
	return false;
}

int main(){
	scanf("%d",&N);
	vvi(N).swap(adj);
	memset( ani, -1, sizeof ani );

	while( scanf("%d-%d",&a,&b) == 2 ){
		a--; b--;
		if( adj2[a][b] ) continue;
		adj2[a][b] = adj2[b][a] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	rec( 0 );

	for(int i=0; i<N; i++){
		printf("%d %d\n",i+1,ani[i]);
	}
	return 0;
}