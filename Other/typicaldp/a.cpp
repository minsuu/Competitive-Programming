// Aug 09 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int sc[111], N, avmax;
bool av[111111];

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&sc[i]);

	av[0] = true; avmax = 0;
	for(int i=0; i<N; i++){
		for(int j=avmax; j>=0; j--)
			if( av[j] ) av[ j + sc[i] ] = true;
		avmax += sc[i];
	}

	int ans = 0;
	for(int i=0; i<=avmax; i++)
		if(av[i] ) ans++;
	printf("%d\n",ans);
	return 0;
} 