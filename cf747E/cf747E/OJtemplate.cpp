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
vector<string> layers[333335];
char line[1000000 + 1000];
int len;
int get_int(int & pos)
{
	int ans = 0;
	while (isdigit(line[pos]))
	{
		ans *= 10;
		ans += line[pos] - '0';
		pos++;
	}
	return ans;
}
void getlayer(int & cur, int depth, int num)
{
	while (num--)
	{
		string comm;
		for (; cur < len; cur++)
		{
			if (line[cur] != ',')
				comm.push_back(line[cur]);
			else
				break;
		}
		layers[depth].push_back(comm);
		cur++;
		int nex_num = get_int(cur);
		cur++;
		if (nex_num)
		{
			getlayer(cur, depth + 1, nex_num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> line)
	{
		len = strlen(line);
		int cur = 0;
		while (cur < len)
		{
			string comm;
			for (; cur < len; cur++)
			{
				if (line[cur] != ',')
				{
					comm.push_back(line[cur]);
				}
				else
					break;
			}
			layers[0].push_back(comm);
			cur++;
			int nex_num = get_int(cur);
			cur++;
			if (nex_num)
			{
				getlayer(cur, 1, nex_num);
			}
		}
		int alpha = 0;
		int mmcnt = 0;
		while (layers[mmcnt].size())
		{
			mmcnt++;
		}
		cout << mmcnt << endl;
		while (layers[alpha].size() != 0)
		{
			cout << layers[alpha][0];
			int nnlen = layers[alpha].size();
			for (int i = 1; i < nnlen; i++)
			{
				cout << " " << layers[alpha][i];
			}
			cout << endl;
			alpha++;
		}
	}
	return 0;
}