
#include <bits/stdc++.h>
using namespace std;
int N,a[101],v,c;
int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    cin>>v;
    for(int i=0;i<N;i++){
        if(a[i]==v) c++;
    }
    cout<<c;
	return 0;
}
