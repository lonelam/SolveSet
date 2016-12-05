#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define PB(X) push_back(X)
vector<int> G[100010];
int vis[100010];
void init(int n) {
	for (int i = 1; i <= n; i++)
		vis[i] = -1;
}
void bfs(int u, int v)
{
	queue<int>q;
	q.push(u);
	vis[u] = -2;
	while (q.front() != v) {
		int S = q.front();
		q.pop();
		for (int i = 0; i < G[S].size(); i++) {
			int x = G[S][i];
			if (vis[x] != -1)
				continue;
			vis[x] = S;
			q.push(x);
		}
	}
}
void output(int a, int b)
{
	if (a == b)
	{
		cout << a << endl;
		return;
	}
	vector<int> v;
	while (vis[b] != a) {
		v.push_back(b);
		b = vis[b];
	}
	v.push_back(b);
	cout << a;
	for (int i = v.size() - 1; i >= 0; i--)
		cout << " " << v[i];
	cout << endl;
}

int main(void)
{
	int i, t, n, q, u, v;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (i = 0; i <= n; i++) {
			G[i].clear();
		}
		for (i = 1; i <= n - 1; i++) {
			cin >> u >> v;
			G[u].PB(v);
			G[v].PB(u);
		}
		for (i = 1; i <= q; i++) {
			cin >> u >> v;
			init(n);
			bfs(u, v);
			output(u, v);
		}
	}
	return 0;
}
