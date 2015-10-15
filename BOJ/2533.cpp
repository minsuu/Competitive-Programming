#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 987654321;

int N,a,b;
vvi linkd;
int cache[1111111][2];

int dfs(int u, int p, bool up ){
	int& ret = cache[u][up];
	if( ret != -1 ) return ret;
	ret = INF;

	if( up ){
		int sum = 0;
		for( auto it : linkd[u] ){
			if( it == p ) continue;
			sum += dfs( it, u, 0 );
		}
		ret = min( ret, sum );
	}

	int sum = 1;
	for( auto it : linkd[u] ){
		if( it == p ) continue;
		sum += dfs( it, u, 1 );
	}
	ret = min( ret, sum );

	return ret;
}

int main(){
	memset( cache, -1, sizeof cache );
	scanf("%d",&N);
	vvi(N).swap(linkd);
	for(int i=1; i<N; i++){
		scanf("%d%d",&a,&b); a--;b--;
		linkd[a].push_back(b);
		linkd[b].push_back(a);
	}
	printf("%d\n",min( dfs(0,-1,0), dfs(0,-1,1) ) );
	return 0;
}