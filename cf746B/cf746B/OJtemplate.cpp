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

	int n;
	string line;
	while (cin >> n)
	{
		cin >> line;
		deque<char> Q;
		if (n & 1)
		{
			bool flip = true;
			for (int i = 0; i < n; i++)
			{
				if (flip)
				{
					Q.push_back(line[i]);
				}
				else
				{
					Q.push_front(line[i]);
				}
				flip = !flip;
			}
		}
		else
		{
			bool flip = false;
			for (int i = 0; i < n; i++)
			{
				if (flip)
				{
					Q.push_back(line[i]);
				}
				else
				{
					Q.push_front(line[i]);
				}
				flip = !flip;
			}
		}
		for (int i = 0; i < Q.size(); i++)
		{
			cout << Q[i];
		}
		cout << endl;
	}
	return 0;
}