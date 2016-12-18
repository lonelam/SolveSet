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

int main()
{
	int n, k, a, b;
	while (cin >> n >> k >> a >> b)
	{
		if (a + b < n)
		{
			cout << "NO\n";
			continue;
		}
		int lef = n;
		char G = 'G';//a cups
		char B = 'B'; // b cups
		if (a > b)
		{
			swap(a, b);
			swap(G, B);
		}
		string ans;
		int las = 0;
		while (lef)
		{
			if (a > b)
			{
				swap(a, b);
				swap(G, B);
				las = 0;
			}
			else if (las >= k)
			{
				swap(a, b);
				swap(G, B);
				las = 0;
			}
			if (b == 0)
			{
				cout << "NO\n";
				return 0;
			}
			ans.push_back(B);
			b--;
			las++;
			lef--;
		}
		cout <<ans << endl;
	}

	return 0;
}

/*
8 6 100 78
*/