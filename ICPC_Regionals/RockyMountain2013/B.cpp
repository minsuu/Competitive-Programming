// Aug 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXV = 2222;
const int MAXN = MAXV*2; // true, false vertex

bool linkd[MAXN][MAXN];
int V;
int disc[MAXN], low[MAXN], loop[MAXN], vCnt;
int sccId[MAXN], sCnt, sccSz[MAXN];
void tarjanSCC(){
    struct STE { int here, iter; };
    vCnt = sCnt = 0;
    memset( disc, -1, sizeof disc );
    memset( sccId, -1, sizeof sccId );
    memset( sccSz, 0, sizeof sccSz );
    for(int b=0; b<V; b++){
        if( disc[b] != -1 ) continue;
        stack<STE> st; stack<int> scc; st.push( { b, 0 } );
        while( !st.empty() ){
            int here = st.top().here, iter = st.top().iter; st.top().iter++;
            if( iter == 0 ){
                low[here] = disc[here] = vCnt++;
                scc.push( here );
            }
            if( iter == V ){
                st.pop();
                for( int there=0; there<V; there++){
                	if( !linkd[here][there] ) continue;
                    if( disc[here] < disc[there] ){ // tree edge
                        low[here] = min( low[here], low[there] );
                    } else if ( sccId[there] == -1 ){ // back edge, no-scc cross edge
                        low[here] = min( low[here], disc[there] );
                    }
                }
                if( low[here] == disc[here] ){ // new SCC!
                    while(1){
                        sccId[ scc.top() ] = sCnt;
                        sccSz[ sCnt ] ++;
                        if( scc.top() == here ) break;
                        scc.pop();
                    } sCnt++; scc.pop();
                } continue;
            }
            if( linkd[here][iter] && disc[iter] == -1 )
                st.push( { iter, 0 } );
        }
    }
}

int N,M,a,b;
int vk[MAXV]; // 1 : A, 2 : B, 3 : C, 4 : A/C, 5 : B/C
bool adj[MAXV][MAXV];
int main(){
	scanf("%d%d",&N,&M); V = N*2;
	for(int i=0; i<M; i++){
		scanf("%d%d",&a,&b); a--;b--;
		adj[a][b] = adj[b][a] = true;
	}
	for(int i=0; i<N; i++){
		if( adj[0][i] ) vk[i] = 4;
		else if( adj[1][i] ) vk[i] = 5;
		else vk[i] = 3;
	}
    vk[0] = 1; vk[1] = 2;

    for(int i=0; i<N; i++)
        printf("%d ",vk[i]);
    printf("\n");

	bool poss = true;
	for(int i=2; i<N && poss; i++){
		for(int j=i+1; j<N && poss; j++){
			if( !adj[i][j] ){
                if( vk[i] == vk[j] ){
                    if( vk[i] == 3 ){
                        poss= false;
                    }else{
                        // T->F and F->T
                        linkd[ i*2 ][ j*2+1 ] = linkd[ i*2+1 ][ j*2 ] = true;
                        linkd[ j*2 ][ i*2+1 ] = linkd[ j*2+1 ][ i*2 ] = true;
                    }
                }else{
                    if( vk[i] == 3 || vk[j] == 3 ){
                        // always T
                        if( vk[i] != 3 ){
                            linkd[ i*2+1 ][ i*2 ] = true;
                        }else{
                            linkd[ j*2+1 ][ j*2 ] = true;
                        }
                    }else{
                        // F->T
                        linkd[ i*2+1 ][ j*2 ] = linkd[ j*2+1 ][ i*2 ] = true;
                    }
                }
			}
		}
	}
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++)
            printf("%d ",linkd[i][j]);
        printf("\n");
    }
    tarjanSCC();
    for(int i=0; i<V; i++) printf("%d ",sccId[i]);
    printf("\n");

    for(int i=0; i<V && poss; i+=2)
        if( sccId[i] == sccId[i+1] )
            poss = false;

    if( !poss ) printf("impossible\n");
    else{
        vector< pair<int,int> > sorted;
        vector< int > tfs(N, -1);

        for(int i=0; i<V; i++)
            sorted.push_back( { -sccId[i], i } );
        for(auto it : sorted){
            if( tfs[ it.second/2] != -1 ) continue;
            tfs[ it.second/2 ] = it.second%2;
        }
        for(auto it : tfs ) printf("%d ",it);
    }
	return 0;
}