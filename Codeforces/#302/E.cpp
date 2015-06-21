#include <bits/stdc++.h>
using namespace std;
const int MAXN = 222222, MOD = 1e9+7;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct STE { int here, it; };
stack<STE> st;
int N, par[MAXN], dp[MAXN], ret[MAXN];
vi ord;
vvi linkd, pre, post;
int main(){
	scanf("%d",&N);
	vvi(N).swap(linkd); vvi(N).swap(pre); vvi(N).swap(post);
	par[0] = -1;
	for(int i=1;i<N;i++){
		scanf("%d", &par[i]), par[i]--;
		linkd[par[i]].push_back(i);
	}
	ord.push_back( 0 );
	for(int i=0;i<ord.size();i++){
		int h = ord[i];
		for(auto j : linkd[h])
			ord.push_back(j);
	}
	for(auto it=ord.rbegin(); it!=ord.rend(); ++it){
		int h = *it; dp[h] = 1;
		pre[h].push_back(1); post[h].push_back(1);
		for(auto j : linkd[h]){
			pre[h].push_back( pre[h].back() * 1LL * (dp[j] + 1 ) % MOD );
			dp[h] = dp[h] * 1LL * (dp[j] + 1) % MOD;
		}
		for(auto j = linkd[h].rbegin(); j!=linkd[h].rend(); ++j){
			post[h].push_back( post[h].back() * 1LL * (dp[*j] + 1) % MOD );
		}
		reverse( post[h].begin(), post[h].end() );
	}
	/*
	for(int i=0; i<N; i++){
		for(auto j : pre[i]) printf("%d ",j); printf("\n");
		for(auto j : post[i]) printf("%d ",j); printf("\n");
	} printf("%d ",dp[i]); */
	st.push({ 0, 0 });
	while(!st.empty()){
		int h = st.top().here, i = st.top().it++;
		if( i == 0 ) ret[h] = dp[h];
		if( i == linkd[h].size() ){
			dp[h] = post[h][0];
			dp[par[h]] = dp[par[h]] * 1LL * ( dp[h] + 1 ) % MOD;
			st.pop(); continue;
		}
		int t = linkd[h][i];
		dp[h] = pre[h][i] * 1LL * post[h][i+1] % MOD;
		if( par[h] != -1 ) dp[h] = dp[h] * 1LL * ( dp[par[h]] + 1) % MOD;
		dp[t] = dp[t] * 1LL * ( dp[h] + 1 ) % MOD;
		st.push({ t, 0 });
	}
	for(int i=0; i<N; i++) printf("%d ",ret[i]);
	return 0;
}