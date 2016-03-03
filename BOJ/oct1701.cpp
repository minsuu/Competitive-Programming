#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int INF = 1987654321;
const int LIM = 1111111;

int T,N,Q, p,a,b;
char buf[4];

struct stree{
    int mini[LIM*2], maxi[LIM*2], d[LIM], n, h;
    void build(){
        memset( d, 0, sizeof d );
        h = sizeof(int) * 8 - __builtin_clz(n);
        for(int i = n-1; i>0; --i){
            mini[i] = min( mini[i<<1], mini[i<<1|1] );
            maxi[i] = max( maxi[i<<1], maxi[i<<1|1] );
        }
    }
    void apply(int p, int v){
        mini[p] += v; maxi[p] += v;
        if( p < n ) d[p] += v;
    }
    void build(int p){
        while( p > 1 ){
            p>>=1;
            maxi[p] = max( maxi[p<<1], maxi[p<<1|1] ) + d[p];
            mini[p] = min( mini[p<<1], mini[p<<1|1] ) + d[p];
        }
    }
    void push(int p){
        for(int s=h; s>0; --s){
            int i = p>>s;
            if( d[i] != 0 ){
                apply( i<<1, d[i]);
                apply( i<<1|1, d[i] );
                d[i] = 0;
            }
        }
    }
    void inc(int l, int r, int value){
        l += n; r += n;
        int l0 = l, r0 = r;
        for(; l<r; l>>=1, r>>=1){
            if( l&1 ) apply( l++, value );
            if( r&1 ) apply( --r, value );
        }
        build( l0 ); build( r0 - 1);
    }
    int query( int l, int r ){
        l += n; r += n; int mx = -INF, mn = INF;
        push( l ); push( r-1 );
        for( ; l<r; l>>=1, r>>=1 ){
            if( l&1 ) mx = max( mx, maxi[l] ), mn = min( mn, mini[l]), l++;
            if( r&1 ) r--, mx = max( mx, maxi[r] ), mn = min( mn, mini[r] );
        }
        return mx - mn;
    }
}stree;

vector<vi> linkd;
vi pre; int sz[LIM], pos[LIM], init[LIM];
void dfs(int n){
    pre.push_back(n); sz[n] = 1;
    for(auto it : linkd[n] ){
        dfs(it);
        sz[n] += sz[it];
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        vector<vi>(N).swap( linkd );
        vi().swap(pre);

        for(int i=1; i<N; i++){
            scanf("%d",&p); p--;
            linkd[p].push_back( i );
        }
        dfs( 0 );

        for(int i=0; i<N; i++){
            pos[ pre[i] ] = i;
        }
        stree.n = N;
        for(int i=0; i<N; i++){
            scanf("%d",&a);
            stree.mini[ N + pos[i] ] = a;
            stree.maxi[ N + pos[i] ] = a;
        }
        stree.mini[ 2*N ] = INF;
        stree.maxi[ 2*N ] = -INF;
        stree.build();

        scanf("%d",&Q);
        while(Q--){
            scanf("%s",buf);
            if( *buf == 'Q' ){
                scanf("%d",&a); a--; //[,)
                printf("%d\n", stree.query( pos[a], pos[a] + sz[a]));
            }else if( *buf == 'R'){
                scanf("%d%d",&a,&b); a--;
                stree.inc( pos[a], pos[a] + sz[a], b);
            }
        }
    }
    return 0;
}