#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100005;
int arr[maxn];
int main()
{
	int t, n, s;
	int cur;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", arr + i);
		}
		int cur = 0, from = 0, to = 0, ans = 999999;
		while (from < n)
		{
			while (cur < s && to < n)
			{
				cur += arr[to++];
			//	printf("**%d **", cur);
			}
			if (cur >= s)
			{
				ans = min(ans, to - from);
			}
			cur -= arr[from++];
		}
		if (ans == 999999)
			printf("0\n"); 
		else
			printf("%d\n", ans);
	}
}