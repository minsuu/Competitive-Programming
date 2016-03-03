#include <bits/stdc++.h>
using namespace std;
const int L = 300333;
int T;

int rad[2*L];
void longest_palindrome(const char* text, int n){
	int i,j,k;
	for(int i=0, j=0; i<2*n; i+=k, j=max(j-k,0) ) {
		while( i>=j && i+j+1 < 2*n && text[(i-j)/2] == text[(i+j+1)/2] ) ++j;
		rad[i] = j;
		for(k=1; i>=k && rad[i] >= k && rad[i-k] != rad[i] - k; ++k )
			rad[i+k] = min(rad[i-k], rad[i]-k);
	}
}
int seg[2*L], l;
char str[2*L];

void build(){
	for(int i=l-1; i>0; i--){
		seg[i] = max( seg[i*2], seg[i*2+1] );
	}
}

int firstk(int i, int j, int k){
	i += l, j += l; int fnd = -1;
	while( i < j ){
		if( i % 2 ){
			if( seg[i] >= k ) { fnd = i; break; }
			i++;
		}
		if( j % 2 ){
			j--;
			if( seg[j] >= k ) fnd = j;
		}
		i/=2; j/=2;
	}
	if( fnd == -1 ) return -1;
	while( fnd < l ){
		if( seg[fnd*2] >= k ) fnd *= 2;
		else fnd = fnd*2 + 1;
	}
	return fnd-l;
}

int main(){
	scanf("%d",&T);
	while( T-- ){
		scanf("%s", str ); l = strlen( str );
		memset( rad, 0, sizeof rad );
		longest_palindrome( str, l );


		for(int i=1; i<2*l; i+=2){
			seg[ l + i/2 ] = rad[ i ] + i;
			// printf("(%d)%d ",rad[i] + i );
		} build( );
		// printf("\n");

		int ans = 0;
		for(int i=1; i<2*l; i+=2){
			if( rad[i] != 0 ){
				int lpos = firstk( i/2 - rad[i]/4, i/2, seg[l+i/2] - rad[i] );
				if( lpos != -1 ){
					ans = max( ans, (i/2 - lpos)*4 );
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}