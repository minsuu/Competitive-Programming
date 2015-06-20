#include <cstdio>
#include <memory.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double pt;

pt op[500][500];
pt ep[500][500];
pt id[500][500];

int deg[500];
int trap[500];
int edge[500][500];

vector<int> traps;

pt A[128][128];
pt R[128][128];
pt tmp[128][128];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	k -= 2;
	for(int i = 0; i < n; i++) {
		scanf("%d",&trap[i]);
		if (trap[i]) traps.push_back(i);
	}
	for(int i = 0; i < m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		edge[a][b]++;
		edge[b][a]++;
		deg[a]++;
		deg[b]++;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			op[i][j] = (pt)edge[i][j] / (pt)deg[i];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (i == j) {
				ep[i][j] = 1;
			} else {
				if (trap[i] == 0) {
					ep[i][j] = -(pt)edge[i][j] / (pt)deg[i];
				} else {
					ep[i][j] = 0;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		id[i][i] = 1;
	}
	for(int i = 0; i < n; i++) {
		if (fabs(ep[i][i]) < 1e-9) {
			pt maxValue = 0;
			int maxInd = -1;
			for(int j = i+1; j < n; j++) {
				auto cur = fabs(ep[j][i]);
				if (maxValue < cur) {
					maxValue = cur;
					maxInd = j;
				}
			}
			if (maxInd >= 0) {
				int j = maxInd;
				for(int k = 0; k < n; k++) {
					ep[i][k] += ep[j][k];
				}
				for(int k = 0; k < n; k++) {
					id[i][k] += id[j][k];
				}
			}
		}
		pt div = 1.0/ep[i][i];
		for(int j = 0; j < n; j++) {
			ep[i][j] *= div;
		}
		for(int j = 0; j < n; j++) {
			id[i][j] *= div;
		}
		for(int j = 0; j < n; j++) {
			if (j == i) continue;
			pt mult = ep[j][i];
			for(int k = 0; k < n; k++) {
				ep[j][k] -= ep[i][k]*mult;
			}
			for(int k = 0; k < n; k++) {
				id[j][k] -= id[i][k]*mult;
			}
		}
	}
	int t = traps.size();
	for(int i = 0; i < t; i++) {
		for(int j = 0; j < t; j++) {
			pt acc = 0;
			for(int k = 0; k < n; k++) {
				acc += op[traps[i]][k]*id[k][traps[j]];
			}
			printf("%d -> %d : %Lf\n",traps[i],traps[j],acc);
			A[i][j] = acc;
		}
	}
	for(int i = 0; i < t; i++) {
		R[i][i] = 1;
	}
	while(k>0) {
		if (k&1) {
			for(int i = 0; i < t; i++) {
				for(int j = 0; j < t; j++) {
					pt s = 0;
					for(int k = 0; k < t; k++) {
						s += A[i][k] * R[k][j];
					}
					tmp[i][j] = s;
				}
			}
			memcpy(R, tmp,sizeof(tmp));
		}
		for(int i = 0; i < t; i++) {
			for(int j = 0; j < t; j++) {
				pt s = 0;
				for(int k = 0; k < t; k++) {
					s += A[i][k] * A[k][j];
				}
				tmp[i][j] = s;
			}
		}
		memcpy(A, tmp,sizeof(tmp));
		k >>= 1;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%Lf ",R[i][j]);
		printf("\n");
	}
	double ans = 0;
	for(int i = 0; i < t; i++) {
		ans += id[0][traps[i]] * R[i][t-1];
	}
	printf("%.10f\n",ans);
	return 0;
}