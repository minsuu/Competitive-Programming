#include <bits/stdc++.h>
using namespace std;
int a,b,A,B;
int main(){
    for(int i=0;i<3;i++){
        cin>>a>>b;
        A^=a; B^=b;
    }
    cout<<A<<" "<<B;
	return 0;
}
