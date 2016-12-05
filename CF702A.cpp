#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 100010;
int n;
int a[MAXN];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int len = 1,ans = 1;
		scanf("%d",a);
		for(int i = 1;i<n;i++)
		{
			scanf("%d",a + i);
			if(a[i] > a[i-1])
			{
				len++;
			}
			else
			{
				ans = max(len,ans);
				len = 1;
			}
		}
		ans = max(len,ans);
		printf("%d\n",ans);
	}
	
} 
