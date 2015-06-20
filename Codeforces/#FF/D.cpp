// Jun 18 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
typedef long double llf;
using namespace std;
const int MAXN=555;
llf imat[MAXN][MAXN], column[MAXN], nmat[MAXN][MAXN];
void takeInverse(int N, llf (&mat)[MAXN][MAXN]){
	int i,j,k,l; llf t, pv;
	for(i=0;i<N;i++) for(j=0;j<N;j++) imat[i][j]=(i==j);
	for(j=0;j<N;j++){
		l = j;
		for(i=j+1;i<N;i++)
			if(fabs(mat[i][j])>fabs(mat[l][j]))
				l = i;
		pv = mat[l][j];
		for(k=0;k<N;k++){
			swap(mat[j][k],mat[l][k]), swap(imat[j][k], imat[l][k]);
			mat[j][k] /= pv; imat[j][k] /= pv;
		}
		for(i=0;i<N;i++){
			if( i == j ) continue;
			t = mat[i][j] / mat[j][j];
			for(k=0;k<N;k++){
				 mat[i][k] -=  mat[j][k] * t;
				imat[i][k] -= imat[j][k] * t;
			}
		}
	}
	for(i=0;i<N;i++) for(j=0;j<N;j++) swap(mat[i][j], imat[i][j]);
}

int N,M,K, a,b, cn, adj[MAXN][MAXN], critical[MAXN], criticals[MAXN], degree[MAXN];
llf mat[MAXN][MAXN], tmp[MAXN][MAXN], R[MAXN][MAXN];
int main(){
	scanf("%d%d%d",&N,&M,&K); K-=2;
	for(int i=0;i<N;i++){
		scanf("%d",&critical[i]);
		if(critical[i]) criticals[cn++] = i;
	}
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b); a--; b--;
		adj[a][b]++; adj[b][a]++; degree[a]++; degree[b]++;
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			if( i == j ) mat[i][j] = 1;
			else mat[i][j] = critical[i] ? 0.0 : -1.0 * adj[i][j] / degree[i] ;
		}
	takeInverse(N, mat);
	for(int i=0; i<cn; i++){
		for(int j=0; j<cn; j++){
			llf p = 0.0;
			for(int k=0;k<N;k++) p += 1.0 * adj[criticals[i]][k] / degree[criticals[i]] * mat[k][criticals[j]];
			nmat[i][j] = p;
		}
	}
	for(int i=0; i<cn; i++) R[i][i]=1;
	while( K ){
		if( K & 1 ){
			for(int i=0; i<cn; i++)
				for(int j=0; j<cn; j++){
					tmp[i][j] = 0;
					for(int k=0; k<cn; k++)
						tmp[i][j] += R[i][k] * nmat[k][j];
				}
			memcpy( R, tmp, sizeof tmp );
		}
		for(int i=0; i<cn; i++)
			for(int j=0; j<cn; j++){
				tmp[i][j] = 0;
				for(int k=0; k<cn; k++)
					tmp[i][j] += nmat[i][k] * nmat[k][j];
			}
		memcpy( nmat, tmp, sizeof tmp );
		K >>= 1;
	}
	llf ans = 0;
	for(int i=0; i<cn; i++){
		ans += mat[0][criticals[i]] * R[i][cn-1];
	}
	cout<<setprecision(10)<<fixed<<ans;
	return 0;
} 