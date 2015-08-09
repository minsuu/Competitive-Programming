// Aug 09 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int K,N, Ri[1<<11];
ld win[11][1<<11];

ld prob( int p, int q ){
	return 1.0 / ( 1.0 + pow( 10.0, ((ld) Ri[q] - Ri[p]) / 400.0 ) );
}

int main(){
	scanf("%d",&K); N = 1<<K;
	for(int i=0; i<N; i++) scanf("%d",&Ri[i]);

	for(int i=0; i<N; i++) win[0][i] = 1.0;

	for(int i=1; i<=K; i++){
		for(int j=0; j<N; j++){
			int sz = 1 << (i-1);
			int bg = ( j ^ sz ) & ( ~( sz - 1 ) );
			for(int k=bg; k<bg+sz; k++){
				win[i][j] += win[i-1][k] * prob( j, k);
			} win[i][j] *= win[i-1][j];
		}
	}
	for(int i=0; i<N; i++)
		printf("%.10Lf\n", win[K][i]);
	return 0;
} 