#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

string A,g;
int P[1111][1111], term[27], gn;
map<ii,int> gram;

int main(){
	ios::sync_with_stdio(false);
	cin>>A; int N = A.size();
	while( cin>>g ){
		int a = 1<<(g[0] - 'A');
		if( g.size() == 2 ){
			term[ g[1] - 'a' ] |= a;
		}else{
			gram[ ii( g[1] - 'A', g[2] - 'A' ) ] |= a;
		}
	}
	for(int i=0; i<N; i++){
		P[0][i] |= term[ A[i]-'a' ];
	}
	for(int i=1; i<N; i++){
		for(int j=0; j<N-i; j++){
			for(int k=0; k<i; k++){
				for( auto it : gram ){
					int a = it.first.first, b = it.first.second;
					if( ( P[k][j] & (1<<a) ) && ( P[i-k-1][j+k+1] & (1<<b) ) )
						P[i][j] |= it.second;
				}
			}
		}
	}
	/*
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ",P[i][j]);
		printf("\n");
	} */
	if( P[N-1][0] & ( 1<< ('S'-'A') ) )
		printf("1");
	else
		printf("0");	
	return 0;
}
