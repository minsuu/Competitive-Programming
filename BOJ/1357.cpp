
#include <bits/stdc++.h>
using namespace std;
string A,B;
void rev(string& x){
    reverse(x.begin(), x.end());
}
stringstream ss;
int main(){
    cin>>A>>B;
    rev(A); rev(B);
    ss<<atoi(A.c_str())+atoi(B.c_str());
    string C = ss.str();
    rev(C);
    cout<<atoi(C.c_str());
	return 0;
}
