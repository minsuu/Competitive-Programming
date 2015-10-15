// Author: Damian Straszak

#include <cstring>
#include <cstdio>
#include <algorithm>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define FOR(i,v)for(int i=0;i<v;i++)
using namespace std;

#define MOD 1000000009
int d[4][4][28][28][28];
char s[3][1<<20];
int ns[3];
int dp[1<<20][4];

int check(int a0,int a1,int b0,int b1,int c1,int c2,int c3)
{
	if (a0>b0 || a1>b1) return 0;
	if (a0==0 && b0==1 && c1>=c2) return 0;
	if (a1==0 && b1==1 && c2>=c3) return 0;
	if (a0==0 && b0==0 && c1!=c2) return 0;
	if (a1==0 && b1==0 && c2!=c3) return 0;
	return 1;
}

int compatible(int p1,int p2,int p3,int c1,int c2,int c3)
{
	if (p1<27 && p1!=c1) return 0;
	if (p2<27 && p2!=c2) return 0;
	if (p3<27 && p3!=c3) return 0;
	if (c1==0 && p1!=0) return 0;
	if (c2==0 && p2!=0) return 0;
	if (c3==0 && p3!=0) return 0;
	return 1;
}

int main()
{
    FOR(p1,28)FOR(c1,27)
	{
		if (p1<27 && p1!=c1) continue;
		FOR(p2,28)FOR(p3,28)FOR(c2,27)FOR(c3,27) 
	    {
	    	if (!compatible(p1,p2,p3,c1,c2,c3)) continue;
	    	FOR(a0,2)FOR(a1,2)FOR(b0,2)FOR(b1,2) if (check(a0,a1,b0,b1,c1,c2,c3)) d[a0+2*a1][b0+2*b1][p1][p2][p3]++;
	    }
	}
	int te;
	scanf("%d",&te);
	while(te--)
	{
		int n=0;
		FOR(i,3)
		{
			scanf("%s",s[i]);
			ns[i]=strlen(s[i]);
			n=max(n,ns[i]);
		}
		FOR(i,3)FOR(j,n+1)
		{
			if (j<ns[i]) 
			{
				if (s[i][j]=='?') s[i][j]=27;
				else s[i][j]-='a'-1;
			}
			else s[i][j]=0;
		}
		dp[0][0]=1;
		REP(i,1,n)
		{
			FOR(b,4) dp[i][b]=0;
			FOR(a,4)FOR(b,4) dp[i][b]=(dp[i][b]+dp[i-1][a]*1LL*d[a][b][ s[0][i-1] ][ s[1][i-1] ][ s[2][i-1] ])%MOD;
		}
		printf("%d\n",dp[n][3]);
	}

	return 0;
}
