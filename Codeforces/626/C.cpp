#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int ans = 987654321;
	for(int i=0; i<=m; i++){
		int x = i * 6;
		int a = max( 0, m - 2*i );
		int b = x - 3 + 6*a;
		int c = max( 0, n - 2*i );
		int d = x + 2*c;
		ans = min( ans, max( b, d ) );
	}
	printf("%d",ans);
	return 0;
}
