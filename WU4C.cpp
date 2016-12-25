#pragma comment(linker, "/STACK:1024000000,1024000000")
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn = 1000000 + 500;
typedef long long ll;
ll sz;
ll bit[maxn];
ll a[maxn];
ll presum[maxn];
void init()
{
	memset(bit, 0, sizeof(bit));
}


void add(ll xx)
{
	if (xx < 0)
	{
		return;
	}
	xx++;
	while (xx <= sz)
	{
		bit[xx] ++;
		xx += xx & (-xx);
	}
}

ll query(ll xx)
{
	xx++;
	ll res = 0;
	while (xx > 0)
	{
		res += bit[xx];
		xx -= xx & (-xx);
	}
	return res;
}

int main()
{
	int T;
	int n;
	ios::sync_with_stdio(false);
	while (cin >> T)
	{
		while (T--)
		{
			ll K;
			cin >> n >> K;
			const ll mbit = 1 << 18;
			K = min(K, mbit);
			sz = mbit + 10;
			init();
			presum[0] = 0;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
				presum[i] = a[i] ^ presum[i - 1];
			}
			ll ans = 0;
			add(0);
			for (int i = 1; i <= n; i++)
			{
				ll curbit = mbit;
				ll fixer = 0;
				while (curbit)
				{
					if (K & curbit)
					{
						if (presum[i] & curbit)
						{
							ans += query(fixer + (curbit << 1) - 1) - query(fixer + curbit - 1);
						}
						else
						{
							ans += query(fixer + curbit - 1) - query(fixer - 1);
							fixer += curbit;
						}
					}
					else
					{
						fixer += curbit & presum[i];
					}
					curbit >>= 1;
				}
				add(presum[i]);
			}
			cout << ans << endl;
		}
	}
}

/*

1
1 2
1



*/
