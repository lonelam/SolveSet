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
const int maxn = 200000 + 100;
bool vis[maxn];
char line[maxn];
int main()
{
	int n;
//	string line;
//	ios::sync_with_stdio(false);
	while (scanf("%d",&n)!=EOF)//cin >> n >> line)
	{
        scanf("%s",line);
        memset(vis,0,sizeof(vis));
		int Dnum = 0, Rnum = 0;
		int Ddenied = 0, Rdenied = 0;
		for (int i = 0; i < n; i++)
		{
			if (line[i] == 'D')
			{
				Dnum++;
			}
			else
			{
				Rnum++;
			}
		}
		int cur = 0;
		while (Dnum && Rnum)
		{
			if (!vis[cur])
			{
				if (line[cur] == 'D')
				{
					if (Ddenied)
					{
						vis[cur] = true;
						Ddenied--;
						Dnum--;
					}
					else
					{
						Rdenied++;
					}
				}
				else
				{
					if (Rdenied)
					{
						vis[cur] = true;
						Rdenied--;
						Rnum--;
					}
					else
					{
						Ddenied++;
					}
				}
			}
			cur = (cur + 1) % n;
		}
		if (Dnum)
		{
			printf("D\n");
		}
		else
		{
			printf("R\n");
		}
	}
	return 0;
}
