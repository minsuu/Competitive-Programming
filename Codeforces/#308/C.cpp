// Jun 19 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int w, m, seq[30], sn;
int main(){
	scanf("%d%d",&w,&m);
	while( m ){
		seq[sn++] = m % w; m /= w;
	}
	bool able=true;
	for(int i=0; i<=sn; i++){
		if( seq[i] == 1 || seq[i] == 0 ) continue;
		if( seq[i] == w-1 || seq[i] == w ){
			seq[i+1]++;
		}else{
			able = false; break;
		}
	}
	if(able) printf("YES");
	else printf("NO");
	return 0;
} 