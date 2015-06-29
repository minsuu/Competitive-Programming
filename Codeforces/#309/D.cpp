// Jun 27 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long lld;

struct FRAC{
	int bdeg, deg, i;
	bool operator<(const FRAC& rhs) const{
		return (deg - bdeg) * 1LL * rhs.deg > (rhs.deg - rhs.bdeg) * 1LL * deg;
	}
};

const int MAXN = 111111;
int fort[MAXN];
vi linkd[MAXN];
FRAC init[MAXN];

int N,M,K, a,b,c;
int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0; i<N; i++) init[i] = {0, 0, i};
	for(int i=0; i<K; i++){
		scanf("%d",&a); a--; fort[a] = 1;
	}
	for(int i=0; i<M; i++){
		scanf("%d%d",&a,&b); a--;b--;
		linkd[a].push_back(b);
		linkd[b].push_back(a);
		init[a].deg++; init[b].deg++;
		if(fort[a]) init[b].bdeg++;
		if(fort[b]) init[a].bdeg++;
	}

	priority_queue<FRAC> pq;
	for(int i=0; i<N; i++)
		if( !fort[i] )
			pq.push(init[i]);

	vi deleted;
	FRAC maxi = {1, 1, 0};
	while( !pq.empty() ){
		FRAC t = pq.top(); pq.pop();
		if( init[t.i].i == -1 ) continue;
		if( init[t.i] < t && t < init[t.i] ) continue;

		deleted.push_back( t.i );
		if( !(maxi < t) ) maxi = t;
		init[t.i].i = -1;

		for( auto j : linkd[t.i] ){
			if( init[j].i == -1 ) continue;
			if( fort[j] ) continue;
			init[j].bdeg++;
			pq.push( init[j] );
		}
	}

	for(int i=0; i<deleted.size(); i++){
		if( deleted[i] == maxi.i ){
			printf("%d\n", (int)deleted.size() - i );
			for(int j=i; j<deleted.size();j++){
				printf("%d ",deleted[j]+1);
			}
			break;
		}
	}
	printf("%c","\n"[0>5]);
	return 0;
}