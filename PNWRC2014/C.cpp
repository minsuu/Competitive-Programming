#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1111, MAXE = 9999, INF = 10000;
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
        //printf("dfscount = %d\n", dfscount);
        return total;
    }
};
 
inline int ind(int x,int y,int z) { return 100*x + 10*y + z; }
int T,N;
Dinic<int> D;

int main(){
	scanf("%d",&T);
	while(T--){
		D.init( 1002 );
		int s = 1000, t = 1001;
		for(int x=0; x<10; x++){
			for(int y=0; y<10; y++){
				for(int z=0; z<9; z++){
					D.addedge( ind(x,y,z), ind(x,y,z+1), 1,1);
					D.addedge( ind(x,z,y), ind(x,z+1,y), 1,1);
					D.addedge( ind(z,x,y), ind(z+1,x,y), 1,1);
				}
				D.addedge( ind(0,x,y), t, 1,0);
				D.addedge( ind(9,x,y), t, 1,0);
				D.addedge( ind(x,0,y), t, 1,0);
				D.addedge( ind(x,9,y), t, 1,0);
				D.addedge( ind(x,y,0), t, 1,0);
				D.addedge( ind(x,y,9), t, 1,0);
			}
		}

		scanf("%d",&N);
		for(int i=0; i<N; i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			D.addedge( s, ind(x,y,z), 6, 0);
		}
		printf("%d\n", D.flow(s,t) );
	}
	return 0;
}
