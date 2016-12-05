#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
const int maxnode = 100010;
const int maxn = 1010;
struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode], row[maxnode], col[maxnode];
	int H[maxn], S[maxn];
	int ansd, ans[maxn];
	void init(int n_, int m_)
	{
		n = n_;
		m = m_;
		for (int i = 0; i <= m; i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0;
		L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
		{
			H[i] = -1;
		}

	}
	void link(int r, int c)
	{
		S[col[++size] = c]++;
		row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if (H[r] < 0)
		{
			H[r] = L[size] = R[size] = size;
		}
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
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
		{
			for (int j = R[i]; j != i; j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[col[j]];
			}
		}
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
		{
			for (int j = L[i]; j != i; j = L[j])
			{
				++S[col[U[D[j]] = D[U[j]] = j]];
			}
		}
		L[R[c]] = R[L[c]] = c;
	}
	bool dance(int d)
	{
		if (R[0] == 0)
		{
			ansd = d;
			return true;
		}
		int c = R[0];
		for (int i = R[0]; i != 0; i = R[i])
		{
			if (S[i] < S[c])
			{
				c = i;
			}
		}
		remove(c);
		for (int i = D[c]; i != c; i = D[i])
		{
			ans[d] = row[i];
			for (int j = R[i]; j != i; j = R[j])
			{
				remove(col[j]);
			}
			if (dance(d + 1))
			{
				return true;
			}
			for (int j = L[i]; j != i; j = L[j])
			{
				resume(col[j]);
			}
		}
		resume(c);
		return false;
	}
};

DLX g;
int a[1005];
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		g.init(n, m);
		for (int i = 1; i <= n; i++)
		{
			int num, j;
			scanf("%d", &num);
			for (int k = 0; k < num; k++)
			{
				scanf("%d", a + k);
			}
			for (int k = num - 1; k >= 0; k--)
			{
				g.link(i, a[k]);
			}
		}
		if (!g.dance(0))
		{
			printf("NO\n");
		}
		else
		{
			printf("%d", g.ansd);
			for (int i = 0; i < g.ansd; i++)
			{
				printf(" %d", g.ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}