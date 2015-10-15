// Oct 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);

struct Circle{
	double x,y,r;
	double getCenterDistance(const Circle &rhs) const{
		return hypot( x-rhs.x, y-rhs.y );
	}
	bool intersects(const Circle &rhs) const{
		double d= getCenterDistance(rhs);
		if( d>=r + rhs.r - EPS ) return false;
		return true;
	}
	bool enclosedIn(const Circle &rhs) const{
		double d = getCenterDistance(rhs);
		return d+r <= rhs.r + EPS;
	}
	double lineIntegral(double th1, double th2) const{
		double ds = sin(th2) - sin(th1);
		double dc = cos(th2) - cos(th1);
		return 0.5 * ( r * (x * ds - y * dc) + r * r * (th2 - th1 ) );
	}

	pair<double, double> getIntersectionAngle( const Circle &rhs ) const{
		double d = getCenterDistance(rhs);
		double base = atan2( rhs.y - y, rhs.x - x);
		double alpha = acos((d*d +r*r - rhs.r*rhs.r) / (2*r*d));
		double l = base - alpha, r = base + alpha;
		if( l < -PI ) l += 2*PI;
		if( r >= PI ) r -= 2*PI;
		return make_pair(l,r);
	}
};

struct CircleUnion{
	int n;
	vector<Circle> a;
	void addCircle( const Circle &C ) {
		for(int i=0; i<(int)a.size(); i++){
			if( C.enclosedIn(a[i]) ) return;
			if( a[i].enclosedIn(C) ){
				swap(a[i], a.back() );
				a.pop_back(); --i;
			}
		}
		a.push_back( C );
		n = (int) a.size();
	}

	double getUnionArea() {
		double S = 0;
		for(int i=0; i<n; i++){
			vector<pair<double, int> > events;
			for(int j=0; j<n; j++) if( i!=j ){
				if( !a[i].intersects(a[j]) ) continue;
				pair<double,double> range = a[i].getIntersectionAngle(a[j]);
				events.emplace_back( range.first, +1);
				events.emplace_back( range.second, -1);
				if( range.first > range.second ){
					events.emplace_back( PI, -1 );
					events.emplace_back( -PI, +1 );
				}
			}
			events.emplace_back( -PI, 0 );
			sort(events.begin(), events.end() );
			events.emplace_back( +PI, 0 );
			int cnt = 0; unsigned p = 0;
			for(int j=0; j+1 < (int)events.size(); ++j){
				double s = events[j].first, t=events[j+1].first;
				while( p < events.size() && events[p].first <=s )
					cnt+=events[p++].second;
				if(cnt==0) S += a[i].lineIntegral(s,t);
			}
		}
		return S;
	}
};
int T,N;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		CircleUnion uni;
		for(int i=0; i<N; i++){
			Circle a;
			scanf("%lf%lf%lf",&a.x,&a.y,&a.r);
			uni.addCircle(a);
		}
		printf("%.10f\n",uni.getUnionArea());
	}
	return 0;
} 