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
	string line;
	while (cin >> line)
	{
		ll sum = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == 'u')
			{
				sum -= (1LL << (ll)(line.length() - 1 - i));
			}
			else if (line[i] == '1')
			{
				sum += (1LL << (ll)(line.length() - 1 - i));
			}
		}
		cout << sum << endl;
	}
	return 0;
}