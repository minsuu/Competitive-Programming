// Aug 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RREP(I, N) for (int I= (N)-1; I>=0; --I)
#define RREPP(I, A, B) for(int I = (B)-1; I>=A; --I)
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define debug(A) REP(i, A.size()) cerr << A[i] << ' '; cerr << '\n'
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
typedef long long lld;
typedef unsigned long long ulld;
typedef pair<lld, lld> plld;
typedef vector<lld> vlld;
typedef vector<vlld> vvlld;
 
typedef long double ld;
typedef vector<ld> vld;
typedef vector<vld> vvld;

const double PI=2.0*acos(0.0);
const double EPSILON=1e-9;
struct F{
	double p; int i; // hull idx
	F( int x = 0 , int y = 0, int _i = 0 ) : i(_i) {
		p = fmod(atan2(y,x)+2*PI, 2*PI);
	}
	bool operator<(const F& rhs) const{
		return p < rhs.p;
	}
};
struct P{
	int F,S,i; // point idx
	bool operator<(const P& rhs) const{
		return (F != rhs.F) ? (F < rhs.F) : (S < rhs.S);
	}
};

int N;
lld cmp(P p, P a, P b){
    // cross product of (A-P) and (B-P)
    return (lld)a.S*b.F*(p.F-a.F)*(p.S-b.S)-(lld)a.F*b.S*(p.S-a.S)*(p.F-b.F);
}

int x[2222], y[2222];
int main(){
	while(1){
		scanf("%d",&N);
		if( N == 0 ) break;

		for(int i=0; i<N; i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		
		vector<P> hulls[2222][4];
		vector<F> segs[2222][4][2];

		for(int i=0; i<N; i++){
			vector<P> pts[4];
			for(int j=0; j<N; j++){
				if( i==j ) continue;
				int ax = x[j] - x[i], ay = y[j] - y[i];
				if( ax >0 && ay>=0 ) pts[0].PB( { ax, ay, j });
				if( ax<=0 && ay >0 ) pts[1].PB( { ax, ay, j });
				if( ax <0 && ay<=0 ) pts[2].PB( { ax, ay, j });
				if( ax>=0 && ay <0 ) pts[3].PB( { ax, ay, j });
			}

			for(int j=0; j<4; j++){
				if( SZ(pts[j]) == 0 ) continue;
			    if( SZ(pts[j]) == 1 ){
			    	hulls[i][j].PB( pts[j][0] );
			    	continue;
			    }
			    sort( ALL(pts[j]) );

				vector<P> upp,dnn;
			    REP(i, SZ(pts[j])){
			        while(SZ(upp)>1 && cmp( upp[SZ(upp)-2], upp.back(), pts[j][i] )>=0 )
			            upp.pop_back();
			        upp.PB(pts[j][i]);
			    }
			    if( SZ(upp) ) upp.pop_back();

			    RREP(i, SZ(pts[j])){
			        while(SZ(dnn)>1 && cmp( dnn[SZ(dnn)-2], dnn.back(), pts[j][i] )>=0 )
			            dnn.pop_back();
			        dnn.PB(pts[j][i]);
			    }
			    if( SZ(dnn) ) dnn.pop_back();

			    for( auto it : upp ) hulls[i][j].PB( it );
			    for( auto it : dnn ) hulls[i][j].PB( it );
			}
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<4; j++){
				int sz = SZ( hulls[i][j] );
				if( sz <= 2 ) continue;
				// printf("hullsegs of (%d,%d) in %dth space :: ", x[i], y[i], j );
				for(int k=0; k<sz; k++){
					int l = ( k + 1 ) % sz;
					int x = hulls[i][j][l].F - hulls[i][j][k].F;
					int y = hulls[i][j][l].S - hulls[i][j][k].S;
					segs[i][j][0].PB( F( y, -x, k ) );
					segs[i][j][1].PB( F( -y, x, k ) );
					// printf("(%d, %d ,%.5f) ",x,y,segmn[i][j].back().p);
				}
				sort( ALL(segs[i][j][0] ) );
				sort( ALL(segs[i][j][1] ) );
				// printf("\n");
			}
		}

		int mx = 0, mn = 1987654321;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if( i==j ) continue;
				// find k candidates via convex hulls
				int ax = x[j] - x[i], ay = y[j] - y[i];
				F A = F( ay, -ax, 0 ), B = F( -ay, ax, 0 );

				for(int k=0; k<4; k++){
					if( SZ(hulls[i][k]) <= 2 ){
						for(auto it : hulls[i][k]){
							if( it.i == j ) continue;
							int area = ay*it.F - ax*it.S;
							if( area<0 ) area = -area;
							mn = min( mn, area); mx = max( mx, area);
						}
						continue;
					}
					#define UPD(X) do {\
						for(int l=0; l<2; l++){\
							auto lw = lower_bound( ALL(segs[i][k][l]), X);\
							int lwp, sz = SZ(hulls[i][k]), area;\
							if( lw == segs[i][k][l].end() ) lwp = segs[i][k][l][0].i;\
							else lwp = (*lw).i;\
							if( hulls[i][k][lwp].i == j ){\
								lwp--; lwp = ( lwp + sz ) % sz;\
								area = ay*hulls[i][k][lwp].F - ax*hulls[i][k][lwp].S;\
								if( area<0 ) area = -area;\
								mn = min( mn, area ); mx = max( mx, area);\
								lwp+=2; lwp = ( lwp + sz ) % sz;\
								area = ay*hulls[i][k][lwp].F - ax*hulls[i][k][lwp].S;\
								if( area<0 ) area = -area;\
								mn = min( mn, area ); mx = max( mx, area);\
							}else{\
								area = ay*hulls[i][k][lwp].F - ax*hulls[i][k][lwp].S;\
								if( area<0 ) area = -area;\
								mn = min( mn, area ); mx = max( mx, area);\
							}\
						}\
					}while(0)
					UPD(A);
					UPD(B);
					#undef UPD
					// printf("after (%d, %d)-(%d, %d) of %dth space :: %d %d\n", x[i],y[i], x[j], y[j], k+1, mx,mn);
				}
			}	
		}
		printf("%.1f %.1f\n",mn/2.0, mx/2.0);
	}
	return 0;
}