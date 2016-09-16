#include <bits/stdc++.h>
using namespace std;
int N;
char B[66][66];
string rec(int i,int j,int n){
    if(n==1){
        string a; a.push_back(B[i][j]);
        return a;
    }
    string a = rec(i,j,n/2);
    string b = rec(i,j+n/2,n/2);
    string c = rec(i+n/2,j,n/2);
    string d = rec(i+n/2,j+n/2,n/2);
    if(a.size()==1 && a==b && b==c && c==d)
        return a;
    else{
        return "("+a+b+c+d+")";
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    cout<<rec(0,0,N);
	return 0;
}
