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
					ans.a[i][j] +=  [&]() {return this->a[i][x] * rhs.a[x][j]; }();
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
	int t;
			int kase = 1;
	while (cin >> t)

	{

		while (t--)
		{
			ll n;
			cin >> n >> md;
			
				matr A;
				cout << "Case " << kase++ << ":\n";
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						cin >> A.a[i][j];
					}
				}
				A = m_power(A, n);
				for (int i = 0; i < 2; i++)
				{
					cout <<( A.a[i][0]+md) % md << ' ' <<( A.a[i][1]+md) %md<< endl;
				}
			
		}
	}
}