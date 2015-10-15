#include <bits/stdc++.h>
using namespace std;
int N,K,X, mx;
int an[222222], cn[222222];
int ror[222222], lor[222222];

int main(){
	scanf("%d%d%d",&N,&K,&X);
	for(int i=0; i<N; i++){
		scanf("%d",&an[i]);
		int k = an[i];
		while( k ){
			cn[i]++;
			k/=2;
		}
		mx = max( cn[i], mx );
	}
	for(int i=0; i<N; i++){
		lor[i] = (i ? lor[i-1] : 0 ) | an[i];
	}
	for(int i=N-1; i>=0; i--){
		ror[i] = (i==N-1 ? 0 : ror[i+1] ) | an[i];
	}
	long long ans = 0LL;
	for(int i=0; i<N; i++){
		if( cn[i] == mx ){
			long long na = ( i? lor[i-1] : 0 ) | ( i==N-1 ? 0 : ror[i+1] );
			long long k = an[i];
			for(int j=0; j<K; j++)
				k *= X;
			na |= k;
			ans = max( ans, na );
		}
	}
	printf("%lld",ans);
	return 0;
}