#include <bits/stdc++.h>
using namespace std;
char board[222][222];
int N, M;
int main(){
	srand (time(NULL));
	while( scanf("%s",board[N++]) != EOF );
	for(int i=0;i<N;i++) printf("%s\n",board[i]);
	return 0;
}