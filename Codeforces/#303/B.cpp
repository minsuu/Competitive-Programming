#include <bits/stdc++.h>
using namespace std;
const int MAXL = 111111;
char A[MAXL], B[MAXL]; int N, diff;
vector<int> d;
int main(){
	scanf("%s%s",A,B); N = strlen(A);
	for(int i=0;i<N;i++){
		if(A[i]!=B[i]) diff++, d.push_back(i);
	}
	if(diff%2) printf("impossible");
	else{
		for(int i=0;i<(int)d.size()/2;i++)
			A[d[i]]^=1;
		printf("%s",A);
	}
	return 0;
}