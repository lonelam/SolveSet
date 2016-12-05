#include<cstdio>
const int maxn = 100000 + 10;
int pa[maxn];
int rank[maxn];
int findset(int x)
{
    return pa[x]!=x ? pa[x] = findset(pa[x]) : x;
}
void uni(int a, int b)
{
    if((a = findset(a)) == (b = findset(b)))
    {
        return;
    }
    if(rank[a] > rank[b])
    {
        pa[b] = a;
    }
    else
    {
        if(rank[a] == rank[b])
            rank[b] ++;
        pa[a] = b;
    }
}
void initps(int n)
{
    for(int i = 0; i <= n; i++)
    {
        pa[i] = i;
        rank[i] = 0;
    }
}
