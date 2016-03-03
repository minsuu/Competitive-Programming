#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
string words[50050];
int N;
lld cache[50050];
const lld INF = 987654321987654321LL;

bool eqp( const string& a, const string& b ){
	if( a.size() > b.size() ) return false;
	for( int i=0; i<a.size(); i++)
		if( a[i] != b[i] ) return false;
	return true;
}

int len[50050], jmp[50050];

lld dp( int i ){
	if( i == N ) return 0;

	lld &ret = cache[i];
	if( ret != -1LL ) return ret;
	
	int k = i+1, l = words[i].size();
	string nw = words[i];

	ret = INF;
	for(int j=l; j>0; j--){
		while( k<N && eqp( nw, words[k] ) ) k++;
		lld nxt = (1LL<<(40-j)) + dp(k) ;
		if( ret > nxt ){
			ret = nxt;
			len[i] = j;
			jmp[i] = k;
		}
		nw.pop_back();
	}
	return ret;
}

int main(){
	freopen( "compression.in", "r", stdin );
	freopen( "compression.out", "w", stdout );
	ios::sync_with_stdio(false);
	memset( cache, -1, sizeof cache );
	cin>>N;
	for(int i=0; i<N; i++){
		cin>> words[i];
	}
	sort( words, words + N );
	printf("%lld\n",dp(0) );
	
	int i = 0;
	vector<string> anss;
	while( i < N ){
		anss.push_back( string( words[i].begin(), words[i].begin() + len[i] ).c_str() );
		i = jmp[i];
	}
	printf("%d\n",anss.size());
	for(auto it : anss ) printf("%s\n",it.c_str());

	fclose( stdin );
	fclose( stdout );
	return 0;
}
