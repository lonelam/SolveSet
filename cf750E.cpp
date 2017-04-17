#include<iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 200000 + 100;
int sevennum[maxn];
int twos[maxn * 4];
int two
char line[maxn];
int sz;
inline int lsb(int x)
{
    return x & (-x);
}
int init(int n)
{
    memset(sevennum, 0, sizeof(sevennum));
    sz = n + 1;
}

int sum (int x, int C[])
{
    int ret = 0;
    while(x > 0)
    {
        ret += C[x];
        x -= lsb(x);
    }
    return ret;
}
void add(int x, int d, int C[])
{
    while(x <= sz)
    {
        C[x] += d;
        x += lsb(x);
    }
}

int main()
{
    int n, q;
    ios::sync_with_stdio(false);
    while(cin >> n >> q)
    {
        cin >> line;
    }
}
