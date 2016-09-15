#include <bits/stdc++.h>
using namespace std;
int N;
set<int> rem;
int main(){
    for(int i=0;i<10;i++){
        cin>>N;
        rem.insert(N%42);
    }
    cout<<rem.size();
    return 0;
}
