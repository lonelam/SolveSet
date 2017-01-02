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

const int maxn = 1000000 + 100;
const int maxb = 10000 + 5;
int tmp[maxn];
int discreter[maxn];
int ql[maxn],qr[maxn];
int n, dn, bsize, bnum;
int belong[maxn];
bool lazy[maxb];
int p[maxn];
int P[maxb], L[maxb], R[maxb];

void sort_tmp()
{
    for (int i = 0; i < n;i++)
    {
        tmp[i * 2] = ql[i];
        tmp[i * 2 + 1] = qr[i];
    }
    sort(tmp, tmp + 2 * n);
}
void discrete()
{
    dn = 0;
    int cnter = unique(tmp, tmp + 2 * n) - tmp;
    discreter[dn++] = tmp[0];
    for (int i = 1; i < cnter; i++)
    {
        if (tmp[i] > tmp[i - 1] + 1) discreter[dn++] = tmp[i - 1] + 1;
        discreter[dn++] = tmp[i];
    }
}
void build()
{
    //discreter.clear();

    sort_tmp();
    discrete();
//    cout << "debug:  "<< dn << endl;
    bsize = sqrt((double)dn);
    bnum = dn / bsize;
    if (dn % bsize) bnum++;
    for (int i = 0; i < bnum; i++)
    {
        lazy[i] = false;
        P[i] = -1;
        L[i] = i * bsize;
        R[i] = (i + 1) * bsize;
    }
    R[bnum - 1] = dn;
    for (int i = 0; i < dn; i++)
    {
        p[i] = -1;
        belong[i] = i / bsize;
    }
}
void push_down(int pos)
{
    for (int i = L[pos]; i < R[pos]; i++)
    {
        p[i] = P[pos];
    }
    lazy[pos] = false;
}
void update(int from, int to, int no)
{
    if (lazy[belong[from]])
    {
        push_down(belong[from]);
    }
    if (belong[from] == belong[to])
    {
        for (int i = from; i <= to; i++)
        {
            p[i] = no;
        }
        return;
    }
    if (lazy[belong[to]])
    {
        push_down(belong[to]);
    }
    for (int i = from; i < R[belong[from]]; i++)
    {
        p[i] = no;
    }
    for (int i = belong[from] + 1; i < belong[to]; i++)
    {
        P[i] = no;
        lazy[i] = true;
    }
    for (int i = L[belong[to]]; i <= to; i++)
    {
        p[i] = no;
    }
}

int solve()
{
    build();

//    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int QL = lower_bound(discreter, discreter + dn, ql[i]) - discreter;
        //if (QL == dn) return -1;
        int QR = lower_bound(discreter, discreter + dn, qr[i]) - discreter;
    //    cout << i <<"  " << QL << "  " << QR << endl;
        //if (QR == dn) return -1;
        update(QL, QR, i);
    }
    set<int> cnt;
    cnt.insert(-1);
    for (int i = 0; i < bnum; i++)
    {
        if (lazy[i])
        {
            cnt.insert(P[i]);
        }
        else
        {
            for (int j = L[i]; j < R[i]; j++)
            {
                cnt.insert(p[j]);
            }
        }
    }
    return cnt.size() - 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", ql + i, qr + i);
        }

        printf("%d\n", solve());
    }
}
