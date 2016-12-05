#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

ll md = 100000007;
struct matr
{
	ll a[2][2];
	matr()
	{
		memset(a, 0, sizeof(a));
	}
	matr operator*(const matr & rhs)
	{
		matr ans;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int x = 0; x < 2; x++)
				{
					ans.a[i][j] += this->a[i][x] * rhs.a[x][j];
				}
				ans.a[i][j] %= md;
			}
		}
		return ans;
	}
};

matr m_power(const matr & base, ll ind)
{
	if (ind == 1)
	{
		return base;
	}
	matr ans;
	ans = m_power(base, ind >> 1);
	ans = ans * ans;
	if (ind & 1)
	{
		return ans * base;
	}
	return ans;
}

int main()
{
	ll n;
	matr xb;
	xb.a[0][1] = xb.a[1][1] = 1;
	xb.a[1][0] = 8;
	while (cin >> n)
	{
		matr ans = m_power(xb, n);
		cout << ans.a[0][1] << endl;
	}
}