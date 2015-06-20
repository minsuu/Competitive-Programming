// Jun 19 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N; long long ans, K, k;
int main(){
	scanf("%d",&N);
	for(K=k=1; K<=N; K*=10, k++); K/=10; k--;
	while( K ){
		ans += k * 1LL * ( N - K + 1 );
		N = K-1; K/=10; k--;
	}
	printf("%lld",ans);
	return 0;
} 