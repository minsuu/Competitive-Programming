#include <bits/stdc++.h>
using namespace std;

int N;
double sc[1000], mx=0, s=0;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>sc[i];
        mx = max(mx, sc[i]); 
    }
    
    for(int i=0;i<N;i++){
        s += sc[i]/mx*100;
    }
    printf("%.2f",s/N);
    return 0;
}
