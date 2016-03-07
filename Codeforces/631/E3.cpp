
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int N, len, ptr, a[100100], b[100100];
lld A[100100], B[100100], D[100100];

void addLine( lld a, lld b ){
	while( len>=2 && (double) (B[len-2] - B[len-1] ) * ( a - A[len-1] ) >= (double) ( B[len-1] - b ) * ( A[len-1] - A[len-2] ) ) {
		--len;
	}
	A[len] = a; B[len] = b; len++;
}

lld minVal( lld x ){
	ptr = min( ptr, len - 1 );
	while( ptr+1 < len && A[ptr+1] * x + B[ptr+1] <= A[ptr]*x + B[ptr] ){
		++ptr;
	}
	return A[ptr]*x + B[ptr];
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	for(int i=0; i<N; i++) scanf("%d",&b[i]);
	
	D[0] = 0;
	addLine( b[0], D[0] );
	for(int i=0; i<N; i++){
		D[i] = minVal( a[i] );
		addLine( b[i], D[i] );
		for(int j=0; j<len; j++)
			printf("%lldx + %lld\n",A[j],B[j]);
		printf("%lld\n",D[i]);
	}
	printf("%lld\n",D[N-1]);
	return 0;
}
