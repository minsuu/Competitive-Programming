// Aug 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
const int MOD = 1e9+7;
int T,N;
int a[MAXN], twop[MAXN];

const int INF = 987654321;

int main(){
	twop[0] = 1;
	for(int i=1; i<MAXN; i++)
		twop[i] = twop[i-1] * 2LL % MOD;

	scanf("%d",&T);	
	while(T--){
		scanf("%d",&N);
		for(int i=0; i<N; i++)
			scanf("%d",&a[i]);
	
		bool zero = false;
		int pl = -INF, ml = -INF, pm = -INF, mm = -INF, sp = -INF;
		for(int i=0; i<N; i++){
			if( a[i] == 0 ){
				pl = ml = -INF;
				zero = true;
			}
			if( a[i] == 1 ){
				pl = max( pl, 0 );
			}
			if( a[i] == 2 ){
				pl = max( pl+1, 1 ); ml++;
			}
			if( a[i] == -1 ){
				swap( ml, pl );
				ml = max( ml, 0 );
			}
			if( a[i] == -2 ){
				swap( ml, pl );
				ml = max( ml+1, 1 ); pl++;
			}
			pm = max( pm, pl ); mm = max( mm, ml ); sp = max( sp, a[i] );
		}
		if( pm >= 0 ) printf("%d\n",twop[pm] );
		else if( zero ) printf("0\n");
		else printf("%d\n", sp );
	}
	return 0;
} 