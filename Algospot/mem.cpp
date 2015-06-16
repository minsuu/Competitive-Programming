#include <cstdio>
int main(){
	int N=200000, z=-1;
	printf("1\n%d\n",N);
	for(int i=0;i<N;i++){
		printf("%d %d %d\n",i,z*i,i);
		z*=-1;
	}
	return 0;
}