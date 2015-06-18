#include <bits/stdc++.h>
using namespace std;
int N, adj[111][111];
vector<int> ans;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&adj[i][j]);
	for(int i=0;i<N;i++){
		bool isans = true;
		for(int j=0;j<N;j++)
			if( adj[i][j] == 1 || adj[i][j] == 3 ){
				isans = false; break;
			}
		if( isans ) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(auto it : ans) printf("%d ",it+1);
	return 0;
}