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
bool cmp(const string & lhs, const string & rhs)
{
	if (lhs.length() != rhs.length())
	{
		return lhs.length() < rhs.length();
	}
	for (int i = 0; i < lhs.length(); i++)
	{
		if (lhs[i] != rhs[i])
		{
			return lhs[i] < rhs[i];
		}
	}
	return false;
}
string operator+(const string & lhs, const string & rhs)
{
	string ans(rhs.length(), '0');
	int rem = 0;
	for (int i = 0, li = lhs.size() - 1, ri = rhs.size() - 1; i < lhs.size(); li--, ri--, i++)
	{
		int tmp = lhs[li] - '0' + rhs[ri] - '0' + rem;
		rem = tmp / 10;
		ans[i] = tmp % 10 + '0';
	}
	if (lhs.size() != rhs.size())
	{
		int tmp = rhs[0] - '0' + rem;
		rem = tmp / 10;
		ans[lhs.size()] = tmp % 10 + '0';
	}
	if (rem)
	{
		ans.push_back(rem + '0');
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
string a, b;
string fib[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tot = 2;
	fib[0] = "1";
	fib[1] = "2";
	while (fib[tot - 1].size() < 200)
	{
		fib[tot] = fib[tot - 2] + fib[tot - 1];
		//cout << fib[tot] << endl;
		tot++;
	}
	//cout << fib[tot - 1].size() << endl;
	//cout << tot << endl;
	while (cin >> a >> b)
	{
		if (a == "0" && b == "0") break;
		int l = 0;
		while (cmp(fib[l], a))
		{
			l++;
		}
		int r = l;
		while (cmp(fib[r], b) || fib[r] == b)
		{
			r++;
		}
		cout << r - l << endl;
	}
}