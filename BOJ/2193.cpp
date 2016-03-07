#include <bits/stdc++.h>
using namespace std;

long long d[100][2];
int main(){
	d[1][0] = 0; d[1][1] = 1;
	for(int i=2; i<100; i++){
		d[i][0] = d[i-1][0] + d[i-1][1];
		d[i][1] = d[i-1][0];
	}int n;
	scanf("%d",&n);
	printf("%lld", d[n][0] + d[n][1] );
	return 0;
}
