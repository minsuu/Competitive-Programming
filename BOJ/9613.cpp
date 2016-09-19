#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b){
        int r=a%b;
        a=b; b=r;
    }
    return a+b;
}
int T,N,a[101];
int main(){
	cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++) cin>>a[i];
        int s=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                s+=gcd(a[i],a[j]);
            }
        }
        cout<<s<<"\n";
    }
	return 0;
}
