// Sep 01 2015, minsu( github : https://github.com/minsuu/ )
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int ST_SIZE = (1<<18)-1;
const int MAX_N = 111111;
const int MAX_M = 5555;

int A[MAX_N];
int nums[MAX_N];
vector<int> dat[ST_SIZE];

void init(int k, int l, int r){
	if (r-l == 1){
		dat[k].push_back( A[l] );
	}else{
		int lch = k*2+1, rch = k*2+2;
		init(lch, l, (l+r)/2 );
		init(rch, (l+r)/2, r );
		dat[k].resize(r-l);

		merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin() );
	}
}

// count the number that is equal or lower than x
int query(int i, int j, int x, int k, int l, int r){
	if( j<=l || r<=i ){
		return 0;
	}else if( i<=l && r<=j ){
		return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
	}else{
		int lc = query(i, j, x, k*2+1, l, (l+r)/2 );
		int rc = query(i, j, x, k*2+2, (l+r)/2, r );
		return lc + rc;
	}
}

int N,M, a,b,k;
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++) scanf("%d",&A[i]), nums[i] = A[i];
	sort( nums, nums + N );
	
	init(0, 0, N);

	while(M--){
		scanf("%d%d%d",&a,&b,&k); a--;
		int lb = -1, ub = N-1;
		while( ub - lb > 1 ){
			int md = (ub + lb)/2;
			int c = query(a, b, nums[md], 0, 0, N );
			if( c>=k ) ub = md;
			else lb = md;
		}
		printf("%d\n",nums[ub]);
	}
	return 0;
} 