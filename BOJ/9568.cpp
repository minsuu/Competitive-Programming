// Sep 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef pair<double, int> di;
const double PI = acos(-1);
int N,M, x,y;
int ans[55555];
vector<di> a;

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++){
		scanf("%d%d",&x, &y);
		double aa = atan2( y, x);
		double R = hypot( x, y);
		double bb = acos( M / R ); // [0, pi]
		a.push_back( { aa-bb, i } );
		a.push_back( { aa+bb, -i } );
		a.push_back( { aa-bb + 2*PI , i } );
		a.push_back( { aa+bb + 2*PI , -i } );
	}
	sort( a.begin(), a.end() );

	int p = 0; long long ret = 0LL;
	for( auto it : a ){
		if( it.S < 0 ){
			p--;
			if( ans[-it.S] == 1 ){
				ret += p;
				ans[-it.S] = 2;
			}
		}else if( it.S > 0 ){
			p++;
			if( 0 < it.F && ans[it.S] == 0 )
				ans[it.S] = 1;
		}
	}
	printf("%lld",ret);
	return 0;
}