#include <bits/stdc++.h>
using namespace std;
const int MV = 20100;
typedef vector<int> vi;

int T,N,a, wei[MV], gr[MV];
vi linkd[MV];

void dfs( int nw ){
	set<int> ngr;
	for( auto nv : linkd[nw] ){
		dfs( nv );
		ngr.insert( gr[nv] );
	}
	int c = 0;
	while( ngr.count(c) ) c++;
	gr[nw] = c;
}
int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			linkd[i].clear();
			gr[i] = -1;
		}
		for(int i=0; i<N; i++) scanf("%d",&wei[i]);
		for(int i=0; i<N; i++){
			scanf("%d",&a); if( a==0 ) continue;
			linkd[a-1].push_back( i );
		}
		dfs( 0 );
		
		int ans = 0;
		for(int i=0; i<N; i++){
			if( wei[i] % 2 ){
				ans ^= gr[i];
			}
		}
		printf("Case #%d: %s\n",t, (ans==0)? "second" : "first" );
	}
	return 0;
}
