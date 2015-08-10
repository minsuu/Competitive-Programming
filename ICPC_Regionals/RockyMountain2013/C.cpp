// Aug 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int INF = 1987654321;
int N,T, x[55],y[55],z[55];
bool ys[55], colinear;

int main(){
	scanf("%d",&T);
	while(T--){
		colinear = true; memset( ys, 0, sizeof ys);
		scanf("%d",&N);

		for(int i=0; i<N; i++)
			scanf("%d%d%d",&x[i],&y[i],&z[i]);

		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				for(int k=j+1; k<N; k++){
					int a = +(y[k] - y[i]) * (z[j] - z[i]) -(z[k] - z[i]) * (y[j] - y[i]);
					int b = -(x[k] - x[i]) * (z[j] - z[i]) +(z[k] - z[i]) * (x[j] - x[i]);
					int c = +(x[k] - x[i]) * (y[j] - y[i]) -(y[k] - y[i]) * (x[j] - x[i]);
					if( a==0 && b==0 && c==0 )
						continue;
					colinear = false;

					int mx = -INF, mn = INF, sc = x[i]*a + y[i]*b + z[i]*c;
					assert( sc == x[j]*a + y[j]*b + z[j] * c);
					assert( sc == x[k]*a + y[k]*b + z[k] * c);
					for(int l=0; l<N; l++){
						mx = max( mx, x[l]*a + y[l]*b + z[l]*c );
						mn = min( mn, x[l]*a + y[l]*b + z[l]*c );
					}
					if( sc == mx || sc == mn ){
						ys[i] = ys[j] = ys[k] = true;
					}
				}
			}
		}
		for(int i=0; i<N; i++)
			printf("%c", ( ys[i] || colinear) ? 'T' : 'F');
		printf("\n");
	}
	return 0;
} 