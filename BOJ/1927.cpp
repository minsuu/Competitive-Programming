#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> pq;

int main(){
    cin>>N;
    while(N--){
        int n;
        cin>>n;
        if(n==0){
            if(pq.empty()){
                cout<<"0\n";
            }else{
                cout<<-pq.top()<<"\n";
                pq.pop();
            }
        }else{
            pq.push(-n);
        }
    }
	return 0;
}
