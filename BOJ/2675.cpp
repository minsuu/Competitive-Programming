#include <bits/stdc++.h>
using namespace std;
int T,R;
string s;
int main(){
    cin>>T;
    while(T--){
        cin>>R>>s;
        string a;
        for(char c:s){
            for(int i=0;i<R;i++)
                a.push_back(c);
        }
        cout<<a<<"\n";
    }
	return 0;
}
