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

int main()
{
	int T;
	while(scanf("%d", &T)!=EOF)
	{
		while(T--)
		{
			memset(pos, -1, sizeof(pos));
			ull a, b, n;
			scanf("%llu%ullu%ullu", &a,&b,&n);
			ull f = 1, pref = 0;
			ull moder = 0;
			for (int i = 0; i < n * n; i++)
			{
				if (pos[pref][f] != -1)
				{
					moder = i - pos[pref][f];
					break;
				}
				pos[pref][f] = i;
				pref = pref + f;
				swap(f, pref);
			}
			
		}
	}
}
