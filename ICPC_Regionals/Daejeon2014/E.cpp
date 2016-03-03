#include <bits/stdc++.h>
using namespace std;
typedef array<int,3> Point;

int T,A,B,C,N, XL,YL, ans;
Point pts[11111];
map<int,int> xm, ym;

// range update +1/-1
// overall maximum query
struct seg{
	int t[22222], d[11111]; int n, h;
	void clear(){
		memset( t, 0, sizeof t );
	}
	void build(){
		h = sizeof(int) * 8 - __builtin_clz(n);
		for(int i=n-1; i>0; --i) t[i] = max( t[i<<1], t[i<<1|1] ), d[i] = 0;
	}
	void apply(int p, int v){
		t[p] += v;
		if( p<n ) d[p] += v;
	}
	void build(int p){
		while( p>1 ) p>>=1, t[p] = max( t[p<<1], t[p<<1|1] ) + d[p];
	}
	void push(int p){
		for(int s=h; s>0; --s){
			int i = p>>s;
			if( d[i] != 0){
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = 0;
			}
		}
	}
	void add(int l, int r, int v){
		l+=n, r+=n; int l0=l, r0=r;
		for(; l<r; l>>=1, r>>=1){
			if( l&1 ) apply(l++, v);
			if( r&1 ) apply(--r, v);
		}
		build(l0); build(r0-1);
	}
	int query(int l,int r){
		l+=n, r+=n; push(l); push(r-1);
		int res = -2e9;
		for(; l<r; l>>=1, r>>=1){
			if( l&1 ) res = max( res, t[l++]);
			if( r&1 ) res = max( t[--r], res);
		}
		return res;
	}
}seg;

int ctz[11111];
void solve_cases(int R, int G, int B){
	seg.clear(); int bcnt = 0, nc = 0, rcnt = 0; memset( ctz, 0, sizeof ctz );
	for(int i=0; i<N; i++){
		assert( 0<= pts[i][0] && pts[i][0] <= XL);
		assert( 0<= pts[i][1] && pts[i][1] <= YL);
		if( pts[i][2] == G ) ctz[ pts[i][0] ] ++;
		if( pts[i][2] == B ) ctz[ pts[i][0] ] --, bcnt++;
	}
	for(int i=0; i<XL; i++){
		assert( -1 <= ctz[i] && ctz[i] <= 1 );
		nc += ctz[i]; seg.t[XL+i] = nc;
	} seg.n = XL; seg.build();

	ans = max( ans, rcnt + bcnt + seg.query(0, XL) );
	for(int r=0; r<N; r++){
		if( pts[r][2] == R ) rcnt++;
		if( pts[r][2] == G ) seg.add( pts[r][0], XL, -1 );
		if( pts[r][2] == B ) seg.add( pts[r][0], XL, +1 ), bcnt--;
		assert( bcnt + seg.t[1] >= 0 );
		ans = max( ans, rcnt + bcnt + seg.query(0, XL) );
	}
	
	seg.clear(); bcnt = 0, nc = 0, rcnt = 0; memset( ctz, 0, sizeof ctz );
	for(int i=0; i<N; i++){
		if( pts[i][2] == G ) ctz[ pts[i][1] ] ++;
		if( pts[i][2] == B ) ctz[ pts[i][1] ] --, bcnt++;
	}
	for(int i=0; i<YL; i++){
		assert( -1 <= ctz[i] && ctz[i] <= 1 );
		nc += ctz[i]; seg.t[YL+i] = nc;
	} seg.n = YL; seg.build();
	
	ans = max( ans, rcnt + bcnt + seg.query(0, YL) );
	for(int r=0; r<N; r++){
		if( pts[r][2] == R ) rcnt++;
		if( pts[r][2] == G ) seg.add( pts[r][1], YL, -1 );
		if( pts[r][2] == B ) seg.add( pts[r][1], YL, +1 ), bcnt--;
		assert( bcnt + seg.t[1] >= 0 );
		ans = max( ans, rcnt + bcnt + seg.query(0, YL) );
	}
}

void solve_perm(){
	int cls[3] = {1,2,3};
	do{
		solve_cases( cls[0], cls[1], cls[2] );
	}while( next_permutation( cls, cls+3 ) );
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&A,&B,&C);
		N = A+B+C; XL = YL = ans = 0; xm.clear(), ym.clear();

		for(int i=0; i<A; i++){
			scanf("%d%d",&pts[i][0],&pts[i][1]);
			pts[i][2] = 1; xm[pts[i][0]]; ym[pts[i][1]];
		}
		for(int i=A; i<A+B; i++){
			scanf("%d%d",&pts[i][0],&pts[i][1]);
			pts[i][2] = 2; xm[pts[i][0]]; ym[pts[i][1]];
		}
		for(int i=A+B; i<A+B+C; i++){
			scanf("%d%d",&pts[i][0],&pts[i][1]);
			pts[i][2] = 3; xm[pts[i][0]]; ym[pts[i][1]];
		}
		sort( pts, pts+N, [](Point& x, Point& y){ return x[0] < y[0]; } );

		for(auto& it : xm) it.second = XL++;
		for(auto& it : ym) it.second = YL++;
		for(int i=0; i<N; i++){
			pts[i][0] = xm[ pts[i][0] ];
			pts[i][1] = ym[ pts[i][1] ];
		}

		solve_perm();
		swap( XL, YL ); for(int i=0; i<N; i++) swap(pts[i][0], pts[i][1]);
		solve_perm();
		for(int i=0; i<N; i++) pts[i][0] = XL - pts[i][0] - 1; reverse( pts, pts+N );
		solve_perm();
		swap( XL, YL );	for(int i=0; i<N; i++) swap(pts[i][0], pts[i][1]);
		solve_perm();
		
		assert( ans <= N );
		printf("%d\n",ans);
	}
	return 0;
}
