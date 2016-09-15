#include <bits/stdc++.h>
using namespace std;

int N,n,a,b=987654321;
int main(){
  cin>>N;
  for(int i=0; i<N; i++){
    cin>>n;
    a = max(a, n);
    b = min(b, n);
  }
  cout<<b<<" "<<a;
  return 0;
}
