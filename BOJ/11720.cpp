#include <bits/stdc++.h>
using namespace std;

int N,ans;
string S;
int main(){
    cin>>N>>S;
    for(char i : S){
        ans += i-'0';
    }
    cout<<ans;
    return 0;
}
