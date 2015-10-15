// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N, fl[111111], ans[111111], mfl;
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&fl[i]);
	}
	for(int i=N-1; i>=0; i--){
		ans[i] = max(0, mfl+1-fl[i] );
		mfl = max( mfl, fl[i] );
	}
	for(int i=0; i<N; i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 