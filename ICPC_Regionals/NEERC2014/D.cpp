#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<double,double> PT;
const double EPS = 1e-15;
const double PI = acos(-1);

double d,l,r,t,h, th ;
inline double cir( double r, double h ){ // h : [-r, r]
	if( r < EPS ) return 0.0;
	if( h > 0 ){
		double th = acos( h / r );
		return r*r*PI - r*r*th + h*sin(th)*r;
	}else{
		h *= -1;
		double th = acos( h / r );
		return r*r*th - h*sin(th)*r ;
	}
}

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

#define integral(F,A,B) adaptiveSimpson( F, A, B, simpson(F,A,B), EPS )

int main(){
	scanf("%lf%lf%lf%lf%lf",&d,&l,&r,&t,&h); d/=2;
	auto ci = [&](double x)->double{ return 2*sqrt( 4*4 - x*x); };
	printf("%.20f %.20f\n ", integral( ci, -4, 4 ), 4*4*PI );
	return 0;

	th = asin( t / l );
	PT A{ 0, l - pow( r*r - d*d, 0.5 ) };
	PT B{ 0, pow( r*r - d*d, 0.5 ) };

	if( th < EPS ){
		auto pA = [&](double x)->double{ return cir( d, h-d ); };
		auto pB = [&](double x)->double{ return cir( sqrt(r*r-x*x), -B.Y ); };
		double ans = integral( pA, 0, l ) + 2*integral( pB, d-h, d );
		printf("%.10f\n", ans / 1e6 );
		return 0;
	}
	double a = tan( PI/2 - th ), b = h/sin(th);
	if( b > l+2*d*a ){

	}else if( b > l ){
		double k = -d*a+(b-d*a), i = tan(th);
		auto pA = [&](double x)->double{ return cir( d, d - i*x ); };
		auto pB = [&](double x)->double{ return cir( sqrt(r*r-x*x), -B.Y ); };
		double ans = d*d*PI*k + integral( pA, 0, l-k ) + integral( pB, -d, d);
		double pa = (l-(b-d*a) )/a, pb = 
		auto pC = [&](double x)->double{ return 0; };
	}else if( b > 2*d*a ){

	}else{

	}

	// printf("%f %f,%f %f,%f %f", th, A.X, A.Y, B.X, B.Y , r*r-d*d);
	// printf(" %f", cir(5,5/sqrt(2.0)) );
	return 0;
}