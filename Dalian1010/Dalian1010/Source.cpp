#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int pool[1000];
char cpool[4000];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", pool + i);
		}
		int cnt = 0;
		memcpy(cpool, pool, sizeof(pool));
		int n4 = n * 4;
		for (int i = 0; i < n4; i++)
		{
			if (cpool[i] == 97)
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
