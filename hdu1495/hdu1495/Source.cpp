#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxs = 105;
int mem[maxs][maxs][maxs];
struct state
{
	int s, m, n;
};
int s, m, n;
int bfs()
{
	queue<state> cur, nex;
	int cnt = 0;

	if (s & 1)
	{
		return -1;
	}

	int hs = s / 2;

	cur.push({ s, 0, 0 });

	while (!cur.empty())
	{
		while (!cur.empty())
		{
			state p = cur.front();
			cur.pop();
			if (mem[p.s][p.m][p.n] != -1)
			{
				continue;
			}
			mem[p.s][p.m][p.n] = cnt;
			if ((p.s == hs && p.n == 0) || (p.m == hs && p.n == hs))
			{
				return cnt;
			}
			if (p.s > 0)
			{
				if (p.m < m)
				{
					if(p.s > m - p.m)
					nex.push({ p.s - (m - p.m), m, p.n });
					else
					{
						nex.push({ 0, p.m + p.s, p.n });
					}
				}
				if (p.n < n)
				{
					if(p.s > n - p.n)
					nex.push({ p.s - n + p.n, p.m, n });
					else
					{
						nex.push({ 0, p.m, p.s + p.n });
					}
				}
			}
			if (p.m > 0)
			{
				nex.push({ p.s + p.m, 0, p.n });
				if (p.n < n)
				{
					if (p.m > n - p.n)
					{
						nex.push({ p.s, p.m - n + p.n, n });
					}
					else if (p.m <= n - p.n)
					{
						nex.push({ p.s, 0, p.m + p.n });
					}
				}
			}
			if (p.n > 0)
			{
				nex.push({ p.s + p.n, p.m, 0 });
				if (p.m < m)
				{
					if (p.n < m - p.m)
					{
						nex.push({ p.s, p.m + p.n, 0 });
					}
					else
					{
						nex.push({ p.s, m, p.n - m + p.m });
					}
				}
			}
		}
		cnt++;
		swap(nex, cur);
	}
	return -1;
}

int main()
{
	while (cin >> s >> m >> n)
	{
		if (s == 0)
		{
			return 0;
		}
		memset(mem, -1, sizeof(mem));
		if (m < n)
		{
			swap(m, n);
		}
		int ans = bfs();
		if (ans == -1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << ans << endl;
		}
	}
}