#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t, n;
	string line;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n >> line;
			long long cnt = 0;
			long long ans = 0;
			for (int i = 0; i < n; i++)
			{
				if (line[i] == '6')
				{
					cnt++;
				}
				else
				{
					ans += cnt * (cnt + 1) / 2;
					cnt = 0;
				}
			}
			ans += cnt * (cnt + 1) / 2;
			cnt = 0;
			cout << ans << endl;

		}
	}
}