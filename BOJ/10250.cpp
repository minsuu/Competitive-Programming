#include <bits/stdc++.h>
using namespace std;
int T,H,W,N;
int main(){
    cin>>T;
    while(T--){
        cin>>H>>W>>N; N--;
        int a = N%H, b = N/H;
        printf("%d%02d\n",a+1,b+1);
    }
	return 0;
}
