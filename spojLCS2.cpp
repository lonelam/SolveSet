#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
const int chsize = 26;

int tot, len[maxn], ch[maxn][chsize], f[maxn], lcs[maxn], tail, head;
void add(int x)
{
    int p = tail, np = tot++;
    len[np] = len[p] + 1;
    tail = np;
    for (; p != -1 && !ch[p][x]; p = f[p])
    {
        ch[p][x] = np;
    }
    if (p == -1)
    {
        f[np] = head;
    }
    else if (len[p] + 1 == len[ch[p][x]])
    {
        f[np] = ch[p][x];
    }
    else
    {
        int q = ch[p][x], nq = tot++;
        len[nq] = len[p] + 1;
        f[nq] = f[q];
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        f[q] = f[np] = nq;
        for (; p != -1 && ch[p][x] == q; p = f[p])
        {
            ch[p][x] = np;
        }
    }
}
void init()
{
    tot = 1;
    tail = head = 0;
    memset(ch, 0, sizeof(ch));
    f[0] = -1;
    len[0] = 0;
    memset(lcs, inf, sizeof(lcs));
}
char a[maxn];
int main()
{
    scanf("%s", a);
    int n = strlen(a);
    init();
    for (int i = 0; i < n; i++)
    {
        add(a[i] - 'a');
    }

    while(scanf("%s", a) != EOF)
    {
        n = strlen(a);
        int nlcs = 0, p = head;

        for (int i = 0; i < n; i++)
        {
            int x = a[i] - 'a';
            if (ch[p][x])
            {
                p = ch[p][x];
                nlcs++;
                lcs[p] = min(lsc[p], )
            }
        }
    }
}
