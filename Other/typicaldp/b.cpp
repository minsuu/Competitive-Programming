// Aug 09 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int A,B, ai[1111], bi[1111];
ii cache[1111][1111][2];
ii game(int a, int b, int st){
	if( a==0 && b==0 ) return {0,0};
	ii& ret = cache[a][b][st];
	if( ret.first != -1 ) return ret;

	ii sa, sb; sa = sb = {-1, -1};
	if( a ) sa = game( a-1, b, 1-st );
	if( b ) sb = game( a, b-1, 1-st );
	if( !st ){
		sa.first += ai[a], sb.first += bi[b];
		if( sa.first > sb.first ) return ret = sa;
		else return ret = sb;
	}
	sa.second += ai[a], sb.second += bi[b];
	if( sa.second > sb.second ) return ret = sa;
	else return ret = sb;
}

int main(){
	scanf("%d%d",&A,&B);
	for(int i=0; i<A; i++) scanf("%d",&ai[A-i]);
	for(int i=0; i<B; i++) scanf("%d",&bi[B-i]);
	for(int i=0; i<=A; i++)
		for(int j=0; j<=B; j++)
			cache[i][j][0] = cache[i][j][1] = {-1,-1};
	ii ans = game(A, B, 0);
	printf("%d\n",ans.first);
	return 0;
} 