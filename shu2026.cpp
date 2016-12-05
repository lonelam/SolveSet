#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll m, n, k;
	ll t;
	while(cin >> t)
	{
		while(t--)
		{
			cin >> n >> m >> k;
			if (k > n + m - 2)
			{
				cout << -1<<endl;
			}
			else if (k > max(n, m) - 1)
			{
				cout << max(m / (k - n + 2), n / (k - m + 2)) << endl;
			}
			else
			{
				cout << max(n / (k + 1) * m, m / (k + 1) * n) << endl;
			}
		}
	}
}
