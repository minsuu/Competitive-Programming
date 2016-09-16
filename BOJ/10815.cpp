#include <bits/stdc++.h>
using namespace std;
int N,M,n;
set<int> S;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&n);
        S.insert(n);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&n);
        printf("%d ",S.count(n));
    }
	return 0;
}
