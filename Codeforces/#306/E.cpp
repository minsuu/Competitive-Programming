#include <bits/stdc++.h>
using namespace std;
stack<int> st; int N,A[111111], ms, av;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		st.push(A[i]);
	}
	if( st.top() == 1 ) { printf("NO"); return 0; }
	if( N==1 ) { printf("YES\n0"); return 0; }
	st.pop(); // pop zero
	while( !st.empty() ){
		int b = st.top(); st.pop();
		if( b == 1 ) { av=1; break; } // 1
		if( st.empty() ) break;
		int a = st.top(); st.pop();
		if( a == 0 && b == 0 ){ // 00->1
			ms++; av=1; break;
		}
		ms++; st.push(0); // 10
	}
	if( av ){
		printf("YES\n");
		string ret;
		for(int i=0; i<N-ms-2; i++)
			ret += (A[i])? "1->" : "0->";
		for(int i=N-ms-2; i<N-2; i++)
			ret += (A[i])? "(1->" : "(0->";
		ret += (A[N-2]) ? "(1" : "(0";
		for(int i=0; i<ms+1; i++)
			ret += ")";
		ret += "->0";
		printf("%s", ret.c_str());
	}else{
		printf("NO");
	}
	return 0;
}