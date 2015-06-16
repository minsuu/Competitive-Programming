#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef pair<lld,lld> ii;
#define xx first
#define yy second
const int MAXN = 5e5+10;
const int BSIZE = sqrt(MAXN)+10;

int N,M, bn; ii S[MAXN];
lld Add[BSIZE], A[MAXN];
inline void update(int bn){
	int bg = bn * BSIZE, en = min( N, bg + BSIZE );
	for(int j=bg; j<en; j++) S[j] = { A[j], j };
	sort( S+bg, S+en );
}
void add(int l, int r, int x){
	int lb = l / BSIZE, rb = r / BSIZE;
	if( lb == rb ){
		for(int i=l; i<=r; i++) A[i]+=x;
		update(lb);
	}else{
		int le = min( N, lb*BSIZE + BSIZE);
		for(int i=l; i<le; i++) A[i]+=x;
		for(int i=rb*BSIZE; i <= r; i++) A[i]+=x;
		update(lb); update(rb);
		for(int i = lb+1; i < rb; i++) Add[i]+=x;
	}
}
int query(int x){
	int mini = -1, maxi = -1;
	//for(int i=0; i<N; i++) cout<<S[i].xx<<"/"<<S[i].yy<<"    "; cout<<"\n";
	for(int i=0; i<bn; i++){
		if( Add[i] > x ) continue;
		int bg = i * BSIZE, en = min( N, bg + BSIZE );
		int p = lower_bound( S+bg, S+en, ii(x-Add[i], -1) ) - S;
		if( p != en && S[p].xx + Add[i] == x ) { mini = S[p].yy; break; } 
	}
	for(int i=bn-1; i>=0; i--){
		if( Add[i] > x ) continue;
		int bg = i * BSIZE, en = min( N, bg + BSIZE );
		int p = lower_bound( S+bg, S+en, ii(x-Add[i]+1, -1) ) - S; p--;
		if( p != en && p >= bg && S[p].xx + Add[i] == x ) { maxi = S[p].yy; break; }
	}
	if(mini == -1 || maxi==-1) { assert(mini==-1 && maxi==-1); return -1; }
	return maxi - mini;
}
int main(){
	scanf("%d %d",&N,&M); bn = (N + BSIZE-1) / BSIZE;
	for(int i=0;i<N;i++) scanf("%lld",&A[i]);
	for(int i=0; i<bn; i++) update(i);
	for(int i=0;i<M;i++){
		int t, l, r, x;
		scanf("%d", &t);
		if(t==1){
			scanf("%d %d %d", &l, &r, &x); l--; r--;
			add(l, r, x);
		}else{
			scanf("%d", &x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}