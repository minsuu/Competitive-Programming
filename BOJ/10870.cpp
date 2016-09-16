#include <bits/stdc++.h>
using namespace std;
int N,a,b,c;
int main(){
    cin>>N;
    if(N==0){
        cout<<0;
        return 0;
    }
    a=0; b=1;
    for(int i=1;i<N;i++){
        c=a+b; a=b; b=c;
    }
    cout<<b;
	return 0;
}
