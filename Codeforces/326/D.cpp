#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int MAX = 50005;
vector<int> edges[MAX];
int from[MAX], to[MAX], color[MAX], cost[MAX];
bool cmp(int x, int y)
{
	return (color[x] < color[y]);
}
vector<pair<int, int> > bads;
vector<int> adj[8 * MAX], tmp[8 * MAX];
int n, m, sz;
void init()
{
	for (int i = 0; i < 8 * MAX; i++)
		adj[i].clear();
	for (int i = 0; i < (int)bads.size(); i++)
	{
		int id1 = bads[i].first, id2 = bads[i].second;
		adj[2 * id1].push_back(2 * id2 + 1);
		adj[2 * id2].push_back(2 * id1 + 1);
	}
	sz = m;
	for (int v = 0; v < n; v++)
		if (!edges[v].empty())
		{
			int last = edges[v][0];
			for (int i = 1; i < (int)edges[v].size(); i++)
			{
				int id = edges[v][i];
				adj[2 * last + 1].push_back(2 * id);
				adj[2 * id + 1].push_back(2 * last);
				adj[2 * id + 1].push_back(2 * sz + 1);
				adj[2 * sz].push_back(2 * id);
				adj[2 * last + 1].push_back(2 * sz + 1);
				adj[2 * sz].push_back(2 * last);
				last = sz++;
			}
		}
}
vector<int> tp;
bool mark[8 * MAX];
void dfs(int v)
{
	mark[v] = true;
	for (int i = 0; i < (int)adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
			dfs(u);
	}
	tp.push_back(v);
}
int cc[8 * MAX];
void sfd(int v, int col)
{
	mark[v] = true;
	cc[v] = col;
	for (int i = 0; i < (int)adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
			sfd(u, col);
	}
}
vector<int> ans;
bool check(int lim)
{
	init();
	sz *= 2;
	for (int i = 0; i < m; i++)
		if (cost[i] > lim)
			adj[2 * i + 1].push_back(2 * i);
	memset(mark, false, sizeof(mark));
	tp.clear();
	for (int i = 0; i < sz; i++)
		if (!mark[i])
			dfs(i);
	reverse(tp.begin(), tp.end());
	for (int i = 0; i < sz; i++)
		tmp[i].clear();
	for (int v = 0; v < sz; v++)
		for (int i = 0; i < (int)adj[v].size(); i++)
			tmp[adj[v][i]].push_back(v);
	for (int i = 0; i < sz; i++)
		adj[i] = tmp[i];
	int cnt = 0;
	memset(mark, false, sizeof(mark));
	for (int i = 0; i < (int)tp.size(); i++)
		if (!mark[tp[i]])
			sfd(tp[i], cnt++);
	ans.clear();
	for (int i = 0; i < sz / 2; i++)
	{
		if (cc[2 * i] == cc[2 * i + 1])
			return false;
		if (i < m && cc[2 * i] < cc[2 * i + 1])
			ans.push_back(i);
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> vals;
	vals.push_back(0);
	for (int i = 0; i < m; i++)
	{
		cin >> from[i] >> to[i] >> color[i] >> cost[i];
		vals.push_back(cost[i]);
		from[i]--;
		to[i]--;
		edges[from[i]].push_back(i);
		edges[to[i]].push_back(i);
	}
	for (int v = 0; v < n; v++)
	{
		sort(edges[v].begin(), edges[v].end(), cmp);
		int cnt = 0;
		for (int i = 0; i < (int)edges[v].size(); i++)
		{
			int j = i + 1;
			while (j < (int)edges[v].size() && color[edges[v][j - 1]] == color[edges[v][j]])
				j++;
			if (j - i > 2)
			{
				cout << "No\n";
				return 0;
			}
			if (j - i == 2)
			{
				cnt++;
				if (cnt == 2)
				{
					cout << "No\n";
					return 0;
				}
				bads.push_back(make_pair(edges[v][i], edges[v][i + 1]));
				i++;
			}
		}
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	int l = -1, r = (int)vals.size();
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(vals[mid]))
			r = mid;
		else
			l = mid;
	}
	if (r == (int)vals.size())
	{
		cout << "No\n";
		return 0;
	}
	check(vals[r]);
	cout << "Yes\n";
	cout << vals[r] << " " << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] + 1 << " ";
	cout << "\n";
	return 0;
}

