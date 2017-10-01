#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<functional>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxnode = 100010;
const int MaxN = 2010;

struct DLX
{
	int n, m, size;
	int U[maxnode], D[maxnode], R[maxnode], L[maxnode];
	int Row[maxnode], Col[maxnode];
	int H[MaxN], S[MaxN];
	int ansd, ans[MaxN];
	int K;
	void init(int _n, int _m)
	{
		n = _n;
		m = _m;
		for (int i = 0; i <= m; i++)
		{
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
			S[i] = 0;
		}
		R[m] = 0;
		L[0] = m;
		size = m;
		for (int i = 1; i <= n; i++)
		{
			H[i] = -1;
		}

	}
	void Link(int r, int c)
	{
		S[Col[++size] = c]++;
		Row[size] = r;
		U[size] = U[c];
		D[size] = c;
		D[U[c]] = size;
		U[c] = size;
		if (H[r] == -1)
		{
			H[r] = R[size] = L[size] = size;
		}
		else
		{
			R[size] = H[r];
			L[size] = L[H[r]];
			R[L[size]] = size;
			L[H[r]] = size;
		}
	}
	void remove(int c)
	{
		for (int i = D[c]; i != c; i = D[i])
		{
			L[R[i]] = L[i];
			R[L[i]] = R[i];
		}
	}
	void resume(int c)
	{
		for (int i = U[c]; i != c; i = U[i])
		{
			R[L[i]] = L[R[i]] = i;
		}
	}
	bool v[maxnode];
	int h()
	{
		int ret = 0;
		for (int c = R[0]; c != 0; c = R[c]) v[c] = true;
		for (int c = R[0]; c != 0; c = R[c])
		{
			if (v[c])
			{
				ret++;
				for (int i = D[c]; i != c; i = D[i])
				{
					for (int j = R[i]; j != i; j = R[j])
					{
						v[Col[j]] = false;
					}
				}
			}
		}
		return ret;
	}

int f()
{
int ret = 0;
for(int c = R[0]; c != 0;c = R[c])v[c] = true;
for(int c = R[0]; c != 0;c = R[c])
if(v[c])
{
ret++;
v[c] = false;
for(int i = D[c];i != c;i = D[i])
for(int j = R[i];j != i;j = R[j])
v[Col[j]] = false;
}
return ret;
}
  void Dance(int d)
{
if(d + f() >= min(ansd, 11))return;
if(R[0] == 0)
{
if(d < ansd)ansd = d;
return;
}
int c = R[0];
for(int i = R[0];i != 0;i = R[i])
if(S[i] < S[c])
c = i;
for(int i = D[c];i != c;i = D[i])
{
remove(i);
for(int j = R[i];j != i;j = R[j])remove(j);
Dance(d+1);
for(int j = L[i];j != i;j = L[j])resume(j);
resume(i);
}
}
};

DLX gg;



int main()
{
  int T;
  while(~scanf("%d", &T))
  {
    while(T--)
    {
      int n, m;
      scanf("%d%d", &n, &m);
      gg.init(n, m);
      for (int i = 1; i <= m; i++)
      {
        int u, v;
        scanf("%d%d", &u, &v);
        gg.Link(u, i);
        gg.Link(v, i);
      }
      gg.ansd = inf;
      gg.Dance(0);
      if (gg.ansd <= 10)
      printf("%d\n", gg.ansd);
      else printf("GG\n");
    }
  }
}
