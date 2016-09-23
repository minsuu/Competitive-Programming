
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int N,a,b,c;
iii A,B;
string aa,bb,cc;
int main(){
	cin>>N>>cc>>c>>b>>a;
    A=B={a,{b,c}};
    aa=bb=cc;

    for(int i=1;i<N;i++){
        cin>>cc>>c>>b>>a;
        iii C={a,{b,c}};
        if(A<C){
            aa = cc;
            A=C;
        }
        if(B>C){
            bb = cc;
            B=C;
        }
    }
    cout<<aa<<"\n"<<bb;
	return 0;
}
