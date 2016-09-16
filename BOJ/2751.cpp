#include <bits/stdc++.h>
using namespace std;
int N,a[1000100];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a, a+N);
    for(int i=0;i<N;i++)
        cout<<a[i]<<"\n";
	return 0;
}
