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
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int pow_(int p, int k)
{
	if (k == 1)
	{
		return p;
	}
	int hf = pow_(p, k / 2);
	if (k & 1)
	{
		return hf * hf * p;
	}
	else
	{
		return hf * hf;
	}
}
int main()
{
	int c, s;
	while (cin >> c >> s && c && s)
	{
		int sum = 0;
		for (int i = 0; i < s; i++)
		{
			sum += pow_(c, gcd(s, i));
		}
		if (s & 1)
		{
			sum += s * pow_(c, (s + 1) / 2);
			sum /= 2 * s;
		}
		else
		{
			sum += s / 2 * pow_(c, s / 2);
			sum += s / 2 * pow_(c, s / 2 + 1);
			sum /= s * 2;
		}
		cout << sum  << endl;
	}

	return 0;
}