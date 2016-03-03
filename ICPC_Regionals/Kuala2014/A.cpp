#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

long long dst[1010];
int edgs[2010][3], reach[1010];
vector<int> linkd[1010];

int main(){
    int T;
    scanf("%d", &T);
    int tt;
    for(tt = 1; tt <= T; tt++){
        int N, M;
        scanf("%d%d", &N, &M);
        int i, j;
		for(i = 0; i < N; i++) linkd[i].clear(), reach[i] = 0;

        for(i = 0; i < M; i++){
            scanf("%d%d%d", &edgs[i][0], &edgs[i][1], &edgs[i][2]);
			linkd[ edgs[i][1] ].push_back( edgs[i][0] );
        }
		
		queue<int> que; que.push( 0 );
		reach[ 0 ] = 1;

		while(!que.empty()){
			int nw = que.front(); que.pop();
			for( auto nx : linkd[nw] ){
				if( reach[nx] == 0 ){
					reach[nx] = 1;
					que.push( nx );
				}
			}
		}

        for(i = 0; i < N; i++) dst[i] = INF;
        dst[0] = 0;
  
        bool ans = false;
        for(i = 0; i < N; i++){
            for(j = 0; j < M; j++){
                if(dst[edgs[j][0]] < INF){
                    long long now = dst[edgs[j][0]] + edgs[j][2];
                    if(now < dst[edgs[j][1]]) dst[edgs[j][1]] = now;
                }
            }
        }
		if( dst[0] < 0 ) ans = true;
		if(!ans){
			for(j = 0; j < M; j++){
				assert( dst[edgs[j][0]] < INF );
				long long now = dst[edgs[j][0]] + edgs[j][2];
				if( now < dst[edgs[j][1]] ){
					if( reach[edgs[j][1]] ){
						ans = true; break;
					}
				}
			}
		}
        printf("Case #%d: %s\n", tt, ans ? "possible" : "not possible");
    }
    return 0;
}
