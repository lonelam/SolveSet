#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1<< 18;
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
		dat[i] = 0;//因为所有数都是正数，0可以 忽略。 
	}
}
void max_init()
{
	int k = n - 1; 
	while(k > 0)
	{
		for(int i = (k - 1)/2; i < k; i++)
		{
			dat[i] = max(dat[i* 2 + 1],dat[i * 2 + 2]);//共n - 1次 更新 
		}
		k = (k - 1)/2;
	}
}
void update(int k, int a)
{
	k += n - 1;
	dat[k] = a;
	while(k > 0)
	{
		k = (k - 1)/2;
		dat[k] = max(dat[(k << 1) + 1], dat[(k << 1) + 2]);
	}
}

int query(int a,int b, int k, int l, int r)
{
	if(r <= a || b <= l) return 0;
	if(a <= l && r <= b) return dat[k];
	else
	{
		return max(query(a, b, k * 2 + 1, l, (l + r)/ 2),query(a, b, k * 2 + 2, (l + r)/ 2, r));
	}
}

int main()
{
	int t, kase = 1;
	char cmd[20];
	int  nn, m, x ,a ,b;
	while(scanf("%d%d",&nn, &m)!=EOF)
	{
		init(nn);
		for(int i = 1; i <= nn; i++)
		{
			scanf("%d", dat + n + i - 1);
		//	update(i, x);//这里如果直接用这个会超时 
		//	printf(" **%d ", query(i,i + 1,0,0 ,n));
		}
		max_init();
		while(m--)
		{
			scanf("%s%d%d",cmd,&a,&b);
			if(cmd[0] == 'U')
			{
				update(a,b);
			}
			else if( cmd[0] == 'Q')
			{
				printf("%d\n", query(a, b + 1, 0, 0, n));
			}
		}
    }

}
