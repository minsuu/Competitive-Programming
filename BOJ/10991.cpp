#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin>>N;    	
    for(int i=0;i<N;i++){
        string s;
        for(int j=1;j<N-i;j++){
            s.push_back(' '); 
        }
        for(int j=0;j<=i;j++){
            s += "* ";
        }
        s.pop_back();
        cout<<s<<"\n";
    }
	return 0;
}
