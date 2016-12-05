#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
ll fibo[10000];
int m;
void init()
{
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; fibo[i - 1] < 1e18; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	//	cout << fibo[i] << endl;
		m = i + 1;
	}
}
int main()
{
	init();
	ll n;
	while (cin >> n)
	{
		int ans = upper_bound(fibo, fibo + m, n) - fibo;
		if (ans >= 4)
		{
			ans -= 3;
		}
		else
		{
			ans = 1;
		}
		cout << ans << endl;
	}
}