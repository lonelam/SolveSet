#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
#include <cstring>
using namespace std;
const int maxn = 1000 + 10;
int pos[maxn][maxn];
typedef unsigned long long ull;
ull F[maxn * maxn * 8];
ull pow_m(ull a, ull b, ull moder)
{
	ull ans = 1;
	ull cur = a;
	while(b)
	{
		if (b & 1ULL)
		{
			ans = (ans * (cur)) % moder;
		}
		b >>= 1;
		//cout << ans << endl;
		cur = (cur * cur) % moder;
	}
	return ans;
}

int main()
{
	int T;
	while(scanf("%d", &T)!=EOF)
	{
		while(T--)
		{
			memset(pos, -1, sizeof(pos));
			ull a, b, n;
			scanf("%llu%llu%llu", &a,&b,&n);
			ull f = 1, pref = 0;
			ull moder = 0;
			ull init = 0;
			for (int i = 0; i < n * n; i++)
			{
			//	cout << "dbg";
				if (pos[pref][f] != -1)
				{
					moder = i - pos[pref][f];
					init = i;
					break;
				}
				pos[pref][f] = i;
				F[i] = pref;
				pref = (pref + f) % n;
				swap(f, pref);
			}
			for (int i = init; i< 2 * moder; i++)
			{
				F[i] = pref;
				pref = (pref + f) % n;
				swap(f, pref);
			}
		//	cout << moder <<" "<<pow_m(a % moder, b , moder) << endl;
			printf("%llu\n", F[pow_m(a % moder, b, moder) + moder]);
		}
	}
}
/*



3
1 1 2
2 3 1000
18446744073709551615 18446744073709551615 1000



*/
