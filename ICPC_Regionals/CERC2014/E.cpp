#include <bits/stdc++.h>
using namespace std;

int N, Seq[1111];
typedef pair<int, int> II;
typedef pair<int, II> STATE;

// ( A ) ( B )
map<STATE, bool> cache;
bool Play( int i, int A, int B ){
	if( i == N ){
		if( B != 0 ) return false;
		for(int j=0; j<=13; j++)
			if( A == (1<<j ) ){
				cache[ {i, {A,B} } ] = true;
				return true;	
			} 
		return false;
	}

	if( cache.count( { i, {A,B} } ) ) return cache[ {i, {A,B} } ];
	bool& ret = cache[ { i, { A, B } } ]; ret = false;

	int sA = A - ( A & (A-1));
	if( sA == 0 || Seq[i] <= sA ){
		ret |= Play( i+1, A + Seq[i], B );
	}
	int sB = B - ( B & (B-1));
	if( sB == 0 || Seq[i] <= sB ){
		B += Seq[i];
		if( ( A & B ) * 2 > A || B > A ){
			int lB = 1;
			while( lB <= B ) lB*=2; lB/=2;
			assert( A < lB || (A & lB) );
			B -= lB;
			A += lB;
		}
		ret |= Play( i+1, A, B );
	}
	return ret;
}

int T;
int main(){
	// freopen("E.out","w", stdout);
	scanf("%d",&T);
	while( T-- ){
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			scanf("%d",&Seq[i]);
		}
		cache.clear();
		bool ans = Play( 0, 0, 0 );
		if( !ans ) printf("no\n");
		else{
			int A = 0, B = 0;
			string ans;
			for(int i=0; i<N; i++){
				int sA = A - ( A & (A-1));
				if( (sA == 0 || Seq[i] <= sA) && cache[ { i+1, { A + Seq[i], B } } ] ){
					ans.push_back('l');
					A += Seq[i];
				}else{
					ans.push_back('r');
					B += Seq[i];
					if( ( A & B ) * 2 > A || B > A ){
						int lB = 1;
						while( lB <= B ) lB*=2; lB/=2;
						B -= lB;
						A += lB;
					}
				}
			}
			printf("%s\n",ans.c_str());	
		}
	}
	// fclose(stdout);
	return 0;
}