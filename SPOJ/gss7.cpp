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

const int inf = 987654321;
struct Result { int lmax, rmax, maxi, sum; };
Result merge(const Result& a, const Result& b){
	Result ret;
	ret.lmax = max( a.lmax, a.sum + b.lmax );
	ret.rmax = max( b.rmax, b.sum + a.rmax );
	ret.maxi = max( a.rmax + b.lmax , max( a.maxi, b.maxi ) );
	ret.sum = a.sum + b.sum;
	return ret;
}
struct snode {
    int i, j, p, v; Result res;
    snode *l, *r;
    snode(int i, int j): i(i), j(j), p(0), v(0) {
        if (j - i == 1) {
            l = r = NULL;
        } else {
            int k = i + j >> 1;
            l = new snode(i, k, arr);
            r = new snode(k, j, arr);
        }
    }
    ~snode() { delete l, r; }
    void visit(){
    	if(p){
    		int newsum = v * ( j - i ), newmaxi = max( 0, newsum );
    		res = { newmaxi, newmaxi, newmaxi, newsum };
    		if(l) l->p=r->p=1, l->v=r->v=v;
    		p=v=0;
    	}
    }
    void update(int I, int J, int V){
    	if( I <= i && j <= J ){
    		p=1; v=V; visit();
    	}else if( j <= I || J <= i ){
    		return;
    	}else{
    		l->update(I,J,v); r->update(I,J,v);
    		res=merge(l->res, r->res);
    	}
    }
    Result query(int I, int J) {
        if (I <= i && j <= J) {
            return res;
        } else if (j <= I || J <= i) {
            return { -inf, -inf, -inf, 0 };
        } else {
            return merge( l->query(I,J), r->query(I,J) );
        }
    }
};
struct segment {
    snode *root;
    segment() : root(0) {}
    void init(int n, const vi& arr) {
        if(root) delete root;
        root = new snode(0, n, arr);
    }
    int update(int i, int j, int v){
    	root->update(i, j+1, v);
    }
    int query(int i, int j) {
    	Result ret = root->query(i, j+1);
        return ret.maxi;
    }
};
struct node{
    vi linked;
    int par, heavyidx, heavypos;
};
struct heavypath{
	int size, parent;
	segment tree;
	heavypath() : size(0), parent(0) {}
	void init(int n){
		tree.init(n);
	}
};
vector<heavypath> heavypaths;
vector<node> nodes;
int N,Q, a,b; vi arr;
int main(){
	scanf("%d",&N); vi(N).swap(arr);
	REP(i, N) scanf("%d",&arr[i]);
    
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&a,&b); a--; b--;
		printf("%d\n", tree.query(a,b) );
	}
    return 0;
}