#include <iostream>
#include <set>
#include <cstring>
using namespace std;

bool ok[21][21][21];
int X, Y, Z;
void dfs(int x, int y, int z)
{
	if (ok[x][y][z])
		return;
	ok[x][y][z] = true;
	if (z > 0)
	{
		if (x + z <= X)
		{
			dfs(x + z, y, 0);
		}
		else
		{
			dfs(X, y, z - (X - x));
		}
		if (y + z <= Y)
		{
			dfs(x, y + z, 0);
		}
		else
		{
			dfs(x, Y, z - (Y - y));
		}
	}
	if (x > 0)
	{ 
		if (x + z <= Z)
		{
			dfs(0, y, x + z);
		}
		else
		{
			dfs(x - (Z - z), y, Z);
		}
		if (y + x <= Y)
		{
			dfs(0, y + x, z);
		}
		else
		{
			dfs(x - (Y - y), Y, z );
		}
	}
	if (y > 0)
	{
		if (y + z <= Z)
		{
			dfs(x, 0, y + z);
		}
		else
			dfs(x, y - (Z - z), Z);
		if (y + x <= X)
		{
			dfs(x + y, 0, z);
		}
		else
			dfs(X, y - (X - x), z);
	}
}

int main()
{
	while (cin >> X >> Y >> Z)
	{
		memset(ok, 0, sizeof(ok));
		dfs(0, 0, Z);
		set<int> ans;
		for (int i = 0; i <= Y; i++)
		{
			for (int j = 0; j <= Z; j++)
			{
				if (ok[0][i][j])
					ans.insert(j);
			}
		}
		int cnt = 0;
		for (int x : ans)
		{
			cout << x << (++cnt != ans.size() ? ' ' : '\n');
		}
	}
}