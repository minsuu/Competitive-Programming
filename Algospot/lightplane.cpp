#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef vector<int> vi;
const int MAXN = 2e5+10;
const lld INF = 987654321987654321LL;

int T, N, X[MAXN], Y[MAXN], C[MAXN]; lld dp;
struct Result { lld m1, m2, m3, m4; };
Result merge(Result a, Result b){
    return { max(a.m1, b.m1), max(a.m2, b.m2), max(a.m3, b.m3), max(a.m4, b.m4) };
}
struct snode {
    int i, j; snode *l, *r; Result res;
    ~snode() { delete l; delete r; }
    snode(int i, int j ): i(i), j(j) {
        if (j - i == 1) {
            l = r = NULL;
            res = { C[i] + X[i], C[i] - X[i], C[i] + Y[i], C[i] - Y[i] };
        } else {
            int k = ( i + j ) >> 1;
            l = new snode(i, k);
            r = new snode(k, j);
            res = merge( l->res , r->res );
        }
    }
	void add(int P, lld val){
		if( j <= P || P < i ) return;
		else if( j - i == 1 ) res.m1+=val, res.m2+=val, res.m3+=val, res.m4+=val;
		else{
			l->add(P, val); r->add(P, val);
			res = merge( l->res, r->res );
		}
	}
    Result query(int I, int J){
        if( I <= i && j <= J){
            return res;
        }else if( j <= I || J <= i ){
            return { -INF, -INF, -INF, -INF };
        }else{
            return merge( l->query(I,J), r->query(I,J) );
        }
    }
};
 
struct segment {
    snode *root;
    segment() : root(0) {}
    void init(int n) {
        if(root) delete root;
        root = new snode(0, n);
    }
    void add(int P, lld val){
    	root->add( P, val );
    }
    Result query(int i, int j){
    	if( j < i ) return {-INF, -INF, -INF, -INF};
        return root->query(i, j+1);
    }
};

segment tree;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N); N++;
		for(int i=1; i<N; i++){
			scanf("%d%d%d",&X[i],&Y[i],&C[i]); C[i]*=-1;
		}
        tree.init(N);

		for(int i=N-1; i>=0; i--){
			int nxt = (i==0 ? i+1 : i+3 ); dp = 0;
            Result r = tree.query(nxt, N-1);
            dp = max(dp, r.m1 - X[i] );
            dp = max(dp, r.m2 + X[i] );
            dp = max(dp, r.m3 - Y[i] );
            dp = max(dp, r.m4 + Y[i] );
            tree.add(i, dp);
		}
		printf("%lld\n",dp);
	}
	return 0;
}