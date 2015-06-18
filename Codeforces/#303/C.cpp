#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
const int MAXL = 1987654321;
deque<int> D;
int N, lr, ll, X[MAXN], H[MAXN];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",&X[i],&H[i]);
		D.push_back( i );
	}
	int ans = 0;
	lr = MAXL, ll = -MAXL;
	while(!D.empty()){
		while(!D.empty() && ll < X[D.front()] - H[D.front()]){
			ans++; ll = X[D.front()]; D.pop_front();
		}
		while(!D.empty() && X[D.back()] + H[D.back()] < lr){
			ans++; lr = X[D.back()]; D.pop_back();
		}
		if(!D.empty()) ll = X[D.front()], lr = X[D.back()];
		// two sides CANNOT be cut outside
		if(!D.empty() && X[D.front()] + H[D.front()] < ( D.size() == 1 ? lr : X[D.front()+1] ) ){
			ans++; ll = X[D.front()] + H[D.front()];
		}
		if(!D.empty() && X[D.back()] - H[D.back()] > ( D.size() == 1 ? ll : X[D.back()-1] ) ){
			ans++; lr = X[D.back()] - H[D.back()];
		}
		if(!D.empty()) D.pop_front();
		if(!D.empty()) D.pop_back();
	}
	printf("%d",ans);
	return 0;
}