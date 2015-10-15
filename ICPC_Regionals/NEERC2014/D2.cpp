#include <bits/stdc++.h>
#define SQ(X) ((X)*(X))
using namespace std;

const double PI = acos(-1);

double d,l,r,t,h, vx,vy,ha,hb,mr;

double circleFrac(double frac) {
    if (frac >= 1.0) return PI;
    if (frac <= 0.0) return 0.0;
    if (frac > 0.5) return PI - circleFrac(1.0 - frac);
    double outside = 2 * (0.5 - frac);
    double alpha = acos(outside);
    return alpha - sin(2 * alpha) / 2.0;
}

double f(int arg, double x){
	if( arg == 0 ){
		double rx = x * l, ymin = 0, ymax = 2*d, hy = ha * rx + hb ;
	    if( ymin > hy ) return 0.0;
	    if( ymax < hy ) return d*d*PI;
	    return circleFrac( hy / ymax )*d*d;
	}
	if( arg == 1 ){
		double rx = x * (r-mr) - (r-mr), ymin = d - sqrt( r*r - SQ(rx-mr) ), ymax = d + sqrt( r*r - SQ(rx-mr) );
		double hy = ha * rx + hb;
		if( ymin > hy ) return 0.0;
		if( ymax < hy ) return SQ( ( ymax-ymin) / 2) *PI;
        return circleFrac( (hy-ymin) / (ymax-ymin) )* SQ( (ymax-ymin)/2 );
	}
	if( arg == 2 ){
		double rx = x * (r-mr) + l, ymin = d - sqrt( r*r - SQ(rx-l+mr) ), ymax = d + sqrt( r*r - SQ(rx-l+mr) );
		double hy = ha * rx + hb;
		if( ymin > hy ) return 0.0;
		if( ymax < hy ) return SQ( ( ymax-ymin )/2 ) *PI;
        return circleFrac( (hy-ymin) / (ymax-ymin) ) * SQ( (ymax-ymin)/2 );		
	}
	return 0.0;
}

double simpson(int arg, double a, double b) {
  double c = (a + b) / 2.0;
  double h3 = fabs(b - a) / 6.0;
  return h3 * (f(arg,a) + 4.0 * f(arg,c) + f(arg,b));
}

double adaptiveSimpson(int arg, double a, double b, double sum, double eps) {
  double c = (a + b) / 2.0;
  double left = simpson(arg, a, c);
  double right = simpson(arg, c, b);
  if(fabs(left + right - sum) <= 15 * eps) 
    return left + right - (left + right - sum) / 15;
  return adaptiveSimpson(arg, a, c, left, eps/2) + adaptiveSimpson(arg, c, b, right, eps/2);
}3

double integral(int arg){
	return adaptiveSimpson( arg, 0.0, 1.0, simpson( arg, 0.0, 1.0), 1 );
}

int main(){
	scanf("%lf%lf%lf%lf%lf",&d,&l,&r,&t,&h); d/=2;
    vx = sqrt(l * l - t * t) / l;
    vy = t / l;
    ha = - t / sqrt(l*l-t*t), hb = h / vx;
	mr = sqrt( r*r - d*d );

	double ans = integral(0)*l + integral(1)*(r-mr) + integral(2)*(r-mr);
	ans /= 1e6;
	printf("%.2f", ans );

	return 0;
}