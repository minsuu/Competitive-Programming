#include <bits/stdc++.h>
using namespace std;
int N;
int l[26], r[26];
char a,b,c;
void pre(int i){
    cout<<(char)(i+'A');
    if(l[i]) pre(l[i]);
    if(r[i]) pre(r[i]);
}
void in(int i){
    if(l[i]) in(l[i]);
    cout<<(char)(i+'A');
    if(r[i]) in(r[i]);
}
void post(int i){
    if(l[i]) post(l[i]);
    if(r[i]) post(r[i]);
    cout<<(char)(i+'A');
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        if(b!='.') l[a-'A']=b-'A';
        if(c!='.') r[a-'A']=c-'A';
    }
    pre(0); cout<<"\n";    
    in(0); cout<<"\n";    
    post(0); cout<<"\n";    
	return 0;
}
