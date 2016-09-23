#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
	cin>>N;
    for(int i=0;i<N-1;i++) cout<<" "; cout<<"*\n";
    for(int i=1;i<N-1;i++){
        for(int j=0;j<N-i-1;j++) cout<<" ";
        cout<<"*";
        for(int j=0;j<i*2-1;j++) cout<<" ";
        cout<<"*\n";
    }
    if(N==1) return 0;
    for(int i=0;i<2*N-1;i++) cout<<"*";
	return 0;
}
