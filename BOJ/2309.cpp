#include <bits/stdc++.h>
using namespace std;
int a[9],s;
int main(){
	for(int i=0; i<9; i++){
		scanf("%d",a+i);
		s += a[i];
	}
	sort( a, a + 9 );
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if( s - a[i] - a[j] == 100 ){
				for(int k=0; k<9; k++){
					if( i==k || j==k ) continue;
					printf("%d\n", a[k]);
				}
			}
		}
	}
	return 0;
}
