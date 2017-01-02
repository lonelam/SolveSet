#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 8000 + 100;
const int maxb = 100;
int bsize, bnum;
int belong[maxn], cl[maxn];
int lazy[maxb], L[maxb], R[maxb];

void build()
{
    bsize = sqrt(maxn);
    bnum = maxn / bsize;
    if (maxn % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        L[i] = i * bsize;
        R[i] = (i + 1) * bsize;
        lazy[i] = -1;
    }
    for (int i = 0; i < maxn;i++)
    {
        belong[i]= i / bsize;
        cl[i] =  -1;
    }
}
void pushdown(int bno)
{
    if (lazy[bno] == -1)
    {
        return ;
    }
    for (int i = L[bno]; i < R[bno]; i++)
    {
        cl[i] = lazy[bno];
    }
    lazy[bno] = -1;
}
void update(int from, int to, int C)
{
    pushdown(belong[from]);
    if (belong[from] == belong[to])
    {
        for (int i = from; i <=to; i++)
        {
            cl[i] = C;
        }
        return;
    }
    pushdown(belong[to]);
    for (int i = from; i < R[belong[from]]; i++)
    {
        cl[i] = C;
    }
    for (int i = belong[from] + 1; i < belong[to]; i++)
    {
        lazy[i] = C;
    }
    for (int i = L[belong[to]]; i <= to; i++)
    {
        cl[i] = C;
    }
}

void sumup()
{
    map<int, int> cnt;
    int precl = -1;
    for (int i = 0; i < bnum; i++)
    {
        if (lazy[i] != -1)
        {
            if (lazy[i] != precl)
            {
                cnt[lazy[i]]++;
                precl = lazy[i];
            }
        }
        else
        {
            for (int j = L[i]; j < R[i]; j++)
            {
                if (cl[j] != precl)
                {
                    if (cl[j] != -1)
                    cnt[cl[j]]++;
                    precl = cl[j];
                }
            }
        }
    }
    for (map<int,int>::iterator i = cnt.begin(); i != cnt.end(); i++)
    {
        printf("%d %d\n", i->first, i->second);
    }

    printf("\n");
}
int main()
{
    int n;
    while(scanf("%d", &n)!= EOF)
    {
        build();
        int x1,x2,c;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&x1,&x2,&c);
            update(x1,x2 - 1,c);
        }
        sumup();
    }
}
