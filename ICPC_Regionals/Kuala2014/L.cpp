#include <bits/stdc++.h>
using namespace std;
const int MAXV = 333, MAXE = 100100, INF = 10000;
template <typename T> struct Dinic {
    int V, source, sink;
    int eind, eadj [2 * MAXE], eprev [2 * MAXE], elast [MAXV], start [MAXV];
    int front, back, q [MAXV], dist [MAXV];
    T CAPINF, ecap [2 * MAXE];
    int dfscount;
    inline Dinic () {
        V = -1;
        CAPINF = numeric_limits <T> :: max ();
    }
    inline void init (int v) {
        V = v; eind = 0;
        memset (elast, -1, V * sizeof (int));
        dfscount = 0;
    }
    inline void addedge (int a, int b, T cap1, T cap2) {
        eadj [eind] = b; ecap [eind] = cap1; eprev [eind] = elast [a]; elast [a] = eind++;
        eadj [eind] = a; ecap [eind] = cap2; eprev [eind] = elast [b]; elast [b] = eind++;
    }
    bool bfs () {
        memset (dist, 63, V * sizeof (int));
        front = back = 0;
        q [back++] = source; dist [source] = 0;
        while (front < back)
        {
            int top = q [front++];
            for (int i = elast [top]; i != -1; i = eprev [i])
            if (ecap [i] > 0 && dist [top] + 1 < dist [eadj [i]])
            {
                dist [eadj [i]] = dist [top] + 1;
                q [back++] = eadj [i];
            }
        }
        return dist [sink] < INF;
    }
    T dfs (int num, T pcap) {
        dfscount++;
        if (num == sink)
            return pcap;
        T total = 0;
        for (int &i = start [num]; i != -1; i = eprev [i])
            if (ecap [i] > 0 && dist [num] + 1 == dist [eadj [i]])
            {
                T p = dfs (eadj [i], min (pcap, ecap [i]));
                ecap [i] -= p;
                ecap [i ^ 1] += p;
                pcap -= p;
                total += p;
                if (pcap == 0)
                    break;
            }
        return total;
    }
    T flow (int _source, int _sink) {
        if (V == -1)
            return -INF;
        source = _source; sink = _sink;
        T total = 0;
        while (bfs ())
        {
            memcpy (start, elast, V * sizeof (int));
            total += dfs (source, CAPINF);
        }
        return total;
    }
};

char buf[222];
Dinic<int> D;
int main() {
    int T,N,M;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d",&N,&M);
		D.init( N+M+2 );
        int S = N+M, T = N+M+1;

		for(int i=0; i<N; i++)
			D.addedge( S, i, 1, 0 );
		for(int i=0; i<M; i++)
			D.addedge( N+i, T, 1, 0 );

		for(int i=0; i<N; i++){
			scanf("%s",buf);
			for(int j=0; j<M; j++){
				if( buf[j] == '1' ){
					D.addedge( i, N+j, INF, 0 ); 
				}
			}
		}
		printf("Case #%d: %d\n",t,D.flow(S,T));
    }
    return 0;
}
