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
typedef long long ll;
const int maxn = 100000 + 560;
ll V[maxn];
int main()

{
	int kase = 1;
	int T;
	ll N, G, P;
	while (cin >> T)
	{
		while (T--)
		{
			cin >> N >> G >> P;
			ll sum = 0;
			ll mx = 0;
			ll ans = 0;
			ll Pmx = 0;
			ll downneg = 0;
			for (int i = 0; i < N; i++)
			{
				cin >> V[i];
				sum += V[i];
				mx = max(mx, sum);
				if (i < P % N)
				{
					Pmx = mx;
				}
			}
			if (sum >= 0)
			{
				ans = (P / N) * sum + max({ Pmx, mx - sum });
			}
			else
			{
				if (P < N)
				{
					ans = Pmx;
				}
				else
				{
					ans = mx;
				}
			}
			cout << "Case #" << kase++ << ": " << max((ll)0, G - ans) << endl;
		}
	}
	return 0;
}