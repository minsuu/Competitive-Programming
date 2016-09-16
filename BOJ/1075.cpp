#include <bits/stdc++.h>
using namespace std;
int N,F;
int main(){
    cin>>N>>F;	
    N -= N%100;
    for(int i=0;i<100;i++){
        if( (N+i)%F == 0 ){
            printf("%02d",i);
            break;
        }
    }
	return 0;
}
