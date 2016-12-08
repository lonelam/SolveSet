#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxm = 10;
const int maxs = 1 << maxm;
const int maxn = 101;
vector<int> states;
string G[maxn];
int dp[maxs][maxs][2];
int m;
void init()
{
	states.clear();
	int ms = 1 << m;
	for (int s = 0; s < ms; s++)
	{
		bool valid = true;
		for (int i = 0; i < m; i++)
		{
			if ((s & (1 << i)) && ((s & (1 << (i + 1))) || (s & (1 << (i + 2)))))
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			states.push_back(s);
		}
	}
	//cout << states.size() << endl;
	return;
}
int main()
{
	int n;
	while (cin >> n >> m)
	{
		init();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			cin >> G[i];
		}
		int flip = 0;
		for (int i = 0; i < n; i++)
		{
			flip ^= 1;
			for (int j = 0; j < states.size(); j++)
			{
				int s = states[j];
				bool valid = true;
				
				int cnt = 0;
				for (int k = 0; k < m; k++)
				{
					if ((s & (1 << k)))
					{
						if (G[i][k] == 'H')
						{
							valid = false;
							break;
						}
						cnt++;
					}
				}
				if (!valid)
				{
					for (int l = 0; l < states.size(); l++)
					{
						dp[j][l][flip] = 0;
					}
					continue;
				}

				for (int up = 0; up < states.size(); up++)
				{
					int pres = states[up];
					dp[j][up][flip] = 0;
					for (int up2 = 0; up2 < states.size(); up2++)
					{
						int ppres = states[up2];
						valid = true;
						for (int k = 0; k < m; k++)
						{
							if ((s & (1 << k)) && ((pres & (1 << k) || (ppres & (1 << k)))))
							{
								valid = false;
								break;
							}
						}
						if (valid)
						{
							dp[j][up][flip] = max(dp[j][up][flip], dp[up][up2][flip ^ 1] + cnt);
						}
					}
				}
			}
			
		}
		int ans = 0;
		for (int i = 0; i < states.size(); i++)
		{
			for (int j = 0; j < states.size(); j++)
			{
				ans = max(ans, dp[i][j][flip]);
			}
		}
		cout << ans << endl;
	}
}
