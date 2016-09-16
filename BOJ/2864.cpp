#include <bits/stdc++.h>
using namespace std;
string A,B;
int main(){
    cin>>A>>B;
    for(auto &c : A) if(c=='6') c='5';
    for(auto &c : B) if(c=='6') c='5';
    cout<<atoi(A.c_str()) + atoi(B.c_str())<<' ';
    for(auto &c : A) if(c=='5') c='6';
    for(auto &c : B) if(c=='5') c='6';
    cout<<atoi(A.c_str()) + atoi(B.c_str());
	return 0;
}
