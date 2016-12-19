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
char gs[] = "ATCG";
int main()
{
	int n;
	string code;
	while (cin >> n >> code)
	{
		if (n % 4 != 0)
		{
			cout << "===\n";
			return 0;
		}
		map<char, int> cnt;
		for (int i = 0; i < n; i++)
		{
			cnt[code[i]]++;
		}
		for (int k = 0; k < 4; k++)
		{
			if (cnt[gs[k]] > n / 4)
			{
				cout << "===\n";
				return 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (code[i] == '?')
			{
				for (int k = 0; k < 4; k++)
				{
					if (cnt[gs[k]] < n / 4)
					{
						code[i] = gs[k];
						cnt[gs[k]]++;
						break;
					}
				}
			}
		}
		cout << code << endl;
	}
	return 0;
}