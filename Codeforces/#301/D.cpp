// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
struct R {
	double r,s,p;
	R operator+(R rhs) {
		return { r+rhs.r, s+rhs.s, p+rhs.p }; 
	}
	R operator*(double x) {
		return { r*x, s*x, p*x };
	}
};
R cache[111][111][111];
R dp(int r, int s, int p){
	if( r<0 || s<0 || p<0 ) return {0, 0, 0};
	if( s==0 && p==0 ) return {1,0,0};
	if( r==0 && p==0 ) return {0,1,0};
	if( r==0 && s==0 ) return {0,0,1};
	R& ret = cache[r][s][p];
	if( !(ret.r == 0 && ret.s == 0 && ret.p == 0) ) return ret;
	double all = (r+s+p) * (r+s+p - 1 ) / 2.0;
	ret = dp(r-1,s,p) * ( r*p / all ) + dp(r,s-1,p) * ( r*s / all ) + dp(r,s,p-1) * ( s*p / all );
	ret = ret * ( all / ( all - r*(r-1)/2 - s*(s-1)/2 - p*(p-1)/2 ) );
	return ret;
}
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	R ret = dp(a,b,c);
	printf("%.15f %.15f %.15f",ret.r,ret.s,ret.p);	
	return 0;
} 