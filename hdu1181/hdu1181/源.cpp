#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 26;
const int tar = 'm' - 'a';
bool G[maxn][maxn];
bool used[maxn];
bool bfs()
{
	int cur;
	queue<int> q;
	q.push(1);
	memset(used, 0, sizeof(used));
	used[1] = true;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur == tar)
		{
			return true;
		}

		for (int i = 0; i < maxn; i++)
		{
			if (G[cur][i] && !used[i])
			{
				q.push(i);
				used[i] = true;
			}
		}
	}
	return false;
}
int main()
{
	string tmp;
	while (cin >> tmp)
	{
		if (tmp == "0")
		{
			if (bfs())
			{
				cout << "Yes.\n";
			}
			else
			{
				cout << "No.\n";
			}
			memset(G, 0, sizeof(G));
		}
		else
		{
			G[tmp.front()-'a'][tmp.back()-'a'] = true;
		}
	}
}
