#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
const int chsize = 26;
int len[maxn], ch[maxn][chsize], f[maxn];
int tot, head, tail;

void add(int x)
{
    int p = tail, np = tot++;
    len[np] = len[p] + 1;
    memset(ch[np], -1, sizeof(ch[np]));
    for (; p != -1 && ch[p][x] == -1; p = f[p])
    {
        ch[p][x] = np;
    }
    tail = np;
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
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        f[nq] = f[q];
        len[nq] = len[p] + 1;
        f[np] = f[q] = nq;
        for (; p != -1 && ch[p][x] == q; p = f[p])
        {
            ch[p][x] = nq;
        }
    }
}
char sa[maxn], sb[maxn];
int main()
{
    while(scanf("%s", sa) != EOF)
    {
        scanf("%s", sb);
        int n = strlen(sa), m = strlen(sb);
        head = tail = 0;
        len[0] = 0;
        tot = 1;
        f[0] = -1;
        memset(ch[0], -1, sizeof(ch[0]));
        for (int i = 0; i < n;i ++)
        {
            add(sa[i] - 'a');
        }
        int p = head, lcs = 0, ans = 0;
        for (int i = 0; i < m; i++)
        {
            int x = sb[i] - 'a';
            if (ch[p][x] != -1)
            {
                p = ch[p][x];
                lcs++;
                ans = max(lcs, ans);
            }
            else
            {
                for (; p != -1 && ch[p][x] == -1; p = f[p]);
                if (p == -1)
                {
                    lcs = 0;
                    p = 0;
                }
                else
                {
                    lcs = len[p] + 1;
                    p = ch[p][x];
                }
            }
        }
        printf("%d\n", ans);
    }
}
