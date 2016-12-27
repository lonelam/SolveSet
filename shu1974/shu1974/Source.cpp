#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn];
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0;
		int ansp = 0;
		for (int i = 0; i <= 1000; i++)
		{
			int buyer = a + n - lower_bound(a, a + n, i) ;
			buyer = min(k, buyer);
			if (buyer * i > ans)
			{
				ans = buyer * i;
				ansp = i;
			}
		}
		cout << ansp << " " << ans << endl;
	}
}