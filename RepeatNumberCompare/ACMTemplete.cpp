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

class RepeatNumberCompare
{
public:
	RepeatNumberCompare() {}
	string compare(int x1, int k1, int x2, int k2)
	{
		int cnt1 = 0, cnt2 = 0;
		int xx1 = x1, xx2 = x2;
		int digit1[100], digit2[100];
		while (xx1)
		{
			digit1[cnt1] = xx1 % 10;
			cnt1++;
			xx1 /= 10;
		}
		while (xx2)
		{
			digit2[cnt2] = xx2 % 10;
			cnt2++;
			xx2 /= 10;
		}
		if (cnt1 * k1 > cnt2 * k2)
		{
			return "Greater";
		}
		else if(cnt1 * k1 < cnt2 * k2)
		{
			return "Less";
		}
		else
		{
			int p1 = cnt1, p2 = cnt2;
			if (!(p1 % p2) || !(p2 % p1))
			{
				return 
			}
			while (p1 && p2)
			{
				if (digit1[--p1] > digit2[--p2])
				{
					return "Greater";
				}
				else if (digit1[p1] < digit2[p2])
				{
					return "Less";
				}
			}
		}

	}
};