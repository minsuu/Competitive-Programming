#include <bits/stdc++.h>
using namespace std;
vector<int> vv;
int main(){
	int n = 1;
	while( vv.size() < 1000 ){
		for(int i=0; i<n; i++) 
			vv.push_back( n );
		n++;
	}
	int a,b,s=0;
	scanf("%d%d",&a,&b); a--; b--;
	for(int i=a; i<=b; i++) s += vv[i];
	printf("%d",s);
	return 0;
}
