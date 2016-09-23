#include <bits/stdc++.h>
using namespace std;
int N,a[1010],b[1010],c[1010];
int abs(int x){ return x>0?x:(-x); }

int per(){
    sort(a,a+N);
    int ret=0;
    do{
        int s=0;
        for(int i=1;i<N;i++)
            s+=abs(a[i]-a[i-1]);
        ret=max(ret,s);
        if(ret==s){
            for(int i=0;i<N;i++)
                c[i]=a[i];
        }
    }while(next_permutation(a,a+N));
    return ret;
}
int main(){
    /*N=7;
    for(;;){

    for(int i=0;i<N;i++)
        a[i]=rand()%100;
*/
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a,a+N);
    int A=0, B=0;
    for(int i=0;i<N;i++){
        if(N%2){
            A += (i==N/2 || i==N/2+1? 1:2) * (i<N/2? -1:1) * a[i];
            B += (i==N/2 || i==N/2-1? 1:2) * (i<N/2+1? -1:1) * a[i];
        }else{
            A += (i==N/2-1 || i==N/2? 1:2) * (i<N/2? -1:1) * a[i];
        }
    }
    int ans = max(A,B);
    
    cout<<ans;
    /*
    if(ans!=per()){
        cout<<"ERROR!";
        for(int i=0;i<N;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        for(int i=0;i<N;i++)
            cout<<b[i]<<" ";
        cout<<ans<<"but "<<per()<<"\n";
        for(int i=0;i<N;i++)
            cout<<c[i]<<" ";
        // break;
    }

    }
    */
	return 0;
}
