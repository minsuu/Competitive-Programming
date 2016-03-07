#include <bits/stdc++.h>
using namespace std;

int d[13],T,N;
int main(){
	d[0] = 1;
	for(int i=1; i<13; i++){
		for(int j=1; j<=3 && j<=i; j++)
			d[i] += d[i-j];
	}
	scanf("%d",&T);
	while( T-- ){
		scanf("%d",&N);
		printf("%d\n",d[N]);
	}
	return 0;
}
