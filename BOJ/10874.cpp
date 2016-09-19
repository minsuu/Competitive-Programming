#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        int a; bool t=true;
        for(int j=0;j<10;j++){
            cin>>a;
            if(a!=(j%5+1)) t=false;
        }
        if(t) cout<<i<<"\n";
    }
	return 0;
}
