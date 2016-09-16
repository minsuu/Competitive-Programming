#include <bits/stdc++.h>
using namespace std;
string o[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
string O,B;
int main(){
    cin>>O;
    for(char c : O){
        B += o[c-'0']; 
    }
    reverse(B.begin(), B.end());
    while(B.size()>1 && B.back()=='0') B.pop_back();
    reverse(B.begin(), B.end());
    cout<<B;
	return 0;
}
