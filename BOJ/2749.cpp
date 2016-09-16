#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
// f_n+f_{n-1} f_n
// f_n         f_{n-1}
int fib(lld n,int m){
    lld h,x=1,y=0;
    if(n==0) return y;
    for(h=1;h<=n;h*=2); h/=4;
    while(h){
        lld a = (x*(x+y)%m+x*y%m)%m;
        lld b = (x*x%m+y*y%m)%m;
        if(n&h){
            x=(a+b)%m; y=a;
        }else{
            x=a; y=b;
        }
        h/=2;
    }
    return x;
}

lld n;
int main(){
    cin>>n;
    cout<<fib(n,1000000);
    return 0;
}
