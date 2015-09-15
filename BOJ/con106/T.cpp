#include <bits/stdc++.h>
using namespace std;

int av[1<<16][161];
int N, st[22];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&st[i]);
	}
	av[0][0] = 1;
	for(int i=1; i<(1<<N); i++){
		av[i][0] = 1;
		int j;
		for( j=N-1; j>=0; j-- )
			if( i & (1<<j) ) break;

		int l = i ^ (1<<j);
		for( int k = 1; k<=160; k++ ){
			av[i][k] = av[l][k];
			if( k==st[j] ) av[i][k]++;
			if( k>st[j] ) av[i][k] = max( av[i][k], av[l][k-st[j]] );
		}
	}
	for(int i=0; i<=160; i++){
		printf("%d ", av[(1<<N)-1][i]);
	}
	return 0;
}