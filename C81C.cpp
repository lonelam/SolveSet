#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1<< 18;
int n, dat[2*maxn - 1];

void init(int n_,int w_)
{
	n = 1;
	while( n < n_) 
	{
		n <<= 1;
	}
	const int mn = 2 * n - 1;
	for(int i = 0;i < mn; i++)
	{
		dat[i] = w_;//所有格子都初始化为w宽度 
	}
}
void update(int k, int a)
{
	k += n - 1;
	dat[k] -= a;//更新的时候那一行的宽度变小了 
	while(k > 0)
	{
		k = (k - 1)/2;
		dat[k] = max(dat[(k << 1) + 1], dat[(k << 1) + 2]);//dat数组里面存着的是最大值 
	}
}
int query(int val, int a,int b, int k, int l, int r)
{
	if(r <= a || b <= l) return -1;
	if( k > n - 2)
	{
		if(dat[k] < val)
		{
			return -1;
		}
		return k - n + 2;//计算贴到了哪一格 
	}
	if(dat[k] < val)
	{
		return -1; 
	}
	const int lv = query(val, a, b, k * 2 + 1, l, (l + r)/ 2);
	if(lv != -1)//上面的格子优先贴 
	{
		return lv;
	}
	else
	{
		return query(val, a, b, k * 2 + 2, (l + r)/ 2, r);
	}
}
int main()
{
	int t, kase = 1;
	char cmd[20];
	int h, w, m, qw;
	while(scanf("%d%d%d", &h, &w, &m)!=EOF)
	{
		if(h > 200000)//h如果太大会超时，200000下面的格子不可能贴到，所以直接缩小到200000 
		{
			h = 200000;
		}
		init(h,w);
		for(int i = 0; i< m; i++)
		{
			scanf("%d",&qw);
			const int ans = query(qw, 0, h,0, 0, n);
			if(ans != -1)
			{
				update(ans - 1, qw);//如果可以贴就要更新 
			}
			printf("%d\n",ans);
		}
	}
}
