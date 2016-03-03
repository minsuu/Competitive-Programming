<<<<<<< HEAD
#include <cstdio>
using namespace std;
typedef long long lld;

lld a = 64;
int main(){
	for(int i=0; i<18; i++) a *= 10;
	printf("%lld",a);
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int N, a[2020], d[5050];
lld e[10100];
int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++) scanf("%d",&a[i]);
	sort( a, a+N );
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
			d[ a[j] - a[i] ]++;
	for(int i=0; i<5050; i++)
		for(int j=0; j<5050; j++)
			e[ i+j ] += d[i] * 1LL * d[j];
	for(int i=1; i<10100; i++)
		e[i] += e[i-1];
	
	lld c = 0;
	for(int i=0; i<5050; i++)
		c += e[i-1] * d[i];
	double ans = c;
	for(int i=0; i<3; i++)
		ans /= N * 1.0 * (N-1) / 2;
	printf("%.10f", ans );
	return 0;
}
>>>>>>> c8f566a5cabfc5d90e412ff036b08b05e06ed89e
