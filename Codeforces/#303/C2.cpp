#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
const int MAXL = 1987654321;
deque<int> D;
int N, lim, X[MAXN], H[MAXN];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d%d",&X[i],&H[i]);
	int ans = 0; lim = -MAXL;
	for(int i=0;i<N;i++){
		if( lim < X[i] - H[i] ){
			ans++; lim = X[i]; continue;
		}
		lim = X[i];
		if( i==N-1 || X[i] + H[i] < X[i+1] ){
			ans++; lim = X[i] + H[i];
		}
	}
	printf("%d",ans);
	return 0;
}