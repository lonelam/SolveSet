#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 1 << 18;
//int discrete[maxn];
int fp[maxn];
int num[maxn];
int RMQ[maxn * 2];
int N;
int a[maxn];

void Ninit(int n)
{
	N = 1;
	while (n > N)
	{
		N <<= 1;
	}
}

void rmq_init(int n)
{
	Ninit(n);
	memset(RMQ, -1, sizeof(RMQ));
	for (int i = 0; i < n; i++)
	{
		RMQ[i + N] = i;
	}
	for (int i = N - 1; i > 0; i--)
	{
		if (RMQ[i * 2] == -1)
		{
			RMQ[i] = RMQ[i * 2 + 1];
		}
		else if (RMQ[i * 2 + 1] == -1 || num[RMQ[i * 2]] >= num[RMQ[i * 2 + 1]])
		{
			RMQ[i] = RMQ[i * 2];
		}
		else
		{
			RMQ[i] = RMQ[i * 2 + 1];
		}
	}
}

int query(int ql, int qr, int o = 1, int l = 0, int r = N - 1)
{
	if (ql <= l && r <= qr)
	{
		return RMQ[o];
	}
	if (r < ql || qr < l)
	{
		return -1;
	}
	const int mid = l + (r - l) / 2;
	int dl = query(ql, qr, o * 2, l, mid);
	int dr = query(ql, qr, o * 2 + 1, mid + 1, r);
	if (dl == -1)
	{
		return dr;
	}
	if (dr == -1 || num[dl] > num[dr])
	{
		return dl;
	}
	return dr;
}

int main()
{
	int n, q;
	while (~scanf("%d", &n))
	{
		if (n == 0)
		{
			continue;
		}
		scanf("%d", &q);
//		cin >> q;
		int k = 0;
		memset(fp, 0, sizeof(fp));
		memset(num, 0, sizeof(num));
		num[k]++;
		scanf("%d", &a[1]);
		//cin >> a[1];
		//discrete[k] = a[1];
		fp[k] = 1;
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", &a[i]);
		//	cin >> a[i];
			if (a[i] != a[i - 1])
			{
				k++;
				//discrete[k] = a[i];
				fp[k] = i;
			}
			num[k]++;
		}
		k++;
		fp[k] = n;
		rmq_init(k);
		int from, to;
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &from, &to);
			//cin >> from >> to;
			int lb = upper_bound(fp, fp + k, from) - fp;
			int ub = upper_bound(fp, fp + k, to) - fp;
			int ans = 0;
			if (lb == ub)
			{
				ans = to - from + 1;
			}
			else if (ub - lb == 1)
			{
				ans = max(fp[lb] - from, to - fp[lb] + 1);
			}
			else
			{
				ans = max(fp[lb] - from, to - fp[ub - 1] + 1);
				ans = max(ans, num[query(lb, ub - 2)]);
			}
			printf("%d\n", ans);
		}
	}
}


/*

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10


5 2
1 1 2 2 5
1 5

2 5



*/