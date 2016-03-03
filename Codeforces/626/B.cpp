#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>

using namespace std;
typedef long long lld;
bool vis[222][222][222];
void rec(int r, int g, int b){
	if( vis[r][g][b] ) return;
	vis[r][g][b] = true;
	
	if( r>1 ) rec(r-1, g, b );
	if( g>1 ) rec(r, g-1, b );
	if( b>1 ) rec(r, g, b-1 );
	if( r>0 && g>0 ) rec( r-1, g-1, b+1 );
	if( r>0 && b>0 ) rec( r-1, g+1, b-1 );
	if( g>0 && b>0 ) rec( r+1, g-1, b-1 );
}

int main(){
	int l; char str[222];
	scanf("%d%s",&l,str);
	int r = 0, g = 0, b = 0;
	for(int i=0; i<l; i++){
		if( str[i] == 'R' ) r++;
		if( str[i] == 'B' ) b++;
		if( str[i] == 'G' ) g++;
	}
	rec( r,g,b );
	if( vis[0][0][1] ) printf("B");
	if( vis[0][1][0] ) printf("G");
	if( vis[1][0][0] ) printf("R");
	return 0;
}
