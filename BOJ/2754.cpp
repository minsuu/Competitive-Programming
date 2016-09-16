#include <bits/stdc++.h>
using namespace std;
string s;
double d;
int main(){
    cin>>s;
    if(s!="F"){
        d = (4-(s[0]-'A'));
        if(s[1]=='+') d+=0.3;
        if(s[1]=='-') d-=0.3;
    }
    printf("%.1f",d);
	return 0;
}
