// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N, va[55], ha[55] ,a,b;
int main(){
	scanf("%d",&N);
	for(int i=1; i<=N*N; i++){
		scanf("%d%d",&a,&b);
		if( va[a] == 0 && ha[b] == 0 ){
			printf("%d ",i);
			va[a] = 1; ha[b] = 1;
		}
	}
	return 0;
} 