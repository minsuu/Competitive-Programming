#include <bits/stdc++.h>
using namespace std;
const int MAXV = 333333;
const long long INF = 987654321987654321;
typedef long long lld;
typedef pair<lld,int> ii;
struct EDGE{
	int fr, to, co, num;
};

int N,M,S, a,b,c, visited[MAXV];
lld dist[MAXV]; int last[MAXV];

vector<EDGE> ed[MAXV]; EDGE edges[MAXV];
priority_queue<ii> pq;
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&a,&b,&c); a--; b--;
		ed[a].push_back({ a, b, c, i });
		ed[b].push_back({ b, a, c, i });
		edges[i] = { a, b, c, i };
	} scanf("%d",&S); S--;
	// Dijkstra
	for(int i=0;i<N;i++) dist[i] = INF;
	pq.push({0, S}); dist[S] = 0LL;
	while(!pq.empty()){
		int here = pq.top().second; pq.pop();
		if( visited[here] ) continue;
		visited[here] = 1;
		for(EDGE& e : ed[here])
			if( !visited[e.to] ){
				if( dist[e.to] > dist[here]+e.co ){
					dist[e.to] = dist[here]+e.co, last[e.to] = e.num;
				}else if( dist[e.to] == dist[here]+e.co)
					last[e.to] = ( edges[last[e.to]].co > e.co ) ? e.num : last[e.to];
				pq.push({-(dist[here]+e.co), e.to});
			}
	}
	lld ans = 0LL; vector<int> ansv;
	for(int i=0; i<N; i++){
		if( i == S ) continue;
		ans += edges[last[i]].co;
		ansv.push_back( last[i] + 1 );
	} sort( ansv.begin(), ansv.end() );
	printf("%lld\n",ans);
	for(auto it : ansv) printf("%d ",it);
	return 0;
}