#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int NEUTRAL_VALUE = INT_MAX;
const int NEUTRAL_DELTA = 0;

struct treap{
	int nodeValue;
	int subTreeValue;
	int delta;
	int count;
	int prio;
	treap *l;
	treap *r;
};

treap nodes[MAXN];
int nodes_cnt;
vector<int> rnd;

static int getCount(treap* root){
	return root? root->count : 0;
}
static int getSubTreeValue( treap* root ){
	return root? root->subTreeValue: NEUTRAL_VALUE;
}

void update(treap *root){
	if(!root) return;
	root->subTreeValue = min( root->nodeValue, min( getSubTreeValue( root->l ), getSubTreeValue( root->r ) ) );
	root->count = getCount(root->l) + 1 + getCount(root->r);
}

void applyDelta( treap *root, int delta) {
	if( !root ) return;
	root->delta ^= delta;
	if( root->delta ) swap( root->l, root->r );
}

void pushDelta(treap *root ){
	if( !root ) return;
	applyDelta(root->l, root->delta);
	applyDelta(root->r, root->delta);
	root->delta = NEUTRAL_DELTA;
}

// l과 r을 합친 결과를 t에 저장함
void merge(treap* &t, treap* l, treap* r ){
	pushDelta( l );
	pushDelta( r );
	if( !l )
		t = r;
	else if( !r )
		t = l;
	else if( l->prio < r->prio )
		merge( l->r, l->r, r ), t = l;
	else
		merge( r->l, l, r->l ), t = r;
	update( t );
}

// t를 key개만큼을 잘라 l에, 나머지를 r에 할당함
void split(treap* t, treap* &l, treap* &r, int key ) {
	pushDelta(t);
	if( !t ) l = r = NULL;
	else if( key <= getCount(t->l) )
		split(t->l, l, t->l, key), r = t;
	else
		split(t->r, t->r, r, key - getCount(t->l)-1 ), l = t;
	update( t );
}

// t에서 index번째 요소의 nodeValue를 찾음
int get(treap* t, int index) {
	pushDelta( t );
	if( index< getCount(t->l) )
		return get(t->l, index);
	else if( index> getCount(t->l) )
		return get(t->r, index-getCount(t->l)-1);
	return t->nodeValue;
}

// t의 index번째에 item을 삽입하고 그걸 root로 리턴
void insert( treap* &t, treap* item, int index ){
	pushDelta(t);
	if( !t )
		t = item;
	else if( item->prio < t->prio )
		split( t, item->l, item->r, index), t = item;
	else if( index <= getCount(t->l) )
		insert( t->l, item, index );
	else
		insert( t->r, item, index- getCount(t->l) -1 );
	update( t );
}

// t의 index번째에 해당value값을 넣고 그걸 root로 리턴
void insert(treap* &root, int index, int value ){
	treap *item = &nodes[nodes_cnt];
	item->nodeValue = value;
	item->subTreeValue = value;
	item->delta = NEUTRAL_DELTA;
	item->count = 1;
	item->prio = rnd[nodes_cnt];
	++nodes_cnt;
	insert( root, item, index );
}

// t의 index번째 아이템을 삭제함 
void remove( treap* &t, int index ){
	pushDelta( t );
	if( index == getCount(t->l) )
		merge( t, t->l, t->r );
	else
		if( index < getCount(t->l) )
			remove( t->l, index );
		else
			remove( t->r, index-getCount(t->l)-1);
	update( t );
}

// a,b사이의 subtreeValue를 리턴함
int query( treap* &root, int a, int b ){
	treap *l1, *r1;
	split( root, l1, r1, b + 1 );
	treap *l2, *r2;
	split( l1, l2, l2, a );
	int res = getSubTreeValue( r2 );
	treap *t;
	merge( t, l2, r2 );
	merge( root, t, r1 );
	return res;
}

int minidx( treap* &root ){
	pushDelta( root );
	int nw = getSubTreeValue( root );
	printf("finding %d..\n", nw );
	if( nw == root->nodeValue ) return getCount( root->l );
	
	if( nw == getSubTreeValue( root->l ) ) return minidx( root->l );
	return getCount(root->l) + 1 + minidx( root->r );
}

int minquery( treap* &root, int a, int b ){	
	treap *l1, *r1;
	split( root, l1, r1, b+1 );
	treap *l2, *r2;
	split( l1, l2, r2, a );
	int res = a + minidx( r2 );
	treap *t;
	merge( t, l2, r2 );
	merge( root, t, r1 );
	return res;
}

void rev( treap* &root, int a, int b ){
	treap *l1, *r1;
	split( root, l1, r1, b+1 );
	treap *l2, *r2;
	split( l1, l2, r2, a );
	applyDelta( r2, 1 );
	treap *t;
	merge( t, l2, r2 );
	merge( root, t, r1 );
}

void print(treap* t ){
	if( !t ) return;
	pushDelta( t );
	print( t->l );
	cout << t->nodeValue << " " ;
	print( t->r );
}

int main (){
	for(int i=0; i<MAXN; i++)
		rnd.push_back( i );
	random_shuffle( rnd.begin(), rnd.end() );

	treap* t = NULL;
	vector<int> list = { 1, 9, 3, 2, 5, 12, 33 };
	for(auto it : list ) 
		insert( t, getCount(t) , it );
	print( t );
	 rev( t, 1, 5 );
	cout<<minquery( t, 1, 3 );
}
