// Oct 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int T,N,M, adj[33][33], vs[33]; char buf[9];
vector<int> order; priority_queue<int> pq;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		memset( adj, 0, sizeof adj ); order.clear();
		memset( vs, 0, sizeof vs ); priority_queue<int>().swap(pq);

		for(int i=0; i<M; i++){
			scanf("%s",buf);
			adj[ buf[0] - 'A' ][ buf[1] - 'A' ] = 1;
			vs[ buf[1] - 'A' ]++;
		}
		for(int i=0; i<N; i++)
			if( vs[i] == 0 ) pq.push( -i );

		for(int i=0; i<N; i++){
			int nw = -pq.top(); pq.pop();
			for(int j=0; j<N; j++){
				if( adj[nw][j] ){
					vs[j]--;
					if( vs[j] == 0 ) pq.push( -j );
				}
			}
			order.push_back( nw );
		}

		string ans;
		for(auto it : order)
			ans.push_back( it+'A' );
		printf("%s\n",ans.c_str());
	}
	return 0;
} 