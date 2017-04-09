#include<cstdio>
const int maxn = 100000 + 10;
int pa[maxn];
int rnk[maxn];
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
    if(rnk[a] > rnk[b])
    {
        pa[b] = a;
    }
    else
    {
        if(rnk[a] == rnk[b])
            rnk[b] ++;
        pa[a] = b;
    }
}
void initps(int n)
{
    for(int i = 0; i <= n; i++)
    {
        pa[i] = i;
        rnk[i] = 0;
    }
}

