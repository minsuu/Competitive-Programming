// Aug 28 2015, minsu( github : https://github.com/minsuu/ )
#include <cstdio>
#include <algorithm>
using namespace std;
const int BSZ = 1000;
int N,M, bn, l,r,k;
int a[111111], b[111111], s[111111];

// in [l, r], numbers lower than n >= k?
bool decision( int n ){
	int lb = l/BSZ, rb = r/BSZ;
	int cnt = 0;
	for(int b=lb+1; b<rb; b++){
		cnt += lower_bound( s+b*BSZ, s+min( (b+1)*BSZ, N ), n ) - (s+b*BSZ);
	}
	if( lb==rb ){
		for(int i=l; i<=r; i++)
			if( a[i] < n ) cnt++;
	}else{
		for(int i=l; i<(lb+1)*BSZ; i++)
			if( a[i] < n ) cnt++;
		for(int i=rb*BSZ; i<=r; i++)
			if( a[i] < n ) cnt++;
	}
	return k<=cnt;
}

int main(){
	scanf("%d%d",&N,&M); bn = (N-1)/BSZ+1;
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]); s[i] = b[i] = a[i];
	}
	sort( b, b+N );
	for(int b=0; b<bn; b++){
		sort( s+b*BSZ, s+min( (b+1)*BSZ, N ) );
	}
	while(M--){
		scanf("%d%d%d",&l,&r,&k); l--; r--;
		// lo : false, hi : true
		int lo = 0, hi = N;
		while( lo + 1 < hi ){
			int m = (lo + hi ) / 2;
			if( decision( b[m] ) ){
				hi = m;
			}else{
				lo = m;
			}
		}
		printf("%d\n",b[lo]);
	}
	return 0;
}