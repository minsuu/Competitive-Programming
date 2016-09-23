#include <bits/stdc++.h>
using namespace std;
int N,c[10010];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int n;
        scanf("%d",&n);
        c[n]++;
    }
    for(int i=1;i<=10000;i++){
        for(int j=0;j<c[i];j++)
            printf("%d\n",i);
    }
	return 0;
}
