#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int sa[maxn], cntA[maxn], ch[maxn], rank[maxn], cntB[maxn], tsa[maxn],
void solve()
{
    for (int i = 0; i < 256; i ++) cntA[i] = 0;
    for (int i = 1; i <= n; i ++) cntA[ch[i]] ++;
    for (int i = 1; i < 256; i ++) cntA[i] += cntA[i - 1];
    for (int i = n; i; i --) sa[cntA[ch[i]] --] = i;
    rank[sa[1]] = 1;
    for (int i = 2; i <= n; i ++)
    {
        rank[sa[i]] = rank[sa[i - 1]];
        if (ch[sa[i]] != ch[sa[i - 1]]) rank[sa[i]] ++;
    }
    for (int l = 1; rank[sa[n]] < n; l <<= 1)
    {
        for (int i = 0; i <= n; i ++) cntA[i] = 0;
        for (int i = 0; i <= n; i ++) cntB[i] = 0;
        for (int i = 1; i <= n; i ++)
        {
            cntA[A[i] = rank[i]] ++;
            cntB[B[i] = (i + l <= n) ? rank[i + l] : 0] ++;
        }
        for (int i = 1; i <= n; i ++) cntB[i] += cntB[i - 1];
        for (int i = n; i; i --) tsa[cntB[B[i]] --] = i;
        for (int i = 1; i <= n; i ++) cntA[i] += cntA[i - 1];
        for (int i = n; i; i --) sa[cntA[A[tsa[i]]] --] = tsa[i];
        rank[sa[1]] = 1;
        for (int i = 2; i <= n; i ++)
        {
            rank[sa[i]] = rank[sa[i - 1]];
            if (A[sa[i]] != A[sa[i - 1]] || B[sa[i]] != B[sa[i - 1]]) rank[sa[i]] ++;
        }
    }
    for (int i = 1, j = 0; i <= n; i ++)
    {
        if (j) j --;
        while (ch[i + j] == ch[sa[rank[i] - 1] + j]) j ++;
        height[rank[i]] = j;
    }
}

int main()
{

}
