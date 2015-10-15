// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int main(){
	int A,B;
	scanf("%d%d",&A,&B);
	if( A > B )
		printf("%d %d", B, (A-B)/2 );
	else
		printf("%d %d", A, (B-A)/2 );
	return 0;
} 