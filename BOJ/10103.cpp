#include <bits/stdc++.h>
using namespace std;
int N,A=100,B=100,a,b;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        if(a<b) A-=b;
        else if(a>b) B-=a;
    }
    cout<<A<<"\n"<<B;
	return 0;
}
