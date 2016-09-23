#include <bits/stdc++.h>
using namespace std;
int D,K;
struct st{
    int a,b;
    st operator+(const st& r){
        return {a+r.a, b+r.b};
    }
};

int main(){
    cin>>D>>K;
    st a={1,0}, b={0,1}, c;
    for(int i=2;i<D;i++){
        c=a+b; a=b; b=c;
    }
    for(int i=1;i<=K/b.a;i++){
        if((K-i*b.a)%b.b==0){
            cout<<i<<"\n"<<(K-i*b.a)/b.b<<"\n";
            break;
        }
    }
	return 0;
}
