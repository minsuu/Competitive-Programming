// Jun 28 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 222222;
int N,M, p,l;
int pos[MAXN]; ii sorted[MAXN];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		scanf("%d",&pos[i]);
		sorted[i] = { pos[i], i };
	}
	sort( sorted, sorted + N );
	
	while(M--){
		scanf("%d%d",&p,&l); p--;

		while(1){
			int pro = lower_bound( sorted, sorted+N, ii( pos[p] + l + 1, 0 ) ) - sorted - 1;
			int prol = l - ( sorted[pro].first - pos[p] );
			int pre = lower_bound( sorted, sorted+N, ii( sorted[pro].first - prol, 0 ) ) - sorted;
			int prel = prol - ( sorted[pro].first - sorted[pre].first );
			// printf("%d %d %d %d\n",sorted[pro].first,prol,sorted[pre].first,prel);
			if( l == prel ) break;
			if( p == sorted[pre].second )
				prel = prel % ( ( sorted[pro].first - sorted[pre].first ) * 2LL );
			l = prel; p = sorted[pre].second;
		}
		printf("%d\n",p+1);
	}

	return 0;
}