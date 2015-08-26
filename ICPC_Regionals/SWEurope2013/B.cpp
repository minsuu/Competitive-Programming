#include <bits/stdc++.h>
using namespace std;
typedef long long Weight;
const long long INF = numeric_limits<Weight>::max();
struct NetworkFlow{
	struct Edge{
		int to; unsigned next;
		Weight cap, flow;
		Edge(int to, Weight cap, unsigned next = ~0) :
			to(to), next(next), cap(cap), flow(0) {}
		inline Weight res() const { return cap-flow; }
	};
	int V;
	vector<unsigned> G;
	Weight totalFlow;
	vector<Edge> edges;
	NetworkFlow(int V) : V(V), G(V, ~0), totalFlow(0) {}

	void clear(){
		for( auto& it : edges ){
			it.flow = 0;
		}
	}
	void addEdge(int a,int b, Weight cab, Weight cba = 0 ){
		edges.push_back( Edge(b, cab, G[a]) ); G[a] = edges.size() - 1;
		edges.push_back( Edge(a, cba, G[b]) ); G[b] = edges.size() - 1;
	}
	vector<int> d; //distance
	vector<unsigned> p;

	bool levelGraph(int S, int T){
		queue<int> q; q.push(S);
		d = vector<int>(V, -1);
		d[S] = 0;
		while(!q.empty() && d[T] == -1 ){
			int u = q.front(); q.pop();
			for(unsigned i = G[u]; i!= ~0u; i = edges[i].next){
				Edge &e = edges[i]; int v = e.to;
				if(e.res() >0 && d[v] == -1) { d[v] = d[u] + 1; q.push(v); }
			}
		}
		return d[T] != -1;
	}
	Weight pushFlow(int u, int T, Weight amt) {
		if(!amt || u == T ) return amt;
		for(unsigned &i = p[u]; i != ~0u; i = edges[i].next){
			Edge &e = edges[i], &rev = edges[i^1];
			int v = e.to;
			if(e.res() > 0 && d[u] + 1 == d[v] ){
				Weight f = pushFlow(v, T, min(e.res(), amt) );
				if( f>0 ){
					e.flow += f, rev.flow -= f;
					return f;
				}
			}
		}
		return 0;
	}
	Weight maxFlow(int S, int T){
		totalFlow = 0;
		while( levelGraph(S, T) ){
			p = G;
			while(Weight f = pushFlow(S, T, numeric_limits<Weight>::max()))
				totalFlow += f;
		}
		return totalFlow;
	}
};

int T,N,M, a;
int bg[1111], en[111], cl[111];
int main(){
	scanf("%d",&T);
	for(int tt=1; tt<=T; tt++){
		scanf("%d%d",&N,&M);
		Weight sm = 0;
		for(int i=0; i<N; i++){
			scanf("%d%d%d",&bg[i],&en[i],&cl[i]);
			cl[i] = ( cl[i] + M - 1 ) / M;
			sm += cl[i];
		}
		int s = 2*N, t = 2*N + 1, sc = 2*N+2, st = 2*N+3;

		NetworkFlow fl( 2*N + 4 );
		for(int i=0; i<N; i++){
			fl.addEdge(   s,   i, cl[i] );
			fl.addEdge(   i,  sc, INF );
			fl.addEdge(  st, i+N, INF );
			fl.addEdge( i+N,   t, cl[i] );
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d",&a);
				if( i == j ) continue;
				if( en[i] + a < bg[j] ){
					fl.addEdge( i, j+N, INF );
				}
			}
		}
		fl.addEdge( sc, st, 0 );
		int me = (int) fl.edges.size() - 2;
		int lo = 0, hi = sm;
		while( lo + 1 < hi ){
			int mid = ( lo + hi ) / 2;
			fl.clear();
			fl.edges[me].cap = mid;
			Weight ff = fl.maxFlow(s, t);
			if( ff == sm )
				hi = mid;
			else
				lo = mid;
		}
		printf("Case %d: %d\n",tt,hi);
	}
	return 0;
}