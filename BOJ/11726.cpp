#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int N,a,b,c;
int main(){
    scanf("%d",&N);
    a=b=1;
    for(int i=1;i<N;i++){
        c=(a+b)%MOD; a=b; b=c;
    }
    printf("%d",b);
    return 0;
}
