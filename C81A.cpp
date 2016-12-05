#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1<< 17;
int n, dat[2*maxn - 1];

void init(int n_)
{
	n = 1;
	while( n < n_) 
	{
		n <<= 1;
	}
	const int mn = 2 * n - 1;
	for(int i = 0;i < mn; i++)
	{
		dat[i] = 0;
	}
}

void update(int k, int a)
{
	k += n - 1;
	dat[k] += a;
	while(k > 0)
	{
		k = (k - 1)/2;
		dat[k] = dat[(k << 1) + 1] + dat[(k << 1) + 2];
	}
}
int query(int a,int b, int k, int l, int r)
{
	if(r <= a || b <= l) return 0;
	if(a <= l && r <= b) return dat[k];
	else
	{
		return query(a, b, k * 2 + 1, l, (l + r)/ 2) + query(a, b, k * 2 + 2, (l + r)/ 2, r);
	}
}
int main()
{
	int t, kase = 1;
	char cmd[20];
	while(scanf("%d", & t)!=EOF)
	{
		while(t--)
		{
			int  m, x ,a ,b;
			scanf("%d", &m);
			init(m);
			for(int i = 1; i <= m; i++)
			{
				scanf("%d", &x);
				update(i, x);
			//	printf(" **%d ", query(i,i + 1,0,0 ,n));
			}
			printf("Case %d:\n",kase++);
			while(scanf("%s", cmd))
			{
				if(cmd[0] == 'E')
				{
					break;
				}
				scanf("%d%d",&a,&b);
				if(cmd[0] == 'A')
				{
					update(a,b);
					
				}
				else if(cmd[0] == 'S')
				{
					update(a,-b);
				}
				else if( cmd[0] == 'Q')
				{
					printf("%d\n", query(a, b + 1, 0, 0, n));
				}
			}
		}
	}
}
