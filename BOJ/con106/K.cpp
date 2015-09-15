#include <bits/stdc++.h>
using namespace std;

int N,K, s[55];
long long av[55555][11];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&K);
	sort( s, s+N );

	long long ans = 0LL;
	av[0][0] = 1LL;
	for(int i=0; i<N; i++){
		for(int j = s[i]+1; j<=50010; j++ ){
			ans += av[j][K-1];
		}
		for(int k=K-2; k>=1; k--){
			for(int j=s[i]; j<= s[i] + 50010; j++ ){
				av[ min(50010, j) ][k+1] += av[ j - s[i] ][k];
			}
		}
		av[ s[i] ][1]++;
	}
	printf("%lld",ans);
	return 0;
}