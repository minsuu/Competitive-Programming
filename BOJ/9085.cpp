#include <bits/stdc++.h>
using namespace std;

int T,N,S,a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		S = 0;
		for(int i=0; i<N; i++){
			scanf("%d",&a);
			S += a;
		}
		printf("%d\n",S);
	}
	return 0;
}
