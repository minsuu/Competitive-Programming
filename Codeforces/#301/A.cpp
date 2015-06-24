// Jun 24 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N, ret; char s1[1111], s2[1111];
int main(){
	scanf("%d%s%s",&N,s1,s2);
	for(int i=0; i<N; i++){
		ret += min( abs(s1[i]-s2[i]), min(s1[i] - s2[i] + 10, s2[i] - s1[i] + 10 ) );
	}
	printf("%d",ret);
	return 0;
} 