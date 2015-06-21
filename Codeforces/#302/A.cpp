// Jun 20 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int dp[555][555],b[555], n,m,l,MOD, ans;
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&MOD);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=b[i];j<=l;j++)
			for(int k=1;k<=m;k++){
				dp[j][k] += dp[j-b[i]][k-1];
				dp[j][k] %= MOD;
			}
	for(int i=0;i<=l;i++)
		ans+=dp[i][m], ans%=MOD;
	printf("%d",ans);
	return 0;
} 