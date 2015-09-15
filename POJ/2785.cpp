// Aug 28 2015, minsu( github : https://github.com/minsuu/ )
#include <cstdio>
#include <algorithm>
using namespace std;
int N, a[4444], b[4444], c[4444], d[4444];
int cd[4444*4444];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cd[i*N + j] = c[i] + d[j];
		}
	}
	sort( cd, cd+N*N );
	long long ans = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int fcd = -(a[i]+b[j]);
			ans += upper_bound( cd, cd+N*N, fcd ) - lower_bound( cd, cd+N*N, fcd );
		}
	}
	printf("%lld",ans);
	return 0;
}