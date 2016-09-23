#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
	cin>>N;
    int a=987654321;
    for(int i=0;i<=N/5;i++){
        if((N-5*i)%3==0){
            a=min(a, i+(N-5*i)/3);
        }
    }
    if(a==987654321) a=-1;
    cout<<a;
	return 0;
}
