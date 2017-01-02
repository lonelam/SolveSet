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
const int maxn = 50000 + 100;

int height[maxn];
int Maxer[maxn * 4];
int Miner[maxn * 4];
int n;
void pushup(int rt)
{
    Maxer[rt] = max(Maxer[rt << 1], Maxer[rt << 1 | 1]);
    Miner[rt] = min(Miner[rt << 1], Miner[rt << 1 | 1]);
}
void build(int l = 0, int r = n, int rt = 1)
{
//    cout << rt<<" "<< l<<"  "<<r << endl;
    //system("read");
    if (l >= r)
    {
        return;
    }
    if (l + 1 == r)
    {
        Maxer[rt] = Miner[rt] = height[l];
        return;
    }
    const int mid = l + (r - l) / 2;
    build(l, mid, rt << 1);
    build(mid, r, rt << 1 | 1);
    pushup(rt);
}
void query(int L, int R, int & ansmax, int & ansmin, int l = 0, int r = n, int rt = 1)
{
//    cout << rt << endl;
    //system("read");
    if (l >= r)
    {
        return;
    }

    if (L <= l && r <= R)
    {
        ansmax = max(ansmax, Maxer[rt]);
        ansmin = min(ansmin, Miner[rt]);
        return;
    }
    if (l + 1 == r)
    {
        return;
    }
    const int mid = l + (r - l) / 2;
    if (L <= mid)
    {
        query(L, R, ansmax,ansmin, l, mid, rt << 1);
    }
    if (mid < R)
    {
        query(L, R, ansmax, ansmin, mid, r, rt << 1 | 1);
    }
}

int main()
{
    int q;
    while(scanf("%d%d",&n,&q) !=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", height + i);
        }
        build();
        for (int i = 0;i < q; i++)
        {
            int A, B;
            scanf("%d%d",&A,&B);
            int amax = 0;
            int amin = inf;
            query(A - 1,B,amax,amin);
            printf("%d\n",amax - amin);
        }
    }
}
