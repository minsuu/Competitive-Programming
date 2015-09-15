#include <bits/stdc++.h>
using namespace std;
int N,K, D[44], T[44], ans;
int main(){
    scanf("%d%d",&N,&K);
    D[0] = D[1] = 1; T[1] = 1;
    for(int i=2; i<=N; i++){
    	D[i] = D[i-1] + D[i-2];
    	T[i] = T[i-1] + D[i-1];
    }
    for(int f=1; f<=N; f++){
    	if( f == K ){
    		ans += ( D[f-1] * D[ N-f ] );
    	}else{
    		if( f < K ){
    			ans += ( D[ f-1 ] * D[ K-f-1 ] * D[ N-K ] );
    			ans += ( T[ f-1 ] * D[ K-f-1 ] * D[ N-K ] );
    			ans += ( D[ f-1 ] * T[ K-f-1 ] * D[ N-K ] );
    		}else{
    			ans += ( D[ f-K-1 ] * D[ N-f ] * D[ K-1 ] );
    			ans += ( T[ f-K-1 ] * D[ N-f ] * D[ K-1 ] );
    			ans += ( D[ f-K-1 ] * T[ N-f ] * D[ K-1 ] );
    		}
    	}
    }
    printf("%d",ans);
    return 0;
}