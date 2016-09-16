#include <bits/stdc++.h>
using namespace std;
string S;
int ans;
stack<int> s;
int main(){
    cin>>S;
    for(int i=0; i<S.size(); i++){
        if(S[i] == '('){
            s.push(i);
        }else if(S[i] == ')'){
            if(s.top() == i-1){
                s.pop();
                ans += s.size();
            }else{
                ans++;
                s.pop();
            }
        }
    }
    cout<<ans;
	return 0;
}
