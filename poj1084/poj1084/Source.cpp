#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 5 * 6 * 2 + 1;
const int maxm = 100 + 1;
const int maxnode = maxn * maxm + 10;
const int inf = 0x3f3f3f3f;

struct DLX
{
	int U[maxnode], D[maxnode], L[maxnode], R[maxnode];
	int S[maxm], H[maxn];
	int row[maxnode], col[maxnode];
	int ansd, n, m, sz;
	void init(int n_, int m_)
	{
		ansd = inf;
		n = n_;
		m = m_;
		sz = m;
		for (int i = 0; i <= m; i++)
		{
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
			S[i] = 0;
		}
		L[0] = m;
		R[m] = 0;
		for (int i = 1; i <= n; i++)
		{
			H[i] = -1;
		}
	}
	void link(int r, int c)
	{
		sz++;
		row[sz] = r;
		col[sz] = c;
		S[c]++;
		if (H[r] == -1)
		{
			H[r] = L[sz] = R[sz] = sz;
		}
		else
		{
			L[sz] = L[H[r]];
			R[sz] = H[r];
			L[R[sz]] = R[L[sz]] = sz;

		}
		U[sz] = U[c];
		D[sz] = c;
		U[c] = sz;
		D[U[sz]] = sz;
	}
	void remove(int c)
	{
		//L[R[c]] = L[c];
		//R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
		{
			L[R[i]] = L[i];
			R[L[i]] = R[i];
		}
	}
	void resume(int c)
	{
		//	L[R[c]] = R[L[c]] = c;
		for (int i = U[c]; i != c; i = U[i])
		{
			L[R[i]] = R[L[i]] = i;
		}
	}
	void bonus(int r)
	{
		if (H[r] == -1)
		{
			return;
		}
		for (int i = R[H[r]]; i != H[r]; i = R[i])
		{
			remove(i);
		}
		remove(H[r]);
	}
	void recover(int r)
	{
		if (H[r] == -1)
		{
			return;
		}
		resume(H[r]);
		for (int i = L[H[r]]; i != H[r]; i = L[i])
		{
			resume(i);
		}
	}
	bool vis[maxnode];
	int h()
	{
		int ret = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = R[0]; i != 0; i = R[i])
		{
			if (!vis[i])
			{
				ret++;
				vis[i] = true;
				for (int j = D[i]; j != i; j = D[j])
				{
					for (int k = R[j]; k != j; k = R[k])
					{
						vis[col[k]] = true;
					}
				}
			}
		}
		return ret;
	}

	void dance(int d)
	{
		if (d + h() >= ansd)
		{
			return;
		}
		if (R[0] == 0)
		{
			ansd = min(ansd, d);
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
		{
			if (S[i] < S[c])
			{
				c = i;
			}
		}
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j])
			{
				remove(j);
			}
			dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])
			{
				resume(j);
			}
			resume(i);
		}
		return;
	}
};
DLX gg[6];
int sq_n[7];
int mis[1000];
int main()
{
	int t;
	int n, k;
	sq_n[0] = 0;
	for (int i = 1; i < 6; i++)
	{
		sq_n[i] = sq_n[i - 1] + i * i;
	}

	for (n = 1; n < 6; n++)
	{
		
		gg[n].init(2 * (n + 1) * n, sq_n[n]);
		for (int a = 1; a <= n; a++)
		{
			const int ind0 = sq_n[n - a] + 1;
			for (int x = 0; x <= n - a; x++)
			{
				for (int y = 0; y <= n - a; y++)
				{
					const int xyno = x * (n - a + 1) + y + ind0;
					for (int i = 0; i < a; i++)
					{
						gg[n].link((2 * n + 1) * y + x + i + 1, xyno);
						gg[n].link((2 * n + 1) * (y + a) + x + i + 1, xyno);
						gg[n].link(n + (2 * n + 1) * (y + i) + x + 1, xyno);
						gg[n].link(n + (2 * n + 1) * (y + i) + x + a + 1, xyno);
					}
				}
			}
		}
	}
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d%d", &n, &k);

			for (int i = 0; i < k; i++)
			{
				scanf("%d", mis + i);
				gg[n].bonus(mis[i]);
			}
			gg[n].dance(0);
			printf("%d\n", gg[n].ansd);
			for (int i = k - 1; i >= 0; i--)
			{
				gg[n].recover(mis[i]);
			}
		}
	}
}