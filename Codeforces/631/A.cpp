#include <bits/stdc++.h>
using namespace std;
int N, a[1010], b[1010];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	for(int i=0; i<N; i++) scanf("%d",&b[i]);

	int ans = 0;
	for(int i=0; i<N; i++){
		int sa = 0, sb = 0; 
		for(int j=i; j<N; j++){
			sa |= a[j];
			sb |= b[j];
			ans = max(ans, sa+sb);
		}
	}
	printf("%d",ans);
	return 0;
}
