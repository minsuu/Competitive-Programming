#include <bits/stdc++.h>
using namespace std;
int T,N,M,S;
int but[22], msg[555];
char buf[1024], buf2[1024];
int main(){
	fgets( buf, 1024, stdin ); sscanf(buf, "%d",&T);

	while(T--){
		assert( fgets(buf, 1024, stdin ) != NULL ); assert( sscanf(buf, "%d%d",&N,&M) == 2 );
		int chk = 0;
		for(int i=0; i<N; i++){
			fgets(buf, 1024, stdin ); but[i] = 0;
			int l = strlen( buf );
			// if( buf.size() == 0 ) { i--; continue; }
			for( int c=0; c <l; c++ ){
				char it = buf[c];
				if( it == ' ' ) but[i] |= 1<<('z' - 'a' + 1);
				else if( it == '.' ) but[i] |= 1<<('z' - 'a' + 2);
				else if( 'a' <= it && it <= 'z' ) but[i] |= 1<<(it - 'a');
				
			}
		}
		assert( chk == 26 );

		assert( fgets(buf, 1024, stdin ) != NULL );

		assert( sscanf(buf, "%d",&S) == 1);

		for(int i=0; i<S; i++){
			fgets(buf, 1024, stdin ); msg[i] = 0;
			int l = strlen(buf);
			// if( buf.size() == 0 ) { i--; continue; }
			for( int c=0; c < l; c++ ){
				char it = buf[c];
				if( it == ' ' ) msg[i] |= 1<<('z' - 'a' + 1);
				else if( it == '.' ) msg[i] |= 1<<('z' - 'a' + 2);
				else if( 'a' <= it && it <= 'z' ) msg[i] |= 1<<(it - 'a');
			}
		}

		int maxi = 0, mini = 0;
		for(int i=0; i< (1<<N); i++){
			int able = 0, fixed = 0;
			for(int j=0; j<N; j++){
				if( i & (1<<j) ){
					fixed++;
					able |= but[j];
				}
			}
			if( fixed > M ) continue;
			int poss = 0;
			for(int j=0; j<S; j++)
				if( (msg[j] & able) == msg[j] )
					poss++;
			if( poss > maxi ) maxi = poss, mini = fixed;
			else if( poss == maxi ) mini = min(mini, fixed);
		}
		printf("%d %d\n",maxi,mini);
	}
	return 0;
}