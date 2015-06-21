// Jun 21 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n,m, a,b, s1,t1,l1, s2,t2,l2, dist[3333][3333];
vvi linkd;
int main(){
	scanf("%d%d",&n,&m); vvi(n).swap(linkd);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b); a--; b--;
		linkd[a].push_back(b);
		linkd[b].push_back(a);
	}
	scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
	s1--; t1--; s2--; t2--;

	memset( dist, -1, sizeof dist );
	for(int i=0;i<n;i++){
		queue<int> q; q.push(i); dist[i][i] = 0;
		while(!q.empty()){
			int here = q.front(); q.pop();
			for(auto there : linkd[here])
				if( dist[i][there] == -1 ){
					dist[i][there] = dist[i][here] + 1;
					q.push(there);
				}
		}
	}
	int mini = 987654321;
	if( dist[s1][t1] <= l1 && dist[s2][t2] <= l2 )
		mini = min(mini, dist[s1][t1] + dist[s2][t2]);
	for(int v1=0; v1<n; v1++){
		for(int v2=0; v2<n; v2++){
			if( dist[s1][v1] + dist[v1][v2] + dist[v2][t1] <= l1
				&& dist[s2][v1] + dist[v1][v2] + dist[v2][t2] <= l2 ){
				mini = min(mini, dist[s1][v1] + dist[v1][v2] + dist[v2][t1]
								+dist[s2][v1] + dist[v2][t2]);
			}
			if( dist[s1][v2] + dist[v2][v1] + dist[v1][t1] <= l1
				&& dist[s2][v1] + dist[v1][v2] + dist[v2][t2] <= l2 ){
				mini = min(mini, dist[s1][v2] + dist[v2][v1] + dist[v1][t1]
								+dist[s2][v1] + dist[v2][t2]);
			}
		}
	}
	if( mini == 987654321 ) printf("-1");
	else printf("%d",m-mini);
	return 0;
}