#include <bits/stdc++.h>
using namespace std;
int N, an[222222], mx, mn = 987654321;
double psum[222222], ans;

double val( double x ){
	double pl = 0, mi = 0, mpl = 0.0, mmi = 0.0;
	for(int i=0; i<N; i++){
		double nw = an[i] - x;
		if( pl + nw > 0 ) pl += nw;
		else pl = 0;

		if( mi + nw < 0 ) mi += nw;
		else mi = 0;

		mpl = max( mpl, pl );
		mmi = min( mmi, mi );
	}
	return max( mpl, -mmi );
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&an[i]);
		mx = max( mx, an[i] );
		mn = min( mn, an[i] );
	}

	double lo = mx, hi = mn;
	for(int i=0; i<100; i++){
		double m1 = ( 2*lo + hi ) / 3;
		double m2 = ( lo + hi*2 ) / 3;
		if( val(m1) < val(m2) ) hi = m2;
		else lo = m1;
	}
	printf("%.10lf",val(lo));
	return 0;
}