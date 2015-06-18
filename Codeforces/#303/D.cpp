#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1111111;
const int INF = 1987654321;
int N, T[MAXN], P[MAXN];
vector<int> ans;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&T[i]);
	sort( T, T+N );
	for(int i=0;i<N;i++) P[i] = INF;
	int ans=0; P[0] = 0;
	for(int i=0;i<N;i++){
		int p = upper_bound( P, P+N, T[i] ) - P - 1;
		P[p+1] = min( P[p+1], P[p] + T[i] );
		ans = max( ans, p+1 );
	}
	printf("%d",ans);
	return 0;
}