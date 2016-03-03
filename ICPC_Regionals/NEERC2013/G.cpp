#include <bits/stdc++.h>
using namespace std;
string A,B;

int N, cn, ll;
vector<int> segs[123];
bool rs,ls;
int idx[123], len[123];

vector<int> compute_pi(string &P) {
	vector<int> pi(P.size());
	int k = pi[0] = -1;
	for(size_t i=1; i<P.size(); ++i){
		while( k>=0 && P[i] != P[k+1]) k = pi[k];
		if(P[i] == P[k+1]) ++k;
		pi[i] = k;
	}
	return pi;
}

void kmp(string &T, string &P, int cc ){
	int k = -1; vector<int> pi = compute_pi(P);
	for( size_t i=0; i<T.size(); ++i) {
		while( k>=0 && T[i] != P[k+1] ) k = pi[k];
		if(T[i] == P[k+1]) ++k;
		if( k >= (int) P.size() - 1) {
			segs[cc].push_back( i - (int)P.size() + 1 ); 
			k = pi[k];
		}
	}
}

bool dec( int st ){
	int en = st + N, nw = st;
	for(int i = 0; i<cn; i++){
		auto it = lower_bound( segs[i].begin(), segs[i].end(), nw );
		if( it == segs[i].end() ) return false;
		if( i==0 && !ls && (*it) != st ) return false;
		nw = (*it) + len[i];
		if( nw > en ) return false;
	}
	if( !rs ){
		int ss = en - len[cn-1];
		auto it = lower_bound( segs[cn-1].begin(), segs[cn-1].end(), ss );
		if( it == segs[cn-1].end() ) return false;
		if( (*it) != ss ) return false;
	}
	return true;
}

int main(){
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);

	ios::sync_with_stdio(false);
	cin>>A>>B; N = B.size(); B = B+B;
	string sA;
	for( int i=0; i<A.size(); i++){
		if( i && A[i-1] == '*' && A[i] == '*' ) continue;
		sA.push_back( A[i] );
	}
	sA.swap( A );
	if( A.size() == 1 ){
		if( A[0] == '*' ){
			printf("%d\n",N);
			return 0;
		}else{
			if( B.size() == 1 && B[0] == A[0] )
				printf("1\n");
			else
				printf("0\n");
			return 0;
		}
	}
	
	ls = ( A[0] == '*' ); rs = ( A.back() == '*' );
	stringstream ass(A); string cs;
	while( getline( ass, cs, '*') ){
		if( cs.size() == 0 ) continue;
		len[cn] = cs.size();
		kmp( B, cs, cn++ );
	}	

	int ans = 0;
	for(int i=0; i<N; i++){
		if( dec( i ) ) ans++;
	}
	printf("%d\n",ans);
	fclose( stdin );
	fclose( stdout );
	return 0;
}
