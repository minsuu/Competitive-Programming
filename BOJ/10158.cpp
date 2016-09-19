#include <bits/stdc++.h>
using namespace std;
int w,h,p,q,t;
int main(){
    cin>>w>>h>>p>>q>>t;	
    int a=(p+t)%w, b=(q+t)%h;
    if((p+t)/w%2) a=w-a;
    if((q+t)/h%2) b=h-b;
    cout<<a<<" "<<b;
	return 0;
}
