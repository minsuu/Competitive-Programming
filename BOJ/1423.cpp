#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lld;

int N, str[55], K;
lld lev[55], cac[55][101][101];
lld rec(int i, int p, int r){
	if( i == N-1 ) return (lev[i]+p)*str[i];
	lld& ret = cac[i][p][r];
	if( ret != -1 ) return ret;
	
	lld l = lev[i] + p;
	for(int u=0; u<=min(l,(lld)r); u++){
		ret = max( ret, (l-u)*str[i] + rec( i+1, u, r-u ) ); 
	}
	return ret;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%lld",&lev[i]);
	for(int i=0; i<N; i++) scanf("%d",&str[i]);
	scanf("%d",&K);
	
	memset( cac, -1, sizeof cac );
	printf("%lld", rec(0,0,K) );
	return 0;
}
