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
const int maxn = 200000 + 100;
typedef long long ll;
typedef long double ld;
char A[maxn];
char Ma[maxn * 2];
int Mp[maxn * 2];
ll len;
ll ans;
void Manachar()
{
	int l = 0;
	Ma[l++] = '.';
	Ma[l++] = ',';
	for (int i = 0; i < len; i++)
	{
		Ma[l++] = A[i];
		Ma[l++] = ',';
	}
	Ma[l] = 0;
	int pnow = 0;
	int pid = 0;
	for (int i = 1; i < l; i++)
	{
		if (pnow > i)
		{
			Mp[i] = min(Mp[2 * pid - i], pnow - i);
		}
		else
		{
			Mp[i] = 1;
		}
		for (; Ma[i - Mp[i]] == Ma[i + Mp[i]]; Mp[i]++);
		if (i + Mp[i] > pnow)
		{
			pnow = i + Mp[i];
			pid = i;
		}
	}
	for (int i = 1; i < l; i++)
	{
		if (Ma[i] == ',')
		{
			ans -= (Mp[i] - 1) / 2;
		}
		else
		{
			ans -= (Mp[i] - 1) / 2;
		}
	}
}
int main()
{
	while (~scanf("%s", A))
	{
	    len = strlen(A);
		ans = len * (len - 1) / 2 + 1;
		map<char, int> cnt;
		for (int i = 0; i < len; i++)
		{
			ans -= cnt[A[i]];
			cnt[A[i]]++;
		}
//		Manachar();
		printf("%lld\n", ans);
	}
}