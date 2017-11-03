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
#include <sstream>
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
int T;
struct mat
{
	ld a[4][4];
	mat() { memset(a, 0, sizeof(a)); }
	void init()
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 4; i++)
		{
			a[i][i] = 1;
		}
	}
	mat operator*(const mat & rhs) const
	{
		mat ret;
		for (int k = 0; k < 4; k++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					ret.a[i][j] += a[i][k] * rhs.a[k][j];
				}
			}
		}
		return ret;
	}
}base;
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> base.a[i][j];
			//scanf("%Lf", &base.a[i][j]);
		}
	}
	string buf;
	cin.get();
	getline(cin, buf);
	stringstream ss(buf);
	int tmp;
	vector<int> seq;
	while (ss >> tmp) seq.push_back(tmp);
	ld P = 1;
	for (int i = 1; i < seq.size(); i++)
	{
		P *= (base.a[seq[i - 1] - 1][seq[i] - 1]);
	}
	printf("%.8Lf\n", P);
	getline(cin, buf);
	stringstream ss2(buf);
	seq.clear();
	while (ss2 >> tmp) seq.push_back(tmp);
	P = 1;
	for (int i = 1; i < seq.size(); i++)
	{
		P *= (base.a[seq[i - 1] - 1][seq[i] - 1]);
	}
	printf("%.8Lf\n", P);
	ld ans = 0;
	P = 1;
	int ii;
	cin >> ii;
	ii--;
	for (ll i = 1; i < 100000; i++)
	{
		ans += P;
		P *= base.a[ii][ii];
	}
	printf("%.8Lf\n", ans);
	int jj;
	P = 1;
	ans = 0;
	cin >> jj; jj--;
	for (ll i = 1; i < 100000; i++)
	{
		ans += P ;
		P *= base.a[jj][jj];
	}
	printf("%.8Lf\n", ans);

	return 0;
}