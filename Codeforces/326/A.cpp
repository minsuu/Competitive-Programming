#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int N,a;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&a);
		pq.push( -a );
	}
	int cnt = 0;
	while( !pq.empty() ){
		if( pq.size() == 1 ){
			pq.pop(); cnt ++;
			break;
		}
		int a = pq.top(); pq.pop();
		if( pq.top() == a ){
			pq.pop();
			pq.push( a-1 );
		}else{
			cnt ++;
		}
	}
	printf("%d",cnt);
	return 0;
}
