#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;
ld ans[maxn];
ld xs[maxn];
ld ys[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	ld r, R;
	int k;
	while (cin >> T)
	{
		for (int kase = 1; kase <= T; kase++)
		{
			cin >> r >> R >> k;
			if (R < r) swap(R, r);
			ld a = (R + r) / 2;
			ld b = sqrt(R) * sqrt(r);
			ld c = sqrt(a * a - b * b);
			ans[0] = R - r;
			ys[0] = 0;
			xs[0] = -a;
			for (int i = 1; i <= k; i++)
			{
				ld low = -a, up = a;
				while (low + 1e-9 < up)
				{
					const ld midx = low + (up - low) / 2;
					const ld midy = sqrt(R * r - 4.0 * midx * midx / (R + r) * R / (R + r) * r);
					const ld Rleft = sqrt((midx - xs[i - 1]) * (midx - xs[i - 1]) + (midy - ys[i - 1]) * (midy - ys[i - 1])) - ans[i - 1];
					const ld Rright = sqrt((midx - c) * (midx - c) + midy * midy) - r;
					if (midx <= xs[i - 1] || Rleft <= 0)
					{
						low = midx;
					}
					else if (Rleft > Rright)
					{
						up = midx;
					}
					else
					{
						low = midx;
					}
				}
				const ld ty = sqrt(R * r - 4.0 * low * low  * R / (R + r) * r/ (R + r));
				xs[i] = low;
				ys[i] = ty;
				ans[i] = sqrt((low - c) * (low - c) + ty * ty) - r;
			}
			cout.setf(ios::fixed);
			cout.precision(4);
			cout << "Case #" << kase << ":" << endl;
			cout << ans[k] << endl;
		}
	}
}