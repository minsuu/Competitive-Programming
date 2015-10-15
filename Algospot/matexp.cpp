// Oct 10 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;

int T,N,C;
int m1[111][111], m2[111][111], m3[111][111];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&C);
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d",&m1[i][j]);
				m2[i][j] = 0;
			}
			m2[i][i] = 1;
		}

		int b = 1;
		while( b <= C ){
			if( b & C ){
				for(int i=0; i<N; i++)
					for(int j=0; j<N; j++){
						m3[i][j] = 0;
						for(int k=0; k<N; k++)
							m3[i][j] = ( m3[i][j] + 0LL + m1[i][k] * m2[k][j] ) % MOD;
					}
				memcpy( m2, m3, sizeof m3 );
			}
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++){
					m3[i][j] = 0;
					for(int k=0; k<N; k++)
						m3[i][j] = ( m3[i][j] + 0LL + m1[i][k] * m1[k][j] ) % MOD;
				}
			memcpy( m1, m3, sizeof m3 );
			b<<=1;
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				printf("%d ",m2[i][j]);
			printf("\n");
		}
	}
	return 0;
} 