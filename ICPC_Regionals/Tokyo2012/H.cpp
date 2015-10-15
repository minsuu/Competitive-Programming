#include <bits/stdc++.h>
using namespace std;
int N,M, a[11111], b[11111], c[11111];
int sub[111][111], dis[111][111];
vector<int> dfsv, disc;

void dfs(int v){
	disc[v] = 1;
	for(int i=0; i<N; i++){
		if( sub[i][v] && !disc[i] ){
			dfs( i );
		}
	}
	dfsv.push_back( v );
}

bool dec(int V){
	memset( sub, 0, sizeof sub );
	memset( dis, 0, sizeof dis );

	for(int i=0; i<V; i++){
		if( a[i] == 1 ){
			sub[ b[i] ][ c[i] ] = 1;
		}
		if( a[i] == 2 ){
			sub[ b[i] ][ c[i] ] = 1;
			sub[ c[i] ][ b[i] ] = 1;
		}
	}
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			if( !sub[i][k] ) continue;
			for(int j=0; j<N; j++){
				sub[i][j] |= sub[i][k] & sub[k][j];
			}
		}
	}
	for(int i=0; i<V; i++){
		if( a[i] == 4 ){
			dis[ b[i] ][ c[i] ] = 1;
			for(int j=0; j<N; j++){
				if( sub[j][c[i]] )
					dis[ b[i] ][ j ] = 1;
			}
			dis[ c[i] ][ b[i] ] = 1;
			for(int j=0; j<N; j++){
				if( sub[j][b[i]] )
					dis[ c[i] ][ j ] = 1;
			}
		}
	}
	vector<int>(N).swap(disc);
	vector<int>().swap(dfsv);
	for(int i=0; i<N; i++){
		if( !disc[i] ) dfs(i);
	}
	reverse( dfsv.begin(), dfsv.end() );
	for(int di=0; di<N; di++){
		int i = dfsv[di];
		for(int j=0; j<N; j++){
			if( sub[i][j] ){
				for(int k=0; k<N; k++)
					dis[i][k] |= dis[j][k];
			}
		}
	}
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) dis[i][j] |= dis[j][i];

	for(int i=0; i<V; i++){
		if( a[i] == 3 ){
			if( dis[ b[i] ][ b[i] ] && dis[ c[i] ][ c[i] ] )
				return false;
			if( sub[ b[i] ][ c[i] ] && sub[ c[i] ][ b[i] ] )
				return false;
		}
		if( a[i] == 5 ){
			if( dis[ b[i] ][ b[i] ] || dis[ c[i] ][ c[i] ] )
				return false;
			if( dis[ b[i] ][ c[i] ] )
				return false;
		}
	}
	return true;
}

int main(){
	while(1){
		scanf("%d%d",&N,&M);
		if( N == 0 && M == 0 ) break;

		for(int i=0; i<M; i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			b[i]--; c[i]--;
		}
		if( dec(M) ) { printf("%d\n",M); continue; }
		int l = 0, h = M;
		while( l + 1 < h ){
			int m = ( l + h ) / 2;
			if( dec(m) ){
				l = m;
			}else{
				h = m;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}