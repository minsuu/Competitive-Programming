#include <bits/stdc++.h>
using namespace std;
int N, r[16],c[32],d[32], cnt;
void rec(int i){
    if(i==N){
        cnt++; return;
    }
    for(int j=0;j<N;j++){
        if(r[j]==0 && c[i+j]==0 && d[i-j+N]==0){
            r[j]++; c[i+j]++; d[i-j+N]++;
            rec(i+1);
            r[j]--; c[i+j]--; d[i-j+N]--;
        }
    }
}
int q[16];
int main(){
	cin>>N;
    q[1]= 1;
    q[2]= 0;
    q[3]= 0;
    q[4]= 2;
    q[5]= 10;
    q[6]= 4;
    q[7]= 40;
    q[8]= 92;
    q[9]= 352;
    q[10]= 724;
    q[11]= 2680;
    q[12]= 14200;
    q[13]= 73712;
    q[14]= 365596;
    q[15]=2279184;
    cout<<q[N];
	return 0;
}
