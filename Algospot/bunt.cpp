// Oct 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define SQ(X) ((X)*(X))
using namespace std;
 
const double EPS = 1e-8;

template<typename Function>
double simpson(Function f, double a, double b) {
	double c = (a + b) / 2.0;
	double h3 = fabs(b - a) / 6.0;
	return h3 * (f(a) + 4.0 * f(c) + f(b));
}

template<typename Function>
double adaptiveSimpson(Function f, double a, double b, double sum, double eps) {
	double c = (a + b) / 2.0;
	double left = simpson(f, a, c);
	double right = simpson(f, c, b);
	if(fabs(left + right - sum) <= 15 * eps) 
		return left + right - (left + right - sum) / 15;
	return adaptiveSimpson(f, a, c, left, eps/2) + adaptiveSimpson(f, c, b, right, eps/2);
}

int T;
double d,r,rb,vt,t,vh, l;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf",&d,&r,&vt,&t,&vh);
		rb = ( d/vh - t ) * vt;
		if( vh < EPS ) { printf("%.10f\n",0.0); continue; }
		if( rb < EPS ) rb = 0.0;

		auto ar = [&](double rx)->double{
			double ry = sqrt( r*r - rx*rx );
			if( rb < rx+EPS ) return ry;
			double m = sqrt(rb*rb - rx*rx), ya = max( 0.0, d-m ), yb = d+m;
			if( ry < ya ) return ry;
			if( ry < yb ) return ya;
			return ry - ( yb - ya );
		};
		printf("%.20f\n", adaptiveSimpson(ar, 0, r, simpson(ar,0,r), 1e-8/4) );
	}	
	return 0;
}