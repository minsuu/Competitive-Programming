#include <bits/stdc++.h>
using namespace std;
const double INF = 1e14;
int a,b;
double ans;
double go( double c ){
	if( c/2.0 < b ) return INF;

	int l = 1, h = a;
	while( l + 1 < h ){
		int m = (l + h)/2;
		if( c/(m*2) < b ){
			h = m;
		}else{
			l = m;
		}
	}
	return c/(l*2);
}
int main(){
	scanf("%d%d",&a,&b);
	ans = min( go( a+b ), go(a-b) );
	if( ans == INF ){
		printf("-1");
	}else{
		printf("%.10lf",ans);
	}
	return 0;
}