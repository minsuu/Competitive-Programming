#include <bits/stdc++.h>
using namespace std;
struct kc{
	char a; long long b;
	bool operator==( const kc& l ) const{
		if( b == -1 || l.b == -1 ) return a == l.a;
		return a == l.a && b == l.b;
	}
	bool operator!=( const kc& l ) const{
		return !( *this==l);
	}
};
typedef vector<kc> kstring;

vector<int> compute_pi( kstring &P ){
	vector<int> pi(P.size());
	int k = pi[0] = -1;
	for(size_t i = 1; i < P.size(); i++ ){
		while( k>=0 && P[i]!=P[k+1] ) k = pi[k];
		if(P[i] == P[k+1]) ++k;
		pi[i] = k;
	}
	return pi;
}
kstring A,B;
long long ans = 0;

void kmp(kstring &T, kstring &P) {
	int k = -1; vector<int> pi = compute_pi(P);
	for( size_t i = 0; i < T.size(); i++ ){
		while( k>=0 && T[i] != P[k+1] ) k = pi[k];
		if( T[i] == P[k+1] ) ++k;
		if( k >= (int) P.size() - 1 ){
			if( P.size() == 1 ){
				ans += max( 0LL, A[i].b - B[0].b + 1 );
			}else{
				if( A[i-k].b >= B[0].b && A[i].b >= B[k].b ) ans ++;
			}
			k = pi[k];
		}
	}
}
int N,M; long long x;
char buf[33];

int main(){	
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		scanf("%lld-%s",&x,buf);
		if( !A.empty() && A.back().a == buf[0] ) A.back().b += x;
		else A.push_back( { buf[0], x } );
	}
	for(int i=0; i<M; i++){
		scanf("%lld-%s",&x,buf);
		if( !B.empty() && B.back().a == buf[0] ) B.back().b += x;
		else B.push_back( { buf[0], x } );
	}
	kstring D(B);
	D[0].b = D.back().b = -1;
	kmp( A, D );
	printf("%lld",ans);
	return 0;
}
