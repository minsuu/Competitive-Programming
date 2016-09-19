#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
	cin>>s;
    int n = s.size();
    bool pal = true;
    for(int i=0;i<n;i++){
        if(s[i] != s[n-i-1]){
            pal = false;
            break;
        }
    }
    cout<<(int)pal;
	return 0;
}
