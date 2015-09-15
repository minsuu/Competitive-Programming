#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
typedef long long lld;

struct v3{
	int x,y,z, i;
	v3 cross( const v3& rhs ) {
		return { y * rhs.z - z * rhs.y, -(x*rhs.z - z*rhs.x), x*rhs.y - y*rhs.x };
	}
	lld dot( const v3& rhs ){
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}
};

typedef pair<int, int> ii;

vector<ii> ans;
v3 pts[111111];
int pidx[6][111111];

bool chk( int n, int k ){
	if( n <= k ){
		for(int i=0; i<n; i++)
			ans.push_back( { pidx[k][i]+1 , -1 } );
		return true;
	}
	if( k == 0 ) return false;

	int mdel = -1, ma, mb, nn = 0;
	for(int i=0; i<100; i++){
		int a = rand() % n;
		int b = rand() % (n-1);
		if( b>=a ) b++;

		v3 pt = pts[ pidx[k][a] ].cross( pts[ pidx[k][b] ] );
		if( pt.z == 0 ) continue;

		int del = 0;
		for(int j=0; j<n; j++){
			if( pt.dot( pts[ pidx[k][j] ] ) == 0LL )
				del++;
		}

		if( del > mdel ){
			nn = 0;
			for(int j=0; j<n; j++){
				if( pt.dot( pts[ pidx[k][j] ] ) != 0LL )
					pidx[k-1][nn++] = pidx[k][j];
			}
			mdel = del; ma = pidx[k][a]+1, mb = pidx[k][b]+1;
		}
	}

	if( mdel == -1 ) return false;
	ans.push_back( { ma , mb } );
	if( chk(nn, k-1) ) return true;
	ans.pop_back();

	return false;
}

int N,K;

int main(){

	srand( unsigned ( time(0) ) );

	scanf("%d%d",&N,&K);
	for(int i=0; i<N; i++){
		scanf("%d%d%d",&pts[i].x, &pts[i].y, &pts[i].z );
		pidx[K][i] = i;
	}

	if( chk( N, K ) ){
		printf("YES\n");
		printf("%d\n", (int) ans.size() );
		for(auto it : ans ){
			printf("%d %d\n",it.first, it.second);
		}
	}else{
		printf("NO");
	}
	return 0;
}