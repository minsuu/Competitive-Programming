// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld ans = 0;
int N, sw[111111][2];
set<int> pos;
struct fenwick {
    vector<lld> values;
    void init(int n) {
        vector<lld>(n+1, 0).swap(values);
    }
    void add(int i, lld v) {
        // add v to position i
        for (i++; i < values.size(); i += i & -i) values[i] += v;
    }
    lld sum(int i) {
        // get sum of values from 0 to i
        lld total = 0;
        for (i++; i; i ^= i & -i) total += values[i];
        return total;
    }
};
int main(){
	scanf("%d",&N);	
	for(int i=0; i<N; i++){
		scanf("%d%d",&sw[i][0],&sw[i][1]);
		pos.insert(sw[i][0]); pos.insert(sw[i][1]);
	}
	vector<int> v1(pos.begin(), pos.end()), v2(pos.begin(), pos.end());
	for(int i=0; i<N; i++){
		int a = sw[i][0], b = sw[i][1];
		int av = lower_bound( v1.begin(), v1.end(), a ) - v1.begin();
		int bv = lower_bound( v1.begin(), v1.end(), b ) - v1.begin();
		swap( v2[av], v2[bv] );
	}
	vector<int> nv1, nv2, wei;
	for(int i=0; i< v1.size(); i++){
		nv1.push_back( v1[i] );
		nv2.push_back( v2[i] );
		wei.push_back( 1 );
		if( i+1 != v1.size() && v1[i+1] - v1[i] > 1 ){
			nv1.push_back( v1[i+1]-1 );
			nv2.push_back( v1[i+1]-1 );
			wei.push_back( v1[i+1] - v1[i] - 1 );
		}
	}
	fenwick tree; tree.init( nv1.size() );
	int all = (int)nv1.size() - 1;
	for(int i=0; i< nv1.size(); i++){
		int mp = lower_bound( nv1.begin(), nv1.end(), nv2[i] ) - nv1.begin();
		ans += wei[i] * ( tree.sum( all ) - tree.sum( mp ) );
		tree.add( mp, wei[i] );
	}
	printf("%lld",ans);
	return 0;
} 