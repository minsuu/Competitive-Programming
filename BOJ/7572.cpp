#include <bits/stdc++.h>
using namespace std;
// 2013 -- F9
int y;
int main(){
    cin>>y;
    int a = ((y-2013)%12+12+5)%12;
    int b = ((y-2013)%10+10+9)%10;
    printf("%c%c",'A'+a,'0'+b);
	return 0;
}
