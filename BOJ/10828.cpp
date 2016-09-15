#include <bits/stdc++.h>
using namespace std;

int N,n;
string cmd;
stack<int> S;
int main(){
  cin>>N;
  while(N--){
    cin>>cmd;
    if(cmd=="push"){
      cin>>n;
      S.push(n);
    }else if(cmd=="pop"){
      if(S.size()){
        cout<<S.top()<<'\n';
        S.pop();
      }else{
        cout<<-1<<'\n';
      }
    }else if(cmd=="size"){
      cout<<S.size()<<'\n';
    }else if(cmd=="empty"){
      cout<<(S.empty()?1:0)<<'\n';
    }else if(cmd=="top"){
      if(S.size()){
        cout<<S.top()<<'\n';
      }else{
        cout<<-1<<'\n';
      }
    }
  }
  return 0;
}
