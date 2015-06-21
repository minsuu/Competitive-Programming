// Jun 20 2015, minsu( github : https://github.com/minsuu/ )
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const double INF = 1e20;
const double EPS = 1e-9;
struct Point { double x, y; bool operator<(Point& rhs) { return x==rhs.x? y<rhs.y : x<rhs.x; } };
typedef vector<Point> Polygon;
double nsq(const Point& X) { return X.x*X.x + X.y*X.y; } // norm square
double distsq(const Point& X, const Point& Y) { return nsq({ X.x - Y.x, X.y - Y.y }); }
Point csc(Point& A, Point& B, Point& C) {
	Point S; double a;
	S.x = 0.5*( nsq(A) * ( B.y - C.y ) - A.y * ( nsq(B) - nsq(C) ) + ( nsq(B) * C.y - nsq(C) * B.y ) );
	S.y = 0.5*( A.x * ( nsq(B) - nsq(C) ) - nsq(A) * ( B.x - C.x ) + ( nsq(C) * B.x - nsq(B) * C.x ) );
	a = A.x * ( B.y - C.y ) - A.y * ( B.x - C.x ) + ( B.x * C.y - C.x * B.y );
	if( fabs(a) < EPS ) return {INF, INF};
	S.x/=a; S.y/=a; return S;
}
double ccw(Point a, Point b, Point c){
	return ( b.x - a.x ) * ( c.y - a.y ) - ( c.x - a.x ) * ( b.y - a.y );
}
Polygon hull(Polygon& p){
	Polygon L, U;
	if( p.size()<=2 ) return p;
	sort(p.begin(), p.end());
	for(auto it : p){
		int sz = L.size();
		while( sz>=2 && ccw(L[sz-2], L[sz-1], it) < EPS )
			L.pop_back(), sz--;
		L.push_back(it);
	}
	for(auto it=p.rbegin(); it!=p.rend(); ++it){
		int sz = U.size();
		while( sz>=2 && ccw(U[sz-2], U[sz-1], *it) < EPS )
			U.pop_back(), sz--;
		U.push_back(*it);
	} L.pop_back(); U.pop_back();
	L.insert( L.end(), U.begin(), U.end() );
	return L;
}
bool check(Point a, Point b, double mind, Polygon& p){
	int pn = p.size(); double maxd = INF;
	for(int k=0; k<pn; k++){
		double cw = ccw( a, b, p[k] );
		if( fabs(cw) < EPS ){ // in a line!
			double ax = min( a.x, b.x ), bx = max( a.x, b.x );
			if( ax <= p[k].x && p[k].x <= bx ){
				mind = INF; break;
			}
		}else{
			Point kc = csc(a, b, p[k]);
			double dist = distsq(kc, a);
			if( ccw( a, b, kc ) < EPS ) dist*=-1.0;

			if( cw > -EPS ){ // ccw
				maxd = min( maxd, dist );
			}else{ // cw
				mind = max( mind, dist );
			}
		}
	}
	if( mind < maxd ) return true;
	return false;
}
bool solve(Polygon& h, Polygon& p ){
	int hn = h.size(), pn = p.size();
	if( hn == 1 ) return true;
	for(int i=0; i<hn; i++){
		int j = (i+1) % hn, t = -1;
		double mind = -INF;
		for(int k=0; k<hn; k++)
			if( i!=k && j!=k ){
				Point kc = csc(h[i], h[j], h[k]);
				double dist = distsq(kc, h[i]);
				if( mind < dist ){
					mind = dist; t = k;
				}
			}
		if( check( h[i], h[j], mind, p ) ||
			( t!=-1 && ( check( h[j], h[t], mind, p) || check( h[t], h[i], mind, p) )) )
			return true;
	}
	return false;
}
int N,M, x,y; Polygon np, mp, nh, mh;
int main() {
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d",&x,&y);
		np.push_back({x,y});
	}
	for(int i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		mp.push_back({x,y});
	}
	nh=hull(np); mh=hull(mp);
	// for(auto it : nh) printf("%g,%g ",it.x,it.y); printf("\n");
	// for(auto it : mh) printf("%g,%g ",it.x,it.y); printf("\n");
	if( solve(nh, mp) || solve(mh, np) )
		printf("YES");
	else
		printf("NO");
	return 0;
}