// Oct 04 2015, minsu( github : https://github.com/minsuu/ )
#include <bits/stdc++.h>
using namespace std;
int x1,y1,x2,y2,x3,y3, h,w;
char brd[333][333];

bool chk(){
	if( x1 == x2 && x2 == x3 ){
		if( y1+y2+y3 == x1 ){
			for(int i=0; i<x1; i++){
				for(int j=0; j<y1; j++)
					brd[i][j] = 'A';
				for(int j=y1; j<y1+y2; j++)
					brd[i][j] = 'B';
				for(int j=y1+y2; j<x1; j++)
					brd[i][j] = 'C';
			}
			h = x1;
			return 1;
		}
	}
	if( x1+x2 == x3 ){
		if( y1 == y2 && y1 + y3 == x3 ){
			for(int i=0; i<x1; i++)
				for(int j=0; j<y1; j++)
					brd[i][j] = 'A';
			for(int i=x1; i<x3; i++)
				for(int j=0; j<y1; j++)
					brd[i][j] = 'B';
			for(int i=0; i<x3; i++)
				for(int j=y1; j<x3; j++)
					brd[i][j] = 'C';
			h = x3;
			return 1;
		}
	}
	if( x2 == x1+x3 ){
		if( y1 == y3 && y1 + y2 == x2 ){
			for(int i=0; i<x1; i++)
				for(int j=0; j<y1; j++)
					brd[i][j] = 'A';
			for(int i=0; i<x2; i++)
				for(int j=y1; j<x2; j++)
					brd[i][j] = 'B';
			for(int i=x1; i<x2; i++)
				for(int j=0; j<y1; j++)
					brd[i][j] = 'C';
			h = x2;
			return 1;
		}
	}	
	if( x1 == x2+x3 ){
		if( y2 == y3 && y1 + y3 == x1 ){
			for(int i=0; i<x1; i++)
				for(int j=0; j<y1; j++)
					brd[i][j] = 'A';
			for(int i=0; i<x2; i++)
				for(int j=y1; j<x1; j++)
					brd[i][j] = 'B';
			for(int i=x2; i<x1; i++)
				for(int j=y1; j<x1; j++)
					brd[i][j] = 'C';
			h = x1;
			return 1;
		}
	}
	return false;
}

int main(){
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	bool poss = false;
	for(int i=0; i<2 && !poss; i++){
		for(int j=0; j<2 && !poss; j++){
			for(int k=0; k<2 && !poss; k++){
				poss |= chk();
				swap( x3, y3 );
			}
			swap( x2, y2 );
		}
		swap( x1, y1 );
	}
	if( !poss ) printf("-1");
	else{
		printf("%d\n",h);
		for(int i=0; i<h; i++){
			for(int j=0; j<h; j++)
				printf("%c",brd[i][j]);
			printf("\n");
		}
	}
	return 0;
} 