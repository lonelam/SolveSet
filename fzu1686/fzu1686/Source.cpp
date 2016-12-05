#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//const int MAXN = 5000000 + 5;
const int INF = 0x3f3f3f3f;
const int maxnode = 100000;
const int MaxM = 250;
const int MaxN = 250;
struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxN];
	int ansd, ans[MaxN];
	void init(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
			H[i] = -1;
		ansd = INF;
	}
	void Link(int r, int c)
	{
		++S[Col[++size] = c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)
	{
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	bool v[maxnode];
	int f()
	{
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c])v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
			if (v[c])
			{
				ret++;
				v[c] = false;
				for (int i = D[c]; i != c; i = D[i])
					for (int j = R[i]; j != i; j = R[j])
						v[Col[j]] = false;
			}
		return ret;

	}
	void Dance(int d)
	{
		if (d + f() >= ansd) return;
		if (R[0] == 0) {
			ansd = min(ansd, d);
			return;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
			if (S[i] < S[c])
				c = i;
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j])remove(j);
			Dance(d + 1);
			for (int j = L[i]; j != i; j = L[j])resume(j);
			resume(i);
		}
	}
};
DLX gg;

int a[55][55];
int id[16][16];
int main()
{
	int n, m, atkn, atkm;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int cnt = 0;
		memset(id, 0, sizeof(id));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", a[i] + j);
				if (a[i][j])
				{
					id[i][j] = ++cnt;
				}
			}
		}
		scanf("%d%d", &atkn, &atkm);
		const int nn = n - atkn + 1;
		const int mm = m - atkm + 1;
		if (atkn == 0 || atkm == 0)
		{
			continue;
		}
		gg.init(nn * mm + 5, cnt);
		int pos = 0;
		for (int i = 0; i < nn; i++)
		{
			for (int j = 0; j < mm; j++)
			{
				pos++;
				for (int ki = 0; ki < atkn; ki++)
				{
					for (int kj = 0; kj < atkm; kj++)
					{
						if (i +ki < n && j+ kj < m && id[i + ki][j + kj])
						{
							gg.Link(pos, id[i + ki][j + kj]);
						}
					}
				}
			}
		}
		gg.Dance(0);
		printf("%d\n", gg.ansd);
	}
}