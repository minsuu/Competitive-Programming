#include <bits/stdc++.h>
using namespace std;

int a,b;
int main(){
    while(cin>>a>>b){
        if(a==0 && b==0) break;
        cout<<(a>b?"Yes":"No")<<"\n";
    }
    return 0;
}
