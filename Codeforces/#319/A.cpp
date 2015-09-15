// Sep 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int siv[1111], N;
vector<int> pr, ans;
int main(){
	siv[1] = 1;
	for(int i=2; i<1111; i++){
		if( siv[i] ) continue;
		for(int j=i*2; j<1111; j+=i )
			siv[j] = 1;
	}
	for(int i=2; i<1111; i++){
		if( !siv[i] ) pr.push_back( i );
	}
	scanf("%d",&N);

	for( auto it : pr ){
		for( int i = it; i <= N; i *= it ){
			ans.push_back( i );
		}
	}

	printf("%d\n",ans.size() );
	for( auto it : ans )
		printf("%d ",it);
	return 0;
} 