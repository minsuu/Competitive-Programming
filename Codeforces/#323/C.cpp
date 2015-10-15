// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int N,a;
map<int,int> nums;

int gcd(int a,int b)
{
    if(a && b)
        while(a%=b^=a^=b^=a);
    return a+b;
}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N*N; i++){
		scanf("%d",&a);
		nums[a]++;
	}
	vector<int> ans;
	for(int i=0; i<N; i++){
		int nw = nums.rbegin()->first;
		nums.rbegin()->second--;
		if( nums.rbegin()->second == 0 ) nums.erase( --nums.end() );

		for( auto it : ans ){
			int g = gcd( it, nw );
			nums[g]-=2;
			if( nums[g] == 0 ) nums.erase( g );
		}
		ans.push_back( nw ); 
	}

	for(auto it : ans) printf("%d ",it);
	return 0;
} 