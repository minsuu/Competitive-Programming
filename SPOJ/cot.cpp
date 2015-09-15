#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int MAXN = 111111;
int mxwei;

// persistent segment tree by Anudeep Nekkanti
struct node
{
	int count; // # of elements within range [l, r)
	node *left, *right;
	
	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);
node *node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
		// With in the range, we need a new node
		if(l+1 == r)
		{
			return new node(this->count+1, null, null);
		}

		int m = (l+r)>>1;

		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}

	// Out of range, we can use previous tree node.
	return this;
}
node *root[MAXN];
int edges[MAXN<<1], eprev[MAXN<<1], elast[MAXN], ecnt;
vi wei;
int N,M, u,v,k;

void addEdge(int u, int v) {
	edges[ecnt] = v;
	eprev[ecnt] = elast[u];
	elast[u] = ecnt++;
}

// par[i][j] : 2^jth parent of i
int dep[MAXN], par[MAXN][20];
void dfs(int u, int p){
    par[u][0] = p; dep[u] = dep[p]+1 ;
    root[u] = root[p]->insert(0, mxwei, wei[u]);
    for(int i = elast[u]; i!=-1; i=eprev[i] ){
    	int v = edges[i];
        if( v == p ) continue;
        dfs(v, u);
    }
}

int up(int v, int k){
    for(int i=0; i<20; i++)
        if( 1<<i & k ) v = par[v][i];
    return v;
}
int lca(int u, int v){
    if( dep[u] < dep[v] )
        swap( u, v );
    u = up(u, dep[u] - dep[v]);
    if( u==v ) return u;
 
    for(int i=19; i>=0; i--)
        if( par[u][i] != par[v][i] )
            u = par[u][i], v = par[v][i];
    u = par[u][0], v = par[v][0];
    return u!=v ? -1 : u;
}

int query(node* a, node* b, node* c, node* d, int l, int r, int k){
	if( l+1 == r ){
		return l;
	}
	int cnt = a->left->count + b->left->count - c->left->count - d->left->count;
	int m = (l+r)/2;
	// printf("(%d~%d) %d=%d+%d-%d-%d %d \n",l,m,cnt,a->left->count,b->left->count,c->left->count,d->left->count,k);
	if( cnt >= k )
		return query( a->left, b->left, c->left, d->left, l, m, k );
	return query( a->right, b->right, c->right, d->right, m, r, k-cnt );
}

int nums[MAXN];
int main(){
	scanf("%d%d",&N,&M);
	memset( elast, -1, sizeof elast );
	vi(N).swap(wei);
	null->left = null->right = null;
	
	for(int i=0; i<N; i++){
		root[i] = null;
		scanf("%d",&wei[i]);
		nums[i] = wei[i];
	}
	sort(nums, nums+N );
	mxwei = unique( nums, nums+N ) - nums;

	for(int i=0; i<N; i++)
		wei[i] = lower_bound( nums, nums+mxwei, wei[i] ) - nums;

	for(int i=0; i<N-1; i++){
		scanf("%d%d",&u,&v); u--; v--;
		addEdge( u, v);
		addEdge( v, u);
	}
	
	memset(par, -1, sizeof par);
	dfs(0, 0);
    for(int j=1; j<20; j++)
        for(int i=0; i<N; i++)
            par[i][j] = par[ par[i][j-1] ][j-1];
	
	for(int i=0; i<M; i++){
		scanf("%d%d%d",&u,&v,&k); u--; v--;
		int lc = lca( u, v );
		int lcp = par[lc][0];
		
		//printf("Query %d %d %d (lca %d lcp %d)\n",u,v,k,lc,lcp);
		int q = query( root[u], root[v], root[lc], lc==lcp? null : root[lcp], 0, mxwei, k );
		printf( "%d\n", nums[q] );
	}
	return 0;
}