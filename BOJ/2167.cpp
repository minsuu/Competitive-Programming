#include <bits/stdc++.h>
using namespace std;
int N,M,K,q,w,e,r, a[303][303], p[303][303];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++){
			scanf("%d",&a[i][j]);
			p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
		}
	scanf("%d",&K);
	while( K-- ){
		scanf("%d%d%d%d",&q,&w,&e,&r); q--; w--;
		printf("%d\n",p[e][r] - p[e][w] - p[q][r] + p[q][w] );
	}
	return 0;
}
