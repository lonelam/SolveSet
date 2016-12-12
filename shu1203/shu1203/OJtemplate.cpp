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
	int a, b;
	while (cin >> a >> b && a  && b)
	{
		a %= b;
		a *= 100;
		vector<int> res;
		for (int i = 0; i < 100; i++)
		{
			if ((a + i) % b == 0)
			{
				res.push_back(i);
			}
		}
		cout.fill('0');
		cout.width(2);
		cout << res[0];
		for (int i = 1; i < res.size(); i++)
		{
			cout << " " << res[i];
		}
		cout << endl;
	}

	return 0;
}