#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include "garden.h"
#include "gardenlib.h"
using namespace std;
const int MAXN=1e6;
int elast[MAXN], eprev[MAXN], eadj[MAXN], eind;
int bpath[MAXN][2], bpathn[MAXN];
int L[MAXN], C[MAXN];
void add_edge(int u, int v){
	eadj[eind]=v; eprev[eind]=elast[u]; elast[u]=eind++;
}
void count_routes(int N, int M, int P, int R[][2], int Q, int G[])
{
	for(int i=0;i<M;i++){
		int u=R[i][0], v=R[i][1];
		if(bpathn[u]<2) bpath[u][bpathn[u]++]=v;
		if(bpathn[v]<2) bpath[v][bpathn[v]++]=u;
	}
	for(int i=0;i<N;i++) if(bpathn[i]==1) bpath[i][1]=bpath[i][0], bpathn[i]++;
	memset( elast, -1, sizeof elast );
	// Vertex 0 to 2*N-1
	for(int u=0;u<N;u++){
		if(bpathn[u]==0) continue;
		int F=bpath[u][0], S=bpath[u][1];
		if(bpath[F][0]!=u) add_edge(F*2, u*2); else add_edge(F*2+1, u*2);
		if(bpath[S][0]!=u) add_edge(S*2, u*2+1); else add_edge(S*2+1, u*2+1);
	}
	memset( C, -1, sizeof C );
	queue<int> q; q.push(P*2); q.push(P*2+1);
	L[P*2]=L[P*2+1]=0; C[P*2]=P*2; C[P*2+1]=P*2+1;
	while(!q.empty()){
		int here=q.front(); q.pop();
		for(int i=elast[here];i!=-1;i=eprev[i]){
			int there=eadj[i];
			L[there]=L[here]+1; C[there]=C[here];
			if(there/2==P) continue;
			q.push(there);
		}
	}
	for(int i=0;i<Q;i++){
		int ans=0;
		for(int b=0;b<2*N;b+=2){
			int g=G[i], bb=b;
			if(C[bb]==-1) continue;
			g-=L[bb]; bb=C[bb];
			if(g>0){ g-=L[bb]; bb=C[bb]; }
			if(g>0){
				if(bb==C[bb] && L[bb]!=0){
					g%=L[bb];
				}else if(bb!=C[bb] && L[bb]!=0 && L[C[bb]]!=0){
					g%=(L[bb]+L[C[bb]]);
				}
			}
			while(g>0 && bb!=-1 && L[bb]!=0){
					g-=L[bb]; bb=C[bb];
			}
			if(g==0) ans++;
		}
		answer(ans);
	}
}