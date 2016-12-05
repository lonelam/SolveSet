#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 15 * 15 + 1;
const int maxm = 15 * 15 + 1;
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
							gg.link(pos, id[i + ki][j + kj]);
						}
					}
				}
			}
		}
		gg.dance(0);
		printf("%d\n", gg.ansd);
	}
}
