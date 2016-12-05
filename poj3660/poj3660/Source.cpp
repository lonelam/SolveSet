#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 105;
bool beat[maxn][maxn];
int n, m;
int main()
{
	int from, to;
	while (cin >> n >> m)
	{
		memset(beat, 0, sizeof(beat));
		for (int i = 0; i < m; i++)
		{
			cin >> from >> to;
			beat[from - 1][to - 1] = true;
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (beat[i][k] && beat[k][j])
					{
						beat[i][j] = true;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			for (int j = 0; j < n; j++)
			{
				if (beat[i][j])
				{
					tmp++;
				}
				if (beat[j][i])
				{
					tmp++;
				}
			}
			if (tmp == n - 1)
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
}