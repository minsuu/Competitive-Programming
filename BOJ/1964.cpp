#include <bits/stdc++.h>
using namespace std;
int N,s=1;
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        s+=(i+1)*3+1;
        s%=45678;
    }
    cout<<s;
	return 0;
}
