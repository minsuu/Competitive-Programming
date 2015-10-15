// Oct 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int T,k,n,a[111], b[50];
int main(){
	scanf("%d",&T);
	b[0] = 0;
	for(int i=1; i<50; i++){
		int j = 0; set<int> s;
		while( (1<<j) <= i ){
			if( i & (1<<j) )
				s.insert( b[j] );
			j++;
		}
		int k;
		for(k=0; k<50; k++)
			if( s.count(k) == 0 ) break;
		b[i] = k;
	}
	while(T--){
		scanf("%d%d",&k,&n);
		int sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
			sum ^= a[i];
		}
		int j = 0; set<int> s;
		while( (1LL<<j) <= k ){
			if( k & (1<<j) )
				s.insert( b[j] );
			j++;
		}
		int k;
		for(k=0; k<50; k++) if( s.count(k) == 0 ) break;

		if( sum == k ) printf("Second\n");
		else{
			bool av = false;
			for(int i=0; i<n; i++){
				int j = sum ^ a[i] ^ k;
				if( j < a[i] ) av = true;
			}
			if( av ) printf("First\n");
			else printf("Second\n");
		}
	}
	return 0;
}