#include <bits/stdc++.h>
using namespace std;
int a[10],b[10],A,B,C=3;
int main(){
    for(int i=0;i<10;i++)cin>>a[i];
    for(int i=0;i<10;i++)cin>>b[i];
    for(int i=0;i<10;i++){
        if(a[i]<b[i]) {C=1; B+=3;}
        else if(a[i]>b[i]) {C=0; A+=3;}
        else {A++; B++;}
    }
    if(A>B) C=0;
    else if(A<B) C=1;
    cout<<A<<" "<<B<<"\n";
    cout<<(char)('A'+C);
	return 0;
}
