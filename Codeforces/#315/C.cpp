// Aug 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
const int MAXV = 444;

int V;
int disc[MAXV], low[MAXV], loop[MAXV], vCnt;
int sccId[MAXV], sCnt, sccSz[MAXV];
vvi linkd;

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
            if( iter == linkd[here].size() ){
                st.pop();
                for( auto there : linkd[here] ){
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
            int there = linkd[here][iter];
            if( disc[there] == -1 )
                st.push( { there, 0 } );
        }
    }
}

char alp[33], word[222], b1[5],b2[5];
vector<string> cand;
int N,M, a,b;
int svc[222][222];

int main(){
	scanf("%s",alp);
	scanf("%d%d",&N,&M); V = N*2;
	vvi(V).swap(linkd); 
	for(int i=0; i<M; i++){
		scanf("%d%s%d%s",&a,b1,&b,b2); a--; b--;
		a = a*2 + (b1[0] == 'C');
		b = b*2 + (b2[0] == 'C');
		linkd[a].push_back(b);
	}
	scanf("%s",word);

	tarjanSCC();
	for(int i=0; i<N; i++)
		if( sccId[i*2] == sccId[i*2+1] ){
			printf("-1"); return 0;
		}

	for(int i=0; i<sCnt; i++){
		for(int j=0; j<V; j++){
			if( sccId[j] == i ){
				svc[i][j/2] |= 1<<(j%2);
				for(auto k : linkd[j]){
					for(int l=0; l<V; l++){
						svc[i][l] |= svc[ sccId[k] ][l];
					}
				}
			}
		}
	}
	
	return 0;
}