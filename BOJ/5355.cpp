#include <bits/stdc++.h>
using namespace std;
double N;
int T;
string s;
int main(){
    getline(cin, s);
    stringstream(s)>>T;
    while(T--){
        getline(cin, s);
        stringstream ss(s);
        ss>>N;
        while(ss>>s){
            if(s[0]=='@') N*=3.0;
            if(s[0]=='%') N+=5.0;
            if(s[0]=='#') N-=7.0;
        }
        printf("%.2f\n",N);
    }
	return 0;
}
