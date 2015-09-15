#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;
int N;
int main(){
	scanf("%d",&N);
	if( N==1 ) { puts("0"); return 0; }
	if( N==2 ) { puts("1"); return 0; }
	int a = 0, b = 1;
	for(int i=3; i<=N; i++){
		int c = (i-1) * 1LL * ( a+ 0LL + b ) % MOD;
		a = b; b = c;
	}
	printf("%d",b);
	return 0;
}