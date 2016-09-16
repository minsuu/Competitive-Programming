#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin>>N;
    // 1 1*6 2*6
    N--;
    int a = 1;
    while(N>0){
        N-=a*6;
        a++;
    }
    cout<<a;
	return 0;
}
