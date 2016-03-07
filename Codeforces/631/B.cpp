#include <bits/stdc++.h>
using namespace std;

int brd[5050][5050];
int las[2][5050];
int eve[100100][3];
int N,M,K;

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0; i<K; i++){
		scanf("%d%d%d",&eve[i][0],&eve[i][1],&eve[i][2]); eve[i][0]--; eve[i][1]--;
		las[ eve[i][0] ][ eve[i][1] ] = i;
	}
	for(int i=0; i<K; i++){
		if( i == las[ eve[i][0] ][ eve[i][1] ] ){
			// fill in
			if( eve[i][0] == 0 ){
				for(int j=0; j<M; j++)
					brd[ eve[i][1] ][j] = eve[i][2];
			}
			else if( eve[i][0] == 1 ){
				for(int j=0; j<N; j++)
					brd[j][ eve[i][1] ] = eve[i][2];
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			printf("%d ",brd[i][j]);
		}
		printf("\n");
	}
	return 0;
}
