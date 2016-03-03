#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int N,K, b[1111111], c[1111111], d[1111111];
pair<int,int> a[1111111];
long long L;
typedef vector<int> vi;
vector<vi> p; // length (i-1), last jth element
int main(){
	scanf("%d%lld%d",&N,&L,&K);
	for(int i=0; i<N; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort( a, a+N );
	for(int i=0; i<N; i++){
		d[ a[i].second ] = i;
	}

	int l = 0, r = 0;
	for( ; l < N; l++ ){
		for( ; r < N && a[r].first <= a[l].first; r++ );
		b[l] = r;
	}
	vector<vi>( K, vi(N) ).swap(p);
	for(int j=0; j<N; j++){
		p[0][j] = 1;
		c[0] = ( c[0] + 0LL + p[0][j] ) % MOD;
	}
	for(int i=1; i<K; i++){
		int psum = 0; r = 0;
		for(int j=0; j<N; j++){
			for( ; r < b[j] ; r++) psum = ( psum + 0LL + p[i-1][r] ) % MOD;
			p[i][j] = psum;
			c[i] = ( c[i] + 0LL + p[i][j] ) % MOD;
		}
	}
	int ans = 0; long long cpl = L/N;
	for(int i=0; i<K; i++){
		int l = i+1;
		long long rpt = max( 0LL, cpl - l + 1 ) % MOD;
		ans = ( ans + c[i] * 1LL * rpt % MOD ) % MOD;
	}
	for(int i=0; i<L%N; i++){
		int ri = d[i];
		for(int j=0; j<min( (long long)K, cpl+1); j++){
			ans = ( ans + 0LL + p[j][ri] ) % MOD;
		}
	}
	printf("%d",ans);
	return 0;
}
