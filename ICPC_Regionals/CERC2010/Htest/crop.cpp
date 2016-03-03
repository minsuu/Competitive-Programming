#include <bits/stdc++.h>
using namespace std;
int T,N, a,b;
char type[1024], buf[1024];
string str;

int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		sprintf( buf, "in%02d.txt", t );
		freopen( buf, "w", stdout );
		
		scanf("%d",&N);
		printf("1\n%d\n",N);
		for(int i=0; i<N; i++){
			scanf("%d%d%s",&a,&b,type);
			printf("%d %d %s\n",a,b,type);
		}
		fclose( stdout );
	}
	return 0;
}
