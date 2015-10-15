#include <bits/stdc++.h>
using namespace std;

int T,N,d[22][22], s[22];
bool r[1<<20];

void rec( int st ){
	r[st] = true;
	for(int i=0; i<N; i++){
		if( st & (1<<i) && s[i] > 0 && !r[st-(1<<i)]){
			for(int j=0; j<N; j++) if( st & (1<<j) ) s[j] += d[i][j];
			rec( st - (1<<i) );
			for(int j=0; j<N; j++) if( st & (1<<j) ) s[j] -= d[i][j];
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){

		scanf("%d",&N);
		for(int i=0; i<N; i++){
			s[i] = 0;
			for(int j=0; j<N; j++){
				scanf("%d",&d[i][j]);
				s[i] += d[i][j];
			}
		}

		for(int i=0; i<(1<<N); i++) r[i] = 0;
		rec( (1<<N)-1 );

		bool ex = false;
		for(int i=0; i<N; i++){
			if( r[1<<i] ){
				ex = true;
				printf("%d ",i+1);
			}
		}
		if( !ex ) printf("0");
		printf("\n");
	}
	return 0;
}