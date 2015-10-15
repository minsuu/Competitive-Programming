// Oct 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int a[333][333], d[333][333];
int T,N;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1; i<=N; i++)
			for(int j=1; j<=i; j++)
				scanf("%d",&a[i][j]);
		for(int i=N+1; i<2*N; i++)
			for(int j=i-N+1; j<=N; j++)
				scanf("%d",&a[i][j]);
		for(int i=0; i<2*N; i++){
			for(int j=0; j<=N; j++){
				d[i][j] = max( d[i-1][j-1], d[i-1][j] ) + a[i][j];
			}
		}
		printf("%d\n",d[2*N-1][N]);
	}
	return 0;
} 