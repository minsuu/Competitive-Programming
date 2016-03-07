#include <bits/stdc++.h>
using namespace std;

int T,N,M;
int vec[111][10], f[10];
int get(){
	int sum = 0;
	for(int i=0; i<N; i++){
		int m = 0, s = 0;
		for(int j=0; j<M; j++){
			s += vec[i][f[j]];
			m = max(m, s);
		}
		sum += m;
	} return sum;
}
int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d",&N,&M);
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
				scanf("%d",&vec[i][j]);
		for(int i=0; i<M; i++)
			f[i] = i;
		int ans = 0;
		do{
			ans = max( ans, get() );
		}while( next_permutation(f, f+M) );
		printf("Case #%d: %d\n",t, ans);
	}
	return 0;
}
