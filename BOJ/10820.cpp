#include <bits/stdc++.h>
using namespace std;
int A,B,C,D;
void add(char c){
    if('a'<=c && c<='z') A++;
    if('A'<=c && c<='Z') B++;
    if('0'<=c && c<='9') C++;
    if(' '==c) D++;
}
string s;
int main(){
	while(getline(cin,s)){
        A=B=C=D=0;
        for(char c:s) add(c);
        cout<<A<<" "<<B<<" "<<C<<" "<<D<<"\n";
    }
	return 0;
}
