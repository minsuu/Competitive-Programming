#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long lld;
typedef vector<int> vi;
typedef vector<lld> vl;
typedef vector<vi> vvi;
const int MAXV = 111;
const int INF = 987654321;

vvi adj; vi dist, visited; vl spath1, spath2;

lld gcd(lld a,lld b)
{
    if(a && b)
        while(a%=b^=a^=b^=a);
    return a+b;
}
struct R{
	lld a,b;
	R ( lld _a = 0, lld _b = 1 ) : a(_a), b(_b) { }
	R operator+(const R& r) const{
		lld g = gcd(b,r.b);
		return R(a*r.b/g + r.a*b/g , b/g*r.b).reduce();
	}
	R operator/(const int& r) const{
		return R(a, b*r).reduce();
	}
	R reduce(){
		lld g = gcd(a,b);
		assert( b/g != 0);
		return R(a/g, b/g);
	}
};

int main(){
	int T, N,M,L, a,b,c;
	cin>>T;
	while(T--){
		cin>>N>>M>>L;
		vvi(N, vi(N, INF)).swap(adj); vi(N, INF).swap(dist);
		vi(N).swap(visited); vl(N).swap(spath1); vl(N).swap(spath2);
		for(int i=0; i<M; i++){
			scanf("%d%d%d",&a,&b,&c);
			a--; b--; adj[a][b] = adj[b][a] = c;
		}
		dist[0] = 0; vi ord;
		while(1){
			int mini = INF, here;
			for(int i=0; i<N; i++)
				if(!visited[i] && dist[i] < mini )
					mini = dist[i], here = i;
			if(mini == INF || here == N-1) break;
			ord.push_back(here); visited[here] = 1;
			for(int there=0; there<N; there++)
				dist[there] = min( dist[there], dist[here] + adj[here][there] );
		}
		assert( dist[N-1] != INF );
		ord.push_back(N-1);	spath1[0]=spath2[N-1]=1;
		for(auto it = ord.begin(); it!=ord.end(); ++it ){
			int here = (*it);
			for(int there=0; there<N; there++)
				if( dist[there] == dist[here] + adj[here][there] )
					spath1[there] = spath1[here] + spath1[there];
		}
		for(auto it = ord.rbegin(); it!=ord.rend(); ++it ){
			int there = (*it);
			for(int here=0; here<N; here++)
				if( dist[there] == dist[here] + adj[here][there] )
					spath2[here] = spath2[here] + spath2[there];
		}
		for(int i=0; i<L; i++){
			scanf("%d",&c); c--;
			lld a = spath1[c]*spath2[c], b = spath2[0], g = gcd(a,b);
			printf("%lld/%lld\n", a/g, b/g );
		}
	}
	return 0;
}