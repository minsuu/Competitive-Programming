#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin>>N;
    for(int i=2;i<=N;i++){
        while(N%i==0){
            cout<<i<<"\n";
            N/=i;
        }
    }
	return 0;
}
