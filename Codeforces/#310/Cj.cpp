// Jun 28 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

const int inf=987654321;
struct snode {
    int i, j;
    int lm, um, lp, up;
    snode *l, *r;
    snode(int i, int j): i(i), j(j), lm(0), um(0), lp(0), up(0) {
        if (j - i == 1) {
            l = r = NULL;
        } else {
            int k = (i + j) >> 1;
            l = new snode(i, k);
            r = new snode(k, j);
        }
    }
    ~snode() { delete l; delete r; }
    void visit() {
        if (lp) {
            lm = max( lm, lp);
            if (l) l->lp = max(l->lp, lp);
            if (r) r->lp = max(r->lp, lp);
            lp = 0;
        }
        if (up) {
            um = max( um, up);
            if (l) l->up = max(l->up, up);
            if (r) r->up = max(r->up, up);
            up = 0;
        }
    }
    void uup(int I, int J, int v) {
        if (I <= i && j <= J) {
            up=max(up,v); visit();
        } else if (j <= I || J <= i) {
            return;
        } else {
            visit();
            l->uup(I,J,v); r->uup(I,J,v);
            um=max(l->um, r->um);
        }
    }
    void lup(int I, int J, int v) {
        if (I <= i && j <= J) {
            lp=max(lp,v); visit();
        } else if (j <= I || J <= i) {
            return;
        } else {
            visit();
            l->lup(I,J,v); r->lup(I,J,v);
            lm=max(l->lm, r->lm);
        }
    }
    ii find(int P){
    	visit();
        if(j-i==1) return { um, lm };
        else{
            int k = (i + j) >> 1;
            if(P<k) return l->find(P);
            else return r->find(P);
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
			int a = tree.root->find( x ).first;
			int b = lower_bound(nx.begin(), nx.end(), N-a) - nx.begin();

			if(ate[x]) { printf("0\n"); continue; }
			printf("%d\n", q[i].b - a );

			tree.root->lup( x, b+1, q[i].a );
			ate[x] = 1;

		}else{
			int a = tree.root->find( x ).second;
			int b = lower_bound(nx.begin(), nx.end(), a) - nx.begin();

			if(ate[x]) { printf("0\n"); continue; }
			printf("%d\n", q[i].a - a );

			tree.root->uup( b, x, q[i].b );
			ate[x] = 1;
		}
	}
	return 0;
} 