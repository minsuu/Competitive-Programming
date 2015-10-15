#include <bits/stdc++.h>
using namespace std;
const long long MAGIC = 9999999999971LL;
typedef long long lld;
int T,N,M;
int r[111][3],x,y;
set< pair<lld, lld> > hset;
inline bool crs(int i, int x, int y){
	return r[i][0] * 1LL * x + r[i][1] * 1LL * y + r[i][2] > 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(int i=0; i<N; i++){
			scanf("%d%d%d",&r[i][0],&r[i][1],&r[i][2]);
		}
		int sz = 1;
		for(int i=0; i<N; i++){
			sz++;
			for(int j=0; j<i; j++){
				if( r[i][0] * 1LL * r[j][1] != r[i][1] * 1LL * r[j][0] )
					sz++;
			}
		}
		
		set< pair<lld, lld> >().swap(hset);
		for(int i=0; i<M; i++){
			scanf("%d%d",&x,&y);
			long long h1 = 0, h2 = 0;
			for(int j=0; j<min(50, N); j++){
				h1 = h1*2 + crs(j, x, y);
			}
			for(int j=min(50,N); j<N; j++){
				h2 = h2*2 + crs(j, x, y);
			}
			hset.insert( {h1, h2} );
		}

		if( hset.size() == sz ) printf("PROTECTED\n");
		else printf("VULNERABLE\n");
	}
	return 0;
}