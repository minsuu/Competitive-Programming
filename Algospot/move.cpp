// Oct 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<long long,int> ii;

int T,N,M,a,b,c; long long d[11111];
vector<ii> linkd[11111];
priority_queue<ii> pq;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(int i=0; i<N; i++) linkd[i].clear();
		for(int i=0; i<M; i++){
			scanf("%d%d%d",&a,&b,&c);
			linkd[a].push_back( { c, b } );
			linkd[b].push_back( { c, a } );
		}
		memset( d, -1, sizeof d );
		pq.push( { 0, 0 } ); d[0] = 0;
		while( !pq.empty() ){
			long long nc = -pq.top().F; int nw = pq.top().S; pq.pop();
			if( d[nw] < nc ) continue;
			for( auto it : linkd[nw] ){
				if( d[it.S] == -1 || nc + it.F < d[it.S] ){
					d[it.S] = nc + it.F;
					pq.push( {-d[it.S], it.S} );
				}
			}
		}
		printf("%lld\n",d[N-1]);
	}	
	return 0;
} 