// Jun 27 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N,M,m, ans;
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d",&m);
		int a, con = 1; bool yes = true;
		for(int j=0;j<m;j++){
			scanf("%d",&a);
			if( a == con && yes ) con++;
			else yes = false;
		}
		con--;
		if( con != 0 ){
			ans += ( m - con );
			N -= con - 1;
		}else{
			ans += ( m - 1);
		}
	}
	ans += ( N - 1 );
	printf("%d",ans);
	return 0;
} 