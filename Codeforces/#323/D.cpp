// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int n,T, a[111], v[111], nv[111], ans;
int main(){
	scanf("%d%d",&n,&T);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);

	for(int i=0; i<n; i++){
		int mx = 0;
		for(int j=0; j<i; j++){
			if( a[j] <= a[i] ) mx = max(mx, v[j] );
		}
		v[i] = mx + 1;
		ans = max( ans, v[i] );
	}
	if( T == 1 ){
		printf("%d",ans); return 0;
	}
	T--;

	for(int i=0; i<100; i++){
		for(int j=0; j<n; j++){
			int mx = 0;
			for(int k=0; k<n; k++){
				if( a[k] <= a[j] ) mx = max( mx, v[k] );
			}
			for(int k=0; k<j; k++){
				if( a[k] <= a[j] ) mx = max( mx, nv[k] );
			}
			nv[j] = mx + 1;
		}
		T--; if( T == 0 ) break;
		if( i!=99 ) memcpy( v, nv, sizeof(v) );
	}

	ans = 0;
	for(int i=0; i<n; i++){
		v[i] += ( nv[i] - v[i] ) * (T+1);
		ans = max( ans, v[i] );
	}
	printf("%d",ans);
	return 0;
}