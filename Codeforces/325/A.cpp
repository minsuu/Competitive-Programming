#include <bits/stdc++.h>
using namespace std;

int N; long long v[4444], d[4444], p[4444];
vector<int> line, ans;

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%lld%lld%lld",&v[i],&d[i],&p[i]);
	for(int i=0; i<N; i++)
		line.push_back( i );

	while( !line.empty() ){
		ans.push_back( *line.begin() );
		
		for(int i=1; i<line.size(); i++){
			line[i-1] = line[i];
		} line.pop_back();

		for(int i=0; i<v[ ans.back() ] && i<line.size(); i++){
			p[ line[i] ] -= ( v[ ans.back() ] - i );
		}

		vector<int> nline;
		long long sd = 0;
		for(int i=0; i<line.size(); i++){
			p[ line[i] ] -= sd;
			if( p[ line[i] ] < 0 ){
				sd += d[ line[i] ];
			}else{
				nline.push_back( line[i] );
			}
		} nline.swap( line );
	}
	printf("%d\n",ans.size());
	for( auto it : ans )
		printf("%d ",it+1);
	return 0;
}
