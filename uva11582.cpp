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
ull F[maxn][maxn * 8];
int moder[maxn];
void init(int n)
{
	memset(pos, -1, sizeof(pos));
	ull f = 1, pref = 0;
	moder[n] = 0;
	for (int i = 0; i < n * n; i++)
	{
	//	cout << "dbg";
		if (pos[pref][f] != -1)
		{
			moder[n] = i - pos[pref][f];
			break;
		}
		pos[pref][f] = i;
		F[n][i] = pref;
		pref = (pref + f) % n;
		swap(f, pref);
	}

}
ull pow_m(ull a, ull b, ull moderr)
{
	ull ans = 1;
	ull cur = a;
	while(b)
	{
		if (b & 1ULL)
		{
			ans = (ans * (cur)) % moderr;
		}
		b >>= 1;
		//cout << ans << endl;
		cur = (cur * cur) % moderr;
	}
	return ans;
}

int main()
{
	for (int i = 2; i <= 1000; i ++)
	{
		init(i);
	}
	int T;
	while(scanf("%d", &T)!=EOF)
	{
		while(T--)
		{
			ull a, b, n;
			scanf("%llu%llu%llu", &a,&b,&n);
			if (n == 1ULL)
			{
				printf("0\n");
				continue;
			}
		//	cout << moder <<" "<<pow_m(a % moder, b , moder) << endl;
			printf("%llu\n", F[n][pow_m(a % moder[n], b, moder[n])]);
		}
	}
}
/*



3
1 1 2
2 3 1000
18446744073709551615 18446744073709551615 1000



*/
