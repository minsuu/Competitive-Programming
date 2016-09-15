#include <bits/stdc++.h>
using namespace std;
int N,a,b;
int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d%d",&a,&b);
    printf("Case #%d: %d + %d = %d\n",i,a,b,a+b);
  }
  return 0;
}
