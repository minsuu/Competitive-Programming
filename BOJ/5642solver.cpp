#include <bits/stdc++.h>
using namespace std;

const int MC = 2e4;
const int MR = 25;

int B[MR][MC], nw;

int pi[100000];
void build_pi (int a, int b) // [a, b)
{
    int k = pi[0] = -1;
 
    for (int i = a; i < b; ++i)
    {
        for (; k >= 0 && B[nw][i] != B[nw][a+k]; k = pi[k]);

        pi[i - a + 1] = ++k;
    }
}

bool kmp_match (int s, int a, int b)
{
    build_pi(a,b);
    int cy = -1, st = 0;

    for (int i = s, k = 0; i < MC; ++i)
    {
        for (; k >= 0 && B[nw][i] != B[nw][a+k]; k = pi[k]);
 
        if (++k == b-a){
    		int nw = i - (b-a) + 1;
    		if( cy == -1 ){
    			cy = nw;
    		}else{
    			if( nw-cy == (b-a) ){
    				st++; cy = nw;
    				if( st >= 5 ) return true;
    			}else{
    				return false;
    			}
    		}
            k = pi[k];
        }
    }
    return false;
}

int main(){
	freopen("5642.out","r", stdin);

	for(int i=0; i<MR; i++){
		for(int j=0; j<MC; j++){
			scanf("%d",&B[i][j]);
		}
	}
/*
	for(int i=0; i<MR; i++){
		for(int j=MC-1; j>=1; j--){
			B[i][j] = B[i][j-1] - B[i][j];
		}
	}
*/
	
	nw = 24;
	for(int j=0; j<2; j++){
		for(int i=0; i<768; i++){
			printf("%d ", B[nw][10000+j*768+i] );
		}
		printf("\n");
	}

	printf("%d\n",kmp_match(10000, 10000, 10768) );

	for(int i=0; i<MR; i++){
		nw = i;
		for(int j=1; j<MC/2; j++){
			if( kmp_match(10000, 10000, 10000+j ) ){
				printf("%d : %d\n",i+1, j );
				break;
			}
		}
	}
	return 0;
}