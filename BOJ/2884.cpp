#include <bits/stdc++.h>
using namespace std;
int A,B;
int main(){
    cin>>A>>B;
    B-=45;
    if(B<0) {A--; B+=60;}
    A=(A+24)%24;
    cout<<A<<" "<<B;
	return 0;
}
