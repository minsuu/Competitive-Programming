#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 100005;

int rnk[MAX_N], sa[MAX_N];

inline int cmp(const int *x, const int &a, const int &b, const int &d, const int &N) {
	return x[a] == x[b] && x[(a + d) % N] == x[(b + d) % N];
}

void doubling(int *a, int N, int M) {
	static int sRank[MAX_N], tmpA[MAX_N], tmpB[MAX_N];
	int *x = tmpA, *y = tmpB;
	for (int i = 0; i < M; ++i) sRank[i] = 0;
	for (int i = 0; i < N; ++i) ++sRank[x[i]=a[i]];
	for (int i = 1; i < M; ++i) sRank[i] += sRank[i - 1];
	for (int i = N - 1; i >= 0; --i) sa[--sRank[x[i]]] = i;	
	for (int d = 1, p = 0; p < N; M = p, d <<= 1) {
		p = 0; 
		for (int i = 0; i < N; ++i) y[p++] = sa[i] >= d ? sa[i] - d : N + (sa[i] - d) % N;
		for (int i = 0; i < M; ++i) sRank[i] = 0;
		for (int i = 0; i < N; ++i) ++sRank[x[i]];
		for (int i = 1; i < M; ++i) sRank[i] += sRank[i - 1];
		for (int i = N - 1; i >= 0; --i) sa[--sRank[x[y[i]]]] = y[i];
		swap(x, y); x[sa[0]] = 0, p = 1;
		for (int i = 1; i < N; ++i) x[sa[i]] = cmp(y, sa[i], sa[i - 1], d, N) ? p - 1 : p ++;
	}
	for (int i = 0; i < N; ++i) {
		rnk[sa[i]] = i;
	}
}

int n, k;

char s[MAX_N];

int a[MAX_N];

int lj, sj;

char buf[MAX_N];

bool check(int bar) {
	for (int i = 0; i < lj; ++i) {
		int cur = i;
		int round = 0;
		for (int j = 0; j < k; ++j) {
			if (rnk[cur] <= rnk[bar]) {
				cur += lj;
			} else {
				cur += sj;
			}
			if (cur >= n) {
				++round;
				cur -= n;
			}
		}
		if (round > 1 || (round == 1 && cur >= i)) {
			return true;
		}
	}
	return false;
}

int main() {
	while (scanf("%d%d", &n, &k) == 2) {
		scanf("%s", s);
		if (k == n) {
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				ans = max(ans, s[i] - '0');
			}
			printf("%d\n", ans);
		} else {
			for (int i = 0; i < n; ++i) {
				a[i] = s[i] - '0';
			}
			doubling(a, n, 10);
			lj = (n + k - 1) / k, sj = lj - 1;
			int l = 0, r = n - 1;
			while (l < r) {
				int m = l + r >> 1;
				if (check(sa[m])) {
					r = m;
				} else {
					l = m + 1;
				}
			}
			int ans = sa[l];
			for (int i = 0; i < lj; ++i) {
				buf[i] = a[(ans + i) % n] + '0';
			}
			buf[lj] = '\0';
			puts(buf);
		}
	}
	return 0;
}
