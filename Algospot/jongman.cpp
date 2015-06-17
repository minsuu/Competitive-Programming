#include <bits/stdc++.h>
using namespace std;

// successive shortest path MCMF algorithm : Given G(V, E, u, c, b), returns minimum cost
// time complexity : O(n^3B) where B = largest supply
const int MAXV = 222, MAXE = 22222, INF = 10000, DINF=987654321;
struct MCMF{
	int s, t, V, ret;
	int eind, eadj[2*MAXE], eprev[2*MAXE], ecap[2*MAXE], ecost[2*MAXE], pcost[2*MAXE];
	int elast[MAXV], dist[MAXV], dpre[MAXV], dedge[MAXV], visit[MAXV];
	inline void init( int v ){
		eind = 0; s = v; t = v+1; V = v+2;
		memset( elast, -1, sizeof elast );
	}
	inline void reduce(){
		for( int v=0; v<V; v++)
			for( int i=elast[v]; i!=-1; i=eprev[i] )
				pcost[i] = (i&1) ? 0 : ( pcost[i] + dist[v] - dist[eadj[i]] );
	}
	inline void addB( int v, int b ){
		if( b<0 ) addedge( v, t, 0, -b );
		else if( b>0 ) addedge( s, v, 0, b );
	}
    inline void addedge (int a, int b, int c, int cap1, int cap2 = 0) {
        eadj[eind] = b; ecost[eind] =  c; ecap[eind] = cap1; eprev[eind] = elast[a]; elast[a] = eind++;
        eadj[eind] = a; ecost[eind] = -c; ecap[eind] = cap2; eprev[eind] = elast[b]; elast[b] = eind++;
    }
    void BellmanFord(){
    	for( int i=0; i<V; i++) dist[i] = DINF; dist[s] = 0;
       	for( int i=1; i<V; i++){
       		for( int u=0; u<V; u++)
       			for( int j=elast[u]; j!=-1; j=eprev[j] ){
       				if( ecap[j] <= 0 ) continue;
       				int v=eadj[j];
       				dist[v] = min( dist[v], dist[u] + pcost[j] );
       			}
    	}
    }
    void Dijkstra(){
    	for( int i=0; i<V; i++) dist[i] = DINF; dist[s] = 0;
    	memset( visit, 0, sizeof visit); memset( dpre, -1, sizeof dpre);
    	while(1){
    		int mind = DINF, u;
    		for( int i=0; i<V; i++)
    			if( !visit[i] && mind>dist[i] ) mind=dist[i], u=i;
    		if( mind == DINF ) break;
    		visit[u] = 1;
    		for( int i=elast[u]; i!=-1; i=eprev[i] ){
    			if( ecap[i] <= 0 ) continue;
    			int v = eadj[i];
    			if( dist[v] > dist[u] + pcost[i] )
    				dist[v] = dist[u] + pcost[i], dpre[v] = u, dedge[v] = i;
    		}
    	}
    }
    int mincost(){
    	ret = 0; memcpy( pcost, ecost, eind * sizeof(int) );
    	BellmanFord(); reduce();
    	// for(int i=0; i<V; i++) printf("%d ",dist[i]); printf("\n");
    	while( 1 ){
    		Dijkstra();
        	// for(int i=0; i<V; i++) printf("%d ",dist[i]); printf("\n");
    		if( dist[t] == DINF ) break;
    		reduce();
    		int f = INF;
    		for( int i = t; i != s; i = dpre[i] )
    			f = min( f, ecap[dedge[i]] );
    		for( int i = t; i != s; i = dpre[i] ){
    			int e = dedge[i];
    			ecap[e] -= f; ecap[e^1] += f; ret+=ecost[e]*f;	
    		}
    	}
    	return ret;
    }
};
MCMF g;
int T, N,M, a,b,c;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		g.init(N*2);
		g.addB(1, -1); g.addB(3, -1); g.addB(4, 2);
		g.addedge(0, 1, 0, 1); g.addedge(2, 3, 0, 1); g.addedge(4, 5, 0, INF);
		for(int i=3;i<N;i++)
			g.addedge( i*2, i*2+1, 0, 1 );
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&a,&b,&c);
			g.addedge( a*2+1, b*2, c, INF );
			g.addedge( b*2+1, a*2, c, INF );
		}
		printf("%d\n",g.mincost());
	}
	return 0;
}