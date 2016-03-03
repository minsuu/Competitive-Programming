#include <cstdio>
using namespace std;
typedef long long lld;

lld a = 64;
int main(){
	for(int i=0; i<18; i++) a *= 10;
	printf("%lld",a);
	return 0;
}
