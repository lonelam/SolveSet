#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

typedef long long ll;
map<ll, ll> st;

int main()
{
	ll x;
	while (cin >> x && x)
	{
		ll n = 0;
		ll recurer = -1;
		st.clear();
		ll rem = 1;
		while (true)
		{
			rem *= 10;
			rem %= x;
			n++;
			if (rem == 0)
			{
				break;
			}
			if (st.find(rem) != st.end())
			{
				recurer = st[rem];
				break;
			}
			st[rem] = n;
		}
		if (recurer == -1)
		{
			cout << n << " 0\n";
		}
		else 
			cout << recurer - 1 << " " << n - recurer << endl;
	}
}

