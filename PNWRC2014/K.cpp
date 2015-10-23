#include <bits/stdc++.h>
using namespace std;
typedef array<int,5> ROW;

int N,T, in[6][6], rr[6][2], up[6], dw[6];
int mk[6][6], uc[6][6];

char board[11][11];
vector<ROW> perm[6][6][6];

bool rec( int r ){
	if( r==N ){
		for(int i=0; i<N; i++){
			int l = 0, ls = -1;
			for(int j=N-1; j>=0; j--) if(ls<mk[j][i]) ls=mk[j][i], l++;
			if( dw[i] != 0 && dw[i] != l ) return false;
		}
		return true;
	}
	for( auto it : perm[N][ rr[r][0] ][ rr[r][1] ] ){
		bool con = false;
		for(int i=0; i<N && !con; i++){
			if( uc[i][ it[i] ] ) con = true;
		} if( con ) continue;
		for(int i=0; i<N && !con; i++){
			if( in[r][i] != 0 && in[r][i] != it[i] ) con = true;
		} if( con ) continue;
		for(int i=0; i<N; i++){
			if( it[i] == N ){
				int l = 0, ls = -1;
				for(int j=0; j<r; j++) if(ls<mk[j][i]) ls=mk[j][i], l++;
				if( up[i] != 0 && up[i] != l+1 ) con = true;
				break;
			}
		} if( con ) continue;

		for(int i=0; i<N; i++){
			mk[r][i] = it[i];
			uc[i][ it[i] ] = true;
		}
		if( rec( r+1 ) ) return true;
		for(int i=0; i<N; i++){
			uc[i][ it[i] ] = false;
		}
	}
	return false;
}

int main(){
	for(int n=3; n<=5; n++){
		array<int,5> nw;
		for(int i=0; i<n; i++) nw[i] = i+1;
		do{
			int l = 0, ls = -1;
			for(int i=0; i<n; i++) if(ls<nw[i]) ls=nw[i], l++;
			int r = 0, rs = -1;
			for(int i=n-1; i>=0; i--) if(rs<nw[i]) rs=nw[i], r++;
			perm[n][l][r].push_back(nw);
			perm[n][0][r].push_back(nw);
			perm[n][l][0].push_back(nw);
			perm[n][0][0].push_back(nw);
		}while( next_permutation( nw.begin(), nw.begin()+n ) );
	}

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		assert( 3<=N && N<=5 );
		for(int i=0; i<N+2; i++){
			scanf("%s",board[i]);
			assert( strlen(board[i]) == N+2 );
		}
		for(int i=1; i<=N; i++){
			rr[i-1][0] = max(0, board[i][0] - '0');
			rr[i-1][1] = max(0, board[i][N+1] - '0');
			up[i-1] = max(0, board[0][i] - '0');
			dw[i-1] = max(0, board[N+1][i] - '0');
		}
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				in[i-1][j-1] = max(0, board[i][j] - '0');
		memset( mk, 0, sizeof mk ); memset( uc, 0, sizeof uc );
		if( rec(0) ){
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++)
					printf("%d",mk[i][j]);
				if( T!=0 || i!=N-1 ) printf("\n");
			}
		}else{
			printf("no");
			if( T!=0 ) printf("\n");
		}
		if( T!=0 ) printf("\n");
	}
	return 0;
}
