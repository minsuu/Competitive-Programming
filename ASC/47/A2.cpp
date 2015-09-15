// Sep 11 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<double, int> di;
const double PI = acos(-1);

int N,M,T;
int dx[2222],dy[2222], fx[2222],fy[2222], tx[2222], ty[2222];
int enc[2222], pts[2222];
vector<di> ags;

int main(){
#ifdef ONLINE_JUDGE
	freopen("ambitious.in", "rt", stdin);
	freopen("ambitious.out", "w", stdout);
#endif
	while( 1 ){
		scanf("%d",&N); // drones
		if( N == 0 ) break;

		for(int i=0; i<N; i++)
			scanf("%d%d",&dx[i], &dy[i]);
		scanf("%d",&M); // forts
		for(int i=0; i<M; i++)
			scanf("%d%d",&fx[i], &fy[i]);		
		scanf("%d",&T); // towers
		for(int i=0; i<T; i++)
			scanf("%d%d",&tx[i], &ty[i]);

		long long ans = 0LL;
		for(int i=0; i<M; i++){
			vector<di>().swap(ags);
			for(int j=0; j<N; j++){
				int xx = dx[j] - fx[i], yy = dy[j] - fy[i];
				double ta = atan2( yy, xx );
				ags.push_back( { ta , 0 } );
				ags.push_back( { ta + 2*PI , 0 } );
				ags.push_back( { ta + 4*PI , 0 } );
			}
			for(int j=0; j<T; j++){
				int xx = tx[j] - fx[i], yy = ty[j] - fy[i];
				double ta = atan2( yy, xx );
				ags.push_back( { ta , j+1 } );
				ags.push_back( { ta + 1*PI , -(j+1) } );
				ags.push_back( { ta + 2*PI , j+1 } );
				ags.push_back( { ta + 3*PI , -(j+1) } );
				ags.push_back( { ta + 4*PI , j+1 } );
				ags.push_back( { ta + 5*PI , -(j+1) } );
			}
			memset( enc, 0, sizeof enc );
			memset( pts, 0, sizeof pts );

			sort( ags.begin(), ags.end() );
			deque<long long> dq;

			int ptl = 0;
			for( auto it : ags ) {
				// printf("%d ",it.S);
				if( it.S == 0 ){
					ptl ++;
				}else if( it.S < 0 ){
					int nw = -it.S -1; enc[nw]++;
					if( enc[nw] == 2 ){
						long long dsum = dq.back() - dq.front();
						dsum -= ( (int) dq.size() - 1 ) * 1LL * pts[nw];
						ans += dsum;
					}
					dq.pop_front();
				}else{
					int nw = it.S -1;
					pts[ nw ] = ptl;
					dq.push_back( (dq.size()==0 ? 0 : dq.back() ) + ptl );
				}
			} // printf("\n");
		}
		printf("%lld\n",ans);
	}
	return 0;
} 