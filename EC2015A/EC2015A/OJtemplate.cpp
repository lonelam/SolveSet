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
int main()
{
	int t;
	int kase = 1;
	ll N, m;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> N;
			ll l = 0, r = 3e9;
			while (l + 1 < r)
			{
				const ll mid = l + (r - l) / 2;
				if ((mid + 1) * mid / 2 > N)
				{
					r = mid;
				}
				else
				{
					l = mid;
				}
			}
			cout << "Case #" << kase++ << ": "<<(l * (l + 1) / 2) << endl;
		}
	}

	return 0;
}