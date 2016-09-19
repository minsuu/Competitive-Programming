#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
    scanf("%d:%d:%d",&a,&b,&c);
    scanf("%d:%d:%d",&d,&e,&f);
    d-=a; e-=b; f-=c;
    if(f<0) {e--; f+=60;}
    if(e<0) {d--; e+=60;}
    if(d<0) {d+=24;}
    printf("%02d:%02d:%02d",d,e,f);
	return 0;
}
