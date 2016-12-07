#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200000 + 550;
int f[maxn];
int diff[maxn];
int elediff[maxn];
int bear[maxn];
int ele[maxn];
void getf(int n)
{
	f[0] = f[1] = 0;
	for (int i = 1; i < n; i++)
	{
		int j = f[i];
		while (j && diff[i] != diff[j]) j = f[j];
		f[i + 1] = diff[j] == diff[i] ? j + 1 : 0;
	}
}

int find(int n, int m)
{
	if (m == 0) return n + 1;
	int cnt = 0;
	getf(m);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j && elediff[i] != diff[j]) j = f[j];
		if (diff[j] == elediff[i]) j++;
		if (j == m)
		{
			cnt++;
			j = f[j];
		}
	}
	return cnt;
}


int main()
{
	int n, m;
	while (cin >> n >> m)
	{

		for (int i = 0; i < n; i++)
		{
			cin >> ele[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> bear[i];
		}
		for (int i = 1; i < n; i++)
		{
			elediff[i - 1] = ele[i] - ele[i - 1];
		}
		for (int i = 1; i < m; i++)
		{
			diff[i - 1] = bear[i] - bear[i - 1];
		}
		cout << find(n - 1, m - 1) << endl;

	}
}
