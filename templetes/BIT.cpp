#include<cstdio>
using namespace std;
const int maxn = 10000;
int n;
int C[maxn];
int lsb(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret += C[x];
        x-=lsb(x);
    }
    return ret;
}
void add(int x, int d)
{
    while(x <= n)
    {
        C[x] += d;
        x += lsb(x);
    }
}
