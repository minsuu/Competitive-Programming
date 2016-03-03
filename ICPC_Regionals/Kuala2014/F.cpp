#include <bits/stdc++.h>
using namespace std;
int T;
string buf, buf2, buf3;
const string vowel = "aeiou";

int syl( string str ){
	if( str.size() >= 6 ){
		if( str.size() == 6 &&
			( str.find( "ng" )!=string::npos
			|| str.find("ny")!=string::npos ) )
			return 2;
		else
			return 3;
	}else if( str.size() >= 4 ){
		return 2;
	}else{
		if( str.size() == 3 && vowel.find( str[0] ) != string::npos )
			return 2;
		return 1;
	}
	assert( 0 );
	return 0;
}

int main(){
	cin>>T; getline( cin, buf );
	for(int t=1; t<=T; t++){
		getline( cin, buf );
		istringstream iss( buf );
		int A,B,C,D,E, v;
		A = B = C = D = E = v = 0;
		
		int syls[10]; string las[10];
		while( getline( iss, buf2, ',' ) ){
			if( 4<=v ) D += 10;
			else{
				if( buf2.back() == '.' ) buf2.pop_back();
				for(int i=0; i<(int)buf2.size(); i++){
					if( 'A' <= buf2[i] && buf2[i] <= 'Z' ){
						buf2[i] -= 'A';
						buf2[i] += 'a';
					}
				}
				istringstream isw( buf2 );
				int tsy = 0;
				while( isw >> buf3 ){
					tsy += syl( buf3 );
				}
				if( 8 <= tsy && tsy <= 12 ){
					A += 10;
				}
				syls[v] = tsy;
				las[v] = string( buf3.end()-2, buf3.end() );
				if( 2<=v && las[v-2] == las[v] )
					B += 20;
				if( 2<=v && syls[v-2] == syls[v] )
					C += 10;
			}
			v++;
		}
		E = A+B+C-D;
		printf("Case #%d: %d %d %d %d %d\n",t,A,B,C,D,E);
	}
	return 0;
}
