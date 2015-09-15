#include <bits/stdc++.h>
using namespace std;

vector<char> vow, con;
char vc[33], buf[9], ans[222], word[222];
int N,M,V,cn, a,b,c,d;
bool adj[444][444], ve,ce;

int setTrue[444];

bool go(int n, bool any);

inline bool step( int n, bool any, char c ){	
	int nvc = ( vc[c-'a'] == 'C' ); bool poss = true;
	if( setTrue[ (n*2+nvc)^1 ] ) poss = false;
	for(int i=0; i<V && poss; i++)
		if( adj[ n*2 + nvc ][i] && setTrue[i^1] ) poss = false;
	if( poss ){
		ans[n] = c; setTrue[2*n+nvc]++;
		for(int i=0; i<V; i++) if( adj[ n*2 + nvc ][i] ) setTrue[i]++;
		if( go(n+1,any) ) return 1;
		for(int i=0; i<V; i++) if( adj[ n*2 + nvc ][i] ) setTrue[i]--;
		setTrue[2*n+nvc]--;
	}
	return 0;
}

bool go(int n, bool any){
	// this
	if( n == N ) return 1;
	if( !any ) if(step( n, any, word[n] )) return 1;	
	// other
	int vv, cc;
	if( !any ){
		vv = upper_bound( vow.begin(), vow.end(), word[n] ) - vow.begin();
		cc = upper_bound( con.begin(), con.end(), word[n] ) - con.begin();
	}else{
		vv = cc = 0;
	}
	if( vv == vow.size() && cc == con.size() ) return 0;
	else if( vv == vow.size() ) return step(n, 1, con[cc] );
	else if( cc == con.size() ) return step(n, 1, vow[vv] );
	else{
		if( vow[vv] < con[cc] ){
			if( step(n, 1, vow[vv] ) || step(n, 1, con[cc] ) ) return 1;
		}else{
			if( step(n, 1, con[cc] ) || step(n, 1, vow[vv] ) ) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%s",vc); cn = strlen(vc);
	scanf("%d%d",&N,&M); V = 2*N;
	for(int i=0; i<M; i++){
		scanf("%d%s",&a,buf); a--; b = (*buf)=='C';
		scanf("%d%s",&c,buf); c--; d = (*buf)=='C';
		adj[ 2*a + b ][ 2*c + d ] = 1;
	}
	scanf("%s",word);

	for(int i=0; i<cn; i++){
		if( vc[i] == 'V' ) vow.emplace_back( 'a' + i );
		else if( vc[i] == 'C' ) con.emplace_back( 'a' + i );
	}

	if( vow.size()==0 ) for(int i=0; i<N; i++) adj[ 2*i ][ 2*i+1 ] =true;	
	if( con.size()==0 ) for(int i=0; i<N; i++) adj[ 2*i+1 ][ 2*i ] =true;
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				adj[i][j] |= ( adj[i][k] & adj[k][j] );
	
	bool ex = true;
	for(int i=0; i<N && ex; i++)
		if( adj[2*i][2*i+1] && adj[2*i+1][2*i] ) ex = false;
	if( !ex || !go(0,0) ) { printf("-1"); return 0; }
	printf("%s\n",ans);
	return 0;
}
