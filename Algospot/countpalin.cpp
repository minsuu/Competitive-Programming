// Oct 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MAXL = 1000011;
int rad[2*MAXL];
void longest_palindrome( const char *text, int n ){
	int i,j,k;
	for( i=0, j=0; i<2*n; i+=k, j=max(j-k,0) ){
		while( i>=j && i+j+1<2*n && text[(i-j)/2] == text[(i+j+1)/2] ) ++j;
		rad[i] = j;
		for(k=1; i>=k && rad[i]>=k && rad[i-k]!=rad[i]-k; ++k )
			rad[i+k] = min(rad[i-k], rad[i]-k);
	}
}
int T,N;
char buf[MAXL];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&N,buf);
		longest_palindrome( buf, N );
		long long ans = 0LL;
		for(int i=0; i<2*N; i++){
			if( i%2==0 ) ans += (rad[i]-1)/2;
			else ans += rad[i]/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 