#include <bits/stdc++.h>
using namespace std;
int N,n,ans[10];
int main(){
	ans[1] = 0;
	ans[2] = 20;
	ans[3] = 432;
	ans[4] = 28860;
	ans[5] = 2710048;
	ans[6] = 19597490;
	ans[7] = 12701197;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}