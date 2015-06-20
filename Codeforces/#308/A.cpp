// Jun 19 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N, cnt[111][111], a,b,c,d, ans;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int j=a;j<=c;j++) for(int k=b;k<=d;k++) cnt[j][k]++;
	}
	for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) ans+=cnt[i][j];
	printf("%d",ans);
	return 0;
} 