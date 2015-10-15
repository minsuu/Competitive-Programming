#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 987654321;
int brd[333][333], psum[333][333], W,L,N,K,a,b;
int dr[333][333], ul[333][333];

#define ps(A,B,C,D) (psum[C][D] - psum[C][B-1] - psum[A-1][D] + psum[A-1][B-1])

inline int getint() {
	int ret = 0, ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for (ret = ch - '0', ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) {
		ret = ret * 10 + ch - '0';
	}
	return ret;
}

int main(){
	W = getint(); 	L = getint();
	N = getint();	K = getint();
	for(int i=0; i<N; i++){
		a = getint(); b = getint();
		brd[a][b]++;
	}
	for(int i=1; i<=W; i++)
		for(int j=1; j<=L; j++)
			psum[i][j] = brd[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];

	for(int i=1; i<=W; i++){
		for(int j=1; j<=L; j++){
			int k = i, res = INF;
			for(int l=1; l<=j; l++){
				while( 1<k && ps( k,l, i,j) < K ) k--;
				if( ps(k,l,i,j) == K ){
					res = min( res, (i-k+1 + j-l+1) * 2 );
				}
			}
			dr[i][j] = res;

			k = i, res = INF;
			for(int l=L; l>=j; l--){
				while( k<W && ps( i,j, k,l) < K ) k++;
				if( ps(i,j,k,l) == K ){
					res = min( res, (k-i+1 + l-j+1) * 2 );
				}
			}
			ul[i][j] = res;
		}
	}
	int ans = INF;
	for(int v=1; v<L; v++){
		int res = INF;
		for(int i=1; i<=W; i++)
			for(int j=1; j<=v; j++)
				res = min( res, dr[i][j] );
		int res2 = INF;
		for(int i=1; i<=W; i++)
			for(int j=v+1; j<=L; j++)
				res2 = min( res2, ul[i][j] );
		ans = min( ans, res + res2 );
	}
	for(int h=1; h<W; h++){
		int res = INF;
		for(int i=1; i<=h; i++)
			for(int j=1; j<=L; j++)
				res = min( res, dr[i][j] );
		int res2 = INF;
		for(int i=h+1; i<=W; i++)
			for(int j=1; j<=L; j++)
				res2 = min( res2, ul[i][j] );
		ans = min( ans, res + res2 );
	}

	if( ans == INF ) printf("NO\n");
	else printf("%d\n",ans);
	return 0;
}