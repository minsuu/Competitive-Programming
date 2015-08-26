// Aug 25 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11111;
typedef long long lld;

int T,N, bs[MAXN], tr[MAXN];
lld dp[MAXN][33];
 
int main(){
    scanf("%d",&T);
 
    while(T--){
        scanf("%d",&N); assert( N <= MAXN );
        for(int i=0; i<N; i++){
            scanf("%d%d",&bs[i], &tr[i]);
        }
        memset( dp, 0, sizeof dp );
 
        for(int i=N-1; i>=0; i--){
            for(int j=30; j>=0; j--){
                if( j==0 ){
                    dp[i][j] = dp[i+1][j] + bs[i] + 2*tr[i];
                }else{
                    dp[i][j] = dp[i+1][j-1] + 2*tr[i];
                }
                // bus cards
				dp[i][j] = min( dp[i][j], dp[i+1][0] + 2*tr[i] + 3 );
				dp[i][j] = min( dp[i][j], dp[i+1][6] + 2*tr[i] + 18 );
				dp[i][j] = min( dp[i][j], dp[i+1][29] + 2*tr[i] + 45 );
                
                // travel cards
                dp[i][j] = min( dp[i][j], dp[i+1][max(0,j-1)] + 6 );
                dp[i][j] = min( dp[i][j], dp[i+7][max(0,j-7)] + 36 );
                dp[i][j] = min( dp[i][j], dp[i+30][max(0,j-30)] + 90 );
            }
        }
        printf("%lld\n",dp[0][0]);
    }
    return 0;
}