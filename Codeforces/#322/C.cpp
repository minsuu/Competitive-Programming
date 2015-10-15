// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
priority_queue<ii> pq;

int N,K, lev[111111], rnk;
int main(){
	scanf("%d%d",&N,&K);	
	for(int i=0; i<N; i++)
		scanf("%d",&lev[i]);
	for(int i=0; i<N; i++){
		pq.push( { lev[i]%10, lev[i] } );
		rnk += lev[i]/10;
	}
	while( !pq.empty() && 0<K ){
		int rem = pq.top().first;
		int lv = pq.top().second; pq.pop();
		if( 100 <= lv ) continue;
		if( 10-rem > K ) break;
		K -= 10-rem; rnk++;
		pq.push( { 0, lv+(10-rem) } );
	}
	printf("%d",rnk);
	return 0;
}