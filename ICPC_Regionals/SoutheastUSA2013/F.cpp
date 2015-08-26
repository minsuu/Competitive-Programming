// Aug 12 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int MAXN = 111111;
int x[MAXN], y[MAXN], z[MAXN], ox, oy, oz;
map<long long, vi> blocks;
int N; long long K;

inline long long bnum( int a, int b, int c ){
	return a + b * 13LL + c * 2999LL;
}
int main(){
	while(1) {
		scanf("%d%lld",&N,&K); blocks.clear();
		if( N==0 && K==0 ) break;
		for(int i=0; i<N; i++){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			ox = min( ox, x[i] );
			oy = min( oy, y[i] );
			oz = min( oz, z[i] );
		}
		for(int i=0; i<N; i++){
			int a = ( x[i] - ox ) / K;
			int b = ( y[i] - oy ) / K;
			int c = ( z[i] - oz ) / K;
			blocks[ bnum(a,b,c) ].push_back(i);
		}

		long long KSQ = K * K; int ans = 0;
		for(int i=0; i<N; i++){
			int ia = ( x[i] - ox ) / K;
			int ib = ( y[i] - oy ) / K;
			int ic = ( z[i] - oz ) / K;
			for( int j=ia-1; j<=ia+1; j++){
				for(int k=ib-1; k<=ib+1; k++){
					for(int l=ic-1; l<=ic+1; l++){
						if( blocks.count( bnum(j,k,l)) ){
							for(auto it : blocks[ bnum(j,k,l) ] ){
								if( it == i ) continue;
								long long dst = ( x[it] - x[i] ) * 1LL * ( x[it] - x[i] ) + 
												( y[it] - y[i] ) * 1LL * ( y[it] - y[i] ) +
												( z[it] - z[i] ) * 1LL * ( z[it] - z[i] );
								if( dst < KSQ )
									ans++;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}