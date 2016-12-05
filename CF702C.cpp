#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100004;
const int maxx = 1000000000;
int citi[maxn];
int towr[maxn];
int rang[maxn];
int main()
{
	int n, m;
	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 0;i<n;i++)
		{
			scanf("%d",citi + i);
		}
		for(int i = 0;i < m;i++)
		{
			scanf("%d",towr + i);
		}
		sort(towr,towr+m);
		sort(citi,citi+ n);
		for(int i = 1;i < m;i++)
		{
			const int diff = towr[i] - towr[i - 1];
			const int sum = towr[i] + towr[i - 1];
			if(diff & 1)
			{
				if(sum > 0)
				{
					rang[i - 1] = sum / 2;
				}
				else
				{
					rang[i - 1] = (sum - 1) / 2;
				}
			}
			else
			{
				rang[i - 1] = sum/2;
			}
			
		}
		int ans = 0;
		rang[m - 1] = maxx;
		for(int i = 0;i < n;i++)
		{
			const int citix = citi[i];
			const int * lrbd = lower_bound(rang,rang+m,citix);
			const int towrpos = lrbd - rang;
		//	printf("for city[%d] = %d,towerpos = %d, rang = %d, ans = %d\n",i,citix,towrpos,*lrbd,ans);
			ans = max(abs(towr[towrpos] - citix),ans);
		}
		printf("%d\n",ans);
		
	}
}
