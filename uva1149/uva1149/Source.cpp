#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 100000 + 20;
int ls[maxn];

int main()
{
	int bl, n;
	int t;
	while(cin >> t)

	while(t--)
	{
		cin >> n >> bl;
		for (int i = 0; i < n; i++)
		{
			cin >> ls[i];
		}
		sort(ls, ls + n);
		int l = 0, r = n - 1;
		int ans = 0;
		while (l < r)
		{
			if (ls[l] + ls[r] <= bl)
			{
				l++;
				r--;
			}
			else
			{
				r--;
			}
			ans++;
		}
		if (l == r)
		{
			ans++;
		}
		cout << ans << endl ;
		if (t != 0)
		{
			cout << endl;
		}
	}
}
