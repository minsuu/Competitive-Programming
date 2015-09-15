// Aug 28 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
const double INF = 1e100;
struct v2{
	double x, y;
	explicit v2(double _x=0.0, double _y=0.0) : x(_x), y(_y) {}
	v2 operator+(const v2& rhs){
		return v2(x+rhs.x, y+rhs.y);
	}
	v2 operator-(const v2& rhs){
		return v2(x-rhs.x, y-rhs.y);
	}
	v2 operator*(const double rhs){
		return v2(x*rhs, y*rhs);
	}
	double polar(){
		double ang = atan2(y,x);
		if( ang < -PI/2) ang += 2*PI;
		return ang;
	}
};

struct FenwickTree{
	int n;
	vector<long long> d;
	FenwickTree(int n) : n(n), d(n+1, 0) { }
	long long sum(int pos){
		long long res = d[0];
		for( ++pos; pos>0; pos&=(pos-1) ) res+=d[pos];
		return res;
	}
	void add(int pos, long long x) {
		for( ++pos; pos<=n; pos+=(pos&(-pos))) d[pos]+=x;
	}
};
struct FenwickRURQ{
	FenwickTree B1, B2;
	FenwickRURQ(int n) : B1(n), B2(n) {}
	long long query(int b) { return B1.sum(b) * b - B2.sum(b); }
	long long rquery(int a,int b) { return query(b) - query(a-1); }
	void radd(int i, int j, long long v) {
		B1.add(i, v); B1.add(j+1, -v);
		B2.add(i, v*(i-1)); B2.add(j+1, -v*j);
	}
};


typedef pair<double, int> di;
int N,M,T;
v2 ft[2222], dr[2222], tw[2222];
int main(){

#ifdef ONLINE_JUDGE
	freopen("ambitious.in", "rt", stdin);
	freopen("ambitious.out", "w", stdout);
#endif
	
	while(1) {
		scanf("%d", &N);
		if( N==0 ) break;

		for(int i=0; i<N; i++){
			scanf("%lf%lf",&dr[i].x, &dr[i].y);
		}
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%lf%lf",&ft[i].x, &ft[i].y);
		}
		scanf("%d", &T);
		for(int i=0; i<T; i++){
			scanf("%lf%lf",&tw[i].x, &tw[i].y);
		}

		long long ans = 0;
		for(int i=0; i<M; i++){
			vector<di> qry;
			for(int j=0; j<N; j++){
				double ang = (dr[j]-ft[i]).polar();
				qry.push_back( { ang, 3} );
			}
			for(int j=0; j<T; j++){
				double ang = (tw[j]-ft[i]).polar();
				qry.push_back( { ang, 1} );
				if( ang < PI/2 ) qry.push_back( { ang+PI , 2} );
			}
			sort( qry.begin(), qry.end() );
			FenwickRURQ ftree( T+1 );
			int l = 0, r = -1;
			for( auto it : qry ){
				if( it.second == 1 ){
					if( l<=r ) ans += ftree.rquery( l, r );
					r++;
				}
				if( it.second == 2 ){
					l++;
				}
				if( it.second == 3 ){
					ftree.radd( l, r, 1LL );
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 