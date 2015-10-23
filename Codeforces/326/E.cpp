#include <bits/stdc++.h>
using namespace std;
const int LIM = 222222;
int n,q;

struct st1{
	int d[LIM], n, h, a[LIM];
	void build(){
		h = sizeof(int)*8 - __builtin_clz(n);
		memset( d, 0, sizeof d );
	}
	void apply(int p, int v){
		if( p<n ) d[p] ^= v;
		else a[p-n] ^= v;
	}
	void push(int p){
		for(int s=h; s>0; --s){
			int i = p>>s;
			if( d[i] != 0 ){
				apply( i<<1, d[i] );
				apply( i<<1|1, d[i] );
				d[i] = 0;
			}
		}
	}
	void update(int l, int r, int v){
		l+=n, r+=n;
		push( l ); push( r - 1);
		for(; l<r; l>>=1, r>>=1){
			if( l&1 ) apply(l++, v);
			if( r&1 ) apply(--r, v);
		}
	}
	int query( int p ){
		push( p+n );
		return a[p];
	}
}st1;
#define lbit(X) ( (X) & -(X) )
struct res{
	int b[32] = {}, s = 0;
	inline void pb(int x){
		for(int i=0; i<s; i++)
			if( x & lbit(b[i]) )
				x ^= b[i];
		if( !x ) return;
		for(int i=0; i<s; i++)
			if( lbit(x) & b[i] )
				b[i] ^= x;
		b[ s++ ] = x;
	}
};

struct st2{
	res c[LIM*2]; int n;
	inline void merge( res u, res v, res& r ){
		r.s = 0;
		for(int i=0; i<u.s; i++)
			r.pb( u.b[i] );
		for(int i=0; i<v.s; i++)
			r.pb( v.b[i] );
	}
	void build(){
		for(int i= n-1; i>0; --i){
			merge( c[i<<1], c[i<<1|1], c[i] );
		}
	}
	void build(int p){
		while( p>1 ) p>>=1, merge( c[p<<1], c[p<<1|1], c[p] );
	}
	void update(int p, int v){
		c[p+n].b[0] ^= v;
		c[p+n].s = 1;
		build(p+n);
	}
	res query(int l, int r){
		res ans;
		for( l+=n, r+=n; l<r; l>>=1, r>>=1) {
			if( l&1 ) merge( ans, c[l++], ans );
			if( r&1 ) merge( c[--r], ans, ans );
		}
		return ans;
	}
}st2;

int a[LIM], b,c,d,e, tp[33];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		if( i ){
			st2.c[n-1+i-1].pb( a[i-1] ^ a[i] );
		}
		st1.a[i] = a[i];
	}
	st1.n = n; st1.build();
	st2.n = n-1; st2.build();
	tp[0] = 1;
	for(int i=1; i<33; i++) tp[i] = tp[i-1] * 2;
	while(q--){
		scanf("%d%d%d",&b,&c,&d); c--; d--;
		if( b==1 ){
			scanf("%d",&e);
			st1.update( c,d+1,e );
			if(c>0) st2.update( c-1, e );
			if(d<n-1) st2.update( d, e );
		}
		if( b==2 ){
			res r = st2.query( c,d );
			r.pb( st1.query(c) );
			printf("%d\n",tp[r.s]);
		}
	}
	return 0;
}
