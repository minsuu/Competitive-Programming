#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>

using namespace std;

void go( char d, int& sx, int& sy ){
	if( d == 'U') sx++;
	if( d == 'D') sx--;
	if( d == 'R') sy++;
	if( d == 'L') sy--;
}

typedef long long lld;
int l;
char cmd[222];
int main(){
	scanf("%d",&l);
	scanf("%s",cmd);
	
	int ans = 0;
	for(int L=0; L<l; L++)
		for(int R=L+1; R<=l; R++){
			int cx = 0, cy = 0;
			for(int i=L; i<R; i++) go( cmd[i], cx, cy );
			if( cx == 0 && 0 == cy ) ans++;
		}

	printf("%d",ans);
	return 0;
}
