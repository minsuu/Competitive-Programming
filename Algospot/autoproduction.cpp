// Sep 08 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int T,N, B[22][22], R[22], C[22];
bool decision( int a ){
	int T = 10;
	for(int i=0; i<N; i++){
		int r = R[i] * a;
		for(int j=0; j<C[i] && 0<r; j++, T--)
			r -= B[i][j];
		if( 0 < r || T < 0 ) return false;
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			scanf("%d%d",&R[i],&C[i]);
			for(int j=0; j<C[i]; j++)
				scanf("%d",&B[i][j]);
			sort( B[i], B[i] + C[i], greater<int>() );
		}
		int lo = 0, hi = 11111;
		while( lo + 1 < hi ){
			int m = ( lo + hi ) /2;
			if( decision(m) ){
				lo = m;
			}else{
				hi = m;
			}
		}
		printf("%d\n",lo);
	}
	return 0;
} 