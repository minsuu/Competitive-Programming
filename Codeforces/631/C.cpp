#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[200200], q[200200][2];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	for(int i=0; i<M; i++){
		scanf("%d%d",&q[i][0],&q[i][1]);
	}

	int mx = 0;
	for(int i=M-1; i>=0; i--){
		if( mx < q[i][1] ){
			mx = q[i][1];
		}else{
			q[i][1] = -1;
		}
	} M++;
	
	deque<int> dq; int dir = -1, l = -1, ll = - 1;
	vector<int> ans;
	for(int i=0; i<M; i++){
		if( q[i][1] != -1 ){
			if( ll == -1 ){
				l = ll = q[i][1];
				sort( a, a + ll );
				for(int j=N-1; j>=ll; j--) ans.push_back( a[j] ); 
				for(int j=0; j<ll; j++) dq.push_back( a[j] );
				dir = q[i][0];
			}else{
				if( dir == 1 ){
					for(int j=q[i][1]; j<l; j++){
						ans.push_back( dq.back() ); dq.pop_back();
					}
				}else{
					for(int j=q[i][1]; j<l; j++){
						ans.push_back( dq.front() ); dq.pop_front();
					}
				}
				dir = q[i][0]; l = q[i][1];
			}
		}
	}
	reverse( ans.begin(), ans.end() );
	for( auto i : ans ) printf("%d ",i);
	return 0;
}
