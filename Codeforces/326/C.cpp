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
struct Result {
	array<int,10> lst; int n;
};
Result merge(const Result& a, const Result& b){
    Result ret; ret.n = 0;
    int l = 0, r = 0;
	while( l < a.n && r < b.n && ret.n < 10){
		if( a.lst[l] < b.lst[r] )
			ret.lst[ ret.n++ ] = a.lst[l++];
		else
			ret.lst[ ret.n++ ] = b.lst[r++];
	}
	while( l < a.n && ret.n < 10 ){
		ret.lst[ ret.n ++ ] = a.lst[l++];
	}
	while( r < b.n && ret.n < 10 ){
		ret.lst[ ret.n ++ ] = b.lst[r++];
	}
	return ret;
}
struct snode {
    int i, j, p, v; Result res;
    snode *l, *r;
    snode(int i, int j): i(i), j(j), p(0), v(0) {
		res.n = 0;
        if (j - i == 1) {
            l = r = NULL;
        } else {
            int k = ( i + j ) >> 1;
            l = new snode(i, k);
            r = new snode(k, j);
        }
    }
    ~snode() { delete l; delete r; }
    void update(int p, int V){
		if( j <= p || p < i ) return;

		if( j - i == 1 ){
			if( res.n < 10 ){
				res.lst[ res.n ++ ] = V;
			}
		}else{
			l->update(p, V); r->update(p, V);
			res = merge( l->res, r->res);
		}
    }
    Result query(int I, int J) {
        if (I <= i && j <= J) {
            return res;
        } else if (j <= I || J <= i) {
            return { array<int,10>(), 0 };
        } else {
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
	void update( int p, int V) {
		root->update( p, V);
	}
    Result query(int i, int j) {
        // cerr<<"Query "<<i<<" to "<<j<<"("<<root<<")\n";
        if(i>j) swap(i,j);
        return root->query(i, j+1);
    }
};
struct node{
    int size, par, heavysize, heavychild, heavyidx, heavypos;
    node() : size(0), par(-1), heavysize(0), heavychild(-1), heavyidx(-1) {}
};
struct heavypath{
    int size, par;
    segment tree;
    heavypath() : size(0), par(0) {}
    heavypath(int _size, int _par ) : size(_size), par(_par) {}
    void init(){
        tree.init(size);
    }
};
vector<heavypath> paths;
vector<node> nodes;
vvi linked;
int N,M,Q, a,b,c,d; vi arr;
void HLD(){
    vi preorder; preorder.PB(0);
    for(int i=0;i<SZ(preorder);i++){
        int here = preorder[i];
        for(auto there : linked[here])
            if( there != nodes[here].par ){
                preorder.PB(there);
                nodes[there].par = here;
            }
    }
    for(int i=SZ(preorder)-1;i>=1;i--){
        int here=preorder[i], p=nodes[here].par;
        nodes[p].size += (++nodes[here].size);
        if(nodes[p].heavysize < nodes[here].size ){
            nodes[p].heavysize = nodes[here].size;
            nodes[p].heavychild = here;
        }
    } nodes[0].size++;
    for(auto i : preorder){
        int& idx = nodes[i].heavyidx; int h = nodes[i].heavychild;
        if(idx == -1){
            idx = SZ(paths);
            paths.PB(heavypath( 0, nodes[i].par ));
        } nodes[i].heavypos = paths[idx].size++;
        if(h != -1) nodes[h].heavyidx = idx;
    }
    for(int i=0;i<SZ(paths);i++) paths[i].init();
    for(int i=0;i<SZ(arr);i++){
		int j = arr[i];
        paths[nodes[j].heavyidx].tree.update(nodes[j].heavypos, i+1);
	}
}
Result pquery(int a, int b){
    Result resa, resb; resa = resb = { array<int,10>(), 0 };
    #define ascend(i) do {\
        int h=nodes[i].heavyidx;\
        int p=nodes[i].heavypos;\
        res##i = merge( paths[h].tree.query(0,p), res##i );\
        i=paths[h].par;\
    } while(0)
    while( nodes[a].heavyidx != nodes[b].heavyidx){
        if(nodes[a].heavyidx > nodes[b].heavyidx)
            ascend(a);
        else
            ascend(b);
    }
    #undef ascend
    int h=nodes[a].heavyidx;
    int pa=nodes[a].heavypos, pb=nodes[b].heavypos;
    if(pb<=pa) resa = merge(paths[h].tree.query(pa, pb), resa);
    if(pb>pa) resb = merge(paths[h].tree.query(pa, pb), resb);
    return merge( resa, resb );
}
int main(){
    scanf("%d%d%d",&N,&M,&Q);
    vi(M).swap(arr); vector<node>(N).swap(nodes); vvi(N).swap(linked);
    REP(i, N-1){
        scanf("%d%d",&a,&b); a--;b--;
        linked[a].PB(b); linked[b].PB(a);
    }
	REP(i, M){ scanf("%d",&arr[i]); arr[i]--; }
	HLD();
    while(Q--){
        scanf("%d%d%d",&a,&b,&c); a--;b--;
        Result res = pquery(a,b);
        printf("%d ", min(res.n, c) );
		for(int i=0; i<min(res.n, c); i++)
			printf("%d ",res.lst[i]);
		printf("\n");
	}
    return 0;
}
