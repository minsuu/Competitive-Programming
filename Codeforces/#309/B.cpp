// Jun 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int N; lld K;
lld dp[55];
int main(){
	scanf("%d%lld",&N,&K); K--;
	dp[0] = dp[1] = 1;
	for(int i=2;i<=N;i++) dp[i] = dp[i-1] + dp[i-2];

	vector<int> part;
	int rn = N;
	while( K ){
		int np;
		for(np=1;np<=2;np++){
			if( dp[rn-np] <= K ) K -= dp[rn-np];
			else break;
		}
		part.push_back( np ); rn-=np;
	}
	vector<int> ans(N);
	for(int i=0;i<N;i++) ans[i] = i+1;

	int bg = 0;
	for(auto it : part){
		reverse( ans.begin() + bg, ans.begin() + bg + it);
		bg += it;
	}

	for(auto it : ans) printf("%d ",it);
	return 0;
}