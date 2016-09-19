#include <bits/stdc++.h>
using namespace std;
double C[]={350.34, 230.90, 190.55, 125.30, 180.90};
int N,a;
int main(){
	cin>>N;
    for(int i=0;i<N;i++){
        double ans=0;
        for(int j=0;j<5;j++){
            cin>>a;
            ans+=C[j]*a;
        }
        printf("$%.2f\n",ans);
    }
	return 0;
}
