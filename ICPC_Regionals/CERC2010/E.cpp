#include <bits/stdc++.h>
using namespace std;

int T,N,M, lst[1111111], ass[1111111], wh[1111111];
set<int> zero;

int main(){
	scanf("%d",&T);
	while( T-- ){
		scanf("%d%d",&N,&M);
		for(int i=0; i<=N; i++) lst[i] = -1;
		for(int i=0; i<M; i++){
			scanf("%d", &wh[i] );
			ass[i] = 0;
		}
		set<int>().swap( zero );
		bool ab = true;
		for(int i=0; i<M; i++){
			if( wh[i] == 0 ){
				zero.insert( i );
			}else{
				int pond = wh[i];
				auto que = zero.lower_bound( lst[pond] );
				if( que == zero.end() ) { ab = false; break; }
				ass[*que] = pond; lst[pond] = i; zero.erase( que );
			}
		}
		if( ab ){
			printf("YES\n");
			for(int i=0; i<M; i++)
				if( wh[i] == 0 ) printf("%d ",ass[i]);
			printf("\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}