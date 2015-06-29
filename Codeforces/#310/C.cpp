// Jun 28 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;

const int inf=987654321;
struct snode {
    int i, j, lm, um;
    snode *l, *r;
    snode(int i, int j): i(i), j(j), lm(0), um(0) {
        if (j - i == 1) {
            l = r = NULL;
        } else {
            int k = i + j >> 1;
            l = new snode(i, k);
            r = new snode(k, j);
        }
    }
    ~snode() { delete l; delete r; }
    void updatel(int P, int v){
        if(j-i==1) lm=max(lm, v);
        else{
            int k = (i + j) >> 1;
            if(P<k) l->updatel(P,v);
            else r->updatel(P,v);
            lm=max(l->lm, r->lm);
        }
    }
    void updateu(int P, int v){
        if(j-i==1) um=max(um, v);
        else{
            int k = i + j >> 1;
            if(P<k) l->updateu(P,v);
            else r->updateu(P,v);
            um=max(l->um, r->um);
        }
    }
    int maxl(int I, int J) {
        // get maximum of values from I to J-1
        if (I <= i && j <= J) {
            return lm;
        } else if (j <= I || J <= i) {
            return -inf;
        } else {
            return max(l->maxl(I, J), r->maxl(I, J));
        }
    }
    int maxu(int I, int J) {
        // get maximum of values from I to J-1
        if (I <= i && j <= J) {
            return um;
        } else if (j <= I || J <= i) {
            return -inf;
        } else {
            return max(l->maxu(I, J), r->maxu(I, J));
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
    void updatel(int i, int v){
        root->updatel(i,v);
    }
    void updateu(int i, int v){
        root->updateu(i,v);
    }
    int maxl(int i, int j) {
        // get maximum of values from i to j, or j to i
        if (i > j) swap(i,j);
        return root->maxl(i, j+1);
    }
    int maxu(int i, int j) {
        // get maximum of values from i to j, or j to i
        if (i > j) swap(i,j);
        return root->maxu(i, j+1);
    }
};

struct QUERY{ int a, b; char c; } q[222222];
int N,Q;  char c;
set<int> xs;
int main(){
	scanf("%d%d",&N,&Q);
	for(int i=0; i<Q; i++){
		char buf[5];
		scanf("%d%d%s",&q[i].a,&q[i].b,buf); q[i].c=*buf;
		xs.insert(q[i].a);
	}
	vector<int> nx(xs.begin(), xs.end());
	vector<int> ate(nx.size());
	segment tree; tree.init(nx.size());
	for(int i=0; i<Q; i++){
		int x = lower_bound(nx.begin(), nx.end(), q[i].a) - nx.begin();
		// printf("%d, %d %c :: ",x,y,q[i].c);
		if( q[i].c == 'U'){
			int a = tree.maxu( x, nx.size()-1 );
			if(ate[x]) a = q[i].b;
			printf("%d\n", q[i].b - a );
			tree.updatel( x, q[i].a );
			ate[x] = 1;
		}else{
			int a = tree.maxl( 0, x );
			if(ate[x]) a = q[i].a;
			printf("%d\n", q[i].a - a );
			tree.updateu( x, q[i].b );
			ate[x] = 1;
		}
	}
	return 0;
} 