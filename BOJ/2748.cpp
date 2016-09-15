#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int N;
lld a,b,c;
int main(){
    cin>>N;
    b=1;
    for(int i=1; i<N;i++){
        c = a+b; a = b; b = c;
    }
    cout<<b;
    return 0;
}
