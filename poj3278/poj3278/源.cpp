#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxk = 100001;
int t[maxk];
const int inf = 0x3f3f3f3f;
int bfs(int x,int cow)
{
	memset(t, inf, sizeof(t));
	queue<int> cur,nex;
	cur.push(x);
	int tm = 0;
	while (!cur.empty())
	{
		while (!cur.empty())
		{
			x = cur.front();
			cur.pop();
			if (x == cow)
			{
				return tm;
			}
			if (x > 0 && t[x-1] == inf)
			{
				nex.push(x - 1);
				t[x - 1] = tm;
			}
			if (2 * x < maxk && t[2*x] ==inf)
			{
				nex.push(2 * x);
				t[2 * x] = tm;
			}
			if (x + 1 < maxk && t[x + 1] == inf)
			{
				nex.push(x + 1);
				t[x + 1] = tm;
			}
		}
		swap(cur, nex);
		tm++;
	}
}
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		cout << bfs(n, k) << endl;
	}
}