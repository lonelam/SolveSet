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
	typedef __int128 ll;
	typedef long double ld;
	ld eps = 1e-6;
	void Cir()
	int main()
	{
		ll x1, y1, x2, y2, x3, y3, x, y;
		int T;
		cin.tie(nullptr);
		ios::sync_with_stdio(false);
		while (cin >> T)
		{
			while (T--)
			{
				ld cx, cy;
				cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
				Cir(x1, y1, x2, y2, x3, y3, cx, cy);
				//cout << cx <<" "<< cy << endl;
				ld r2
					= ((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1));
				ld r3 = ((cx - x) * (cx - x) + (cy - y) * (cy - y));
				//cout << r2 << " " << r3 << endl;
				if (r3 > r2 && abs(r2 - r3) > eps)
				{
					cout << "Accepted\n";
				}
				else
				{
					cout << "Rejected\n";
				}
			}
		}
	}