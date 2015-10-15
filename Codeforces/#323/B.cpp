// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N, rem, a[1111], val[1111];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]);
	}
	int turn = 0, dir = 1, nw = 0, inf = 0;
	while( inf < N ){
		while( 1 ){
			if( val[nw] == 0 && a[nw]<=inf ){
				val[nw] = 1; inf ++;
			}
			if( 0<= nw+dir && nw+dir<N ) nw+=dir;
			else break;
		}
		if( inf < N ) dir *= -1, turn ++;
	}
	
	printf("%d",turn);
	return 0;
} 