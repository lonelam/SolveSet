#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
bool isprime(ll x)
{
	for (ll  i = 2; i*i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;

		}
	}
	return true;
}
int main()
{
	ll n;
	while(cin >> n)
	{
		if (n == 0)
		{
			cout << 0 << endl;
		}
		else if (n == 2 ||isprime(n))
		{
			cout << 1 << endl;
		}
		else if (n % 2 == 1)
		{
			if (isprime(n - 2))
			{
				cout << 2 << endl;
			}
			else cout << 3 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
}