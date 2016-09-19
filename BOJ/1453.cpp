#include <bits/stdc++.h>
using namespace std;
int N,c[101];
int main(){
	cin>>N;
    int s=0;
    for(int i=0;i<N;i++){
        int a; cin>>a;
        if(c[a]) s++;
        c[a]=1;
    }
    cout<<s;
	return 0;
}
