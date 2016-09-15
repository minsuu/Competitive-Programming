#include <bits/stdc++.h>
using namespace std;

int N,n;
vector<int> seq;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>n;
        seq.insert(seq.begin() + (i-n), i+1);
    }
    for(int i : seq) cout<<i<<' ';
    return 0;
}
