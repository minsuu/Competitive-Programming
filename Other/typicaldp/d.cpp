// Aug 09 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef long double ld;

int N, d2, d3, d5;
lld D;
ld dp[111][66][44][33];
int f[6][3] = { { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 },
	 		    { 2, 0, 0 }, { 0, 0, 1 }, { 1, 1, 0 } };

int main(){
	scanf("%d%lld",&N,&D);
	while( D % 2 == 0 ) D/=2, d2++;
	while( D % 3 == 0 ) D/=3, d3++;
	while( D % 5 == 0 ) D/=5, d5++;
	if( D != 1 ) { printf("0\n"); return 0; }
	
	dp[0][0][0][0] = 1.0;
	for(int dr=1; dr<=N; dr++)
		for(int i2=0; i2<=d2; i2++)
			for(int i3=0; i3<=d3; i3++)
				for(int i5=0; i5<=d5; i5++)
					if( dp[dr-1][i2][i3][i5] != 0.0 )
						for(int dc=0; dc<6; dc++){
							int f2 = min( d2, i2 + f[dc][0] );
							int f3 = min( d3, i3 + f[dc][1] );
							int f5 = min( d5, i5 + f[dc][2] );
							dp[dr][f2][f3][f5] += dp[dr-1][i2][i3][i5] / 6.0;
						}
	printf("%.10Lf\n",dp[N][d2][d3][d5]);
	return 0;
} 