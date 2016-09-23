#include <bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){
	for(int i=0;i<10;i++) cin>>a[i];
    for(int i=0;i<10;i++) cin>>b[i];
    int A=0,B=0;
    for(int i=0;i<10;i++){
        if(a[i]<b[i]) B++;
        if(a[i]>b[i]) A++;
    }
    if(A<B) cout<<"B";
    if(A>B) cout<<"A";
    if(A==B) cout<<"D";
	return 0;
}
