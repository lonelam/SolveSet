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
typedef unsigned long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
map<char, ll> hval;
const int maxn = 10005;
const int maxprime = 20005;
const ll moder = 1e9 + 7 ;
const ll Radix = 10007;
int lennum;
int lenss[maxn];
bool nprime[maxprime];
void init()
{
    nprime[0] = true;
    nprime[1] = true;
    nprime[2] = false;
    for (int i = 2; i < maxprime; i++)
    {
        if (!nprime[i])
        {
            for (int j = i + i; j < maxprime; j+= i)
            {
                nprime[i] = true;
            }
        }
    }
    char hkey = 127;
    for (int k = 10000; k < maxprime && hkey; k++)
    {
        if (!nprime[k])
        {
            hval[hkey--] = k;
        }
    }
}

ll Hash[maxn];
ll hpower[maxn];

char S[maxn];
int n;
void build()
{
    Hash[0] = 0;
    hpower[0] = 1;
    for (int i = 0; i < n; i++)
    {
        Hash[i+1] = (Hash[i] + hval[S[i]]) % moder;
        hpower[i+1] = hpower[i] * Radix % moder;
    }
}
//i,j inclusive
ll get(int i, int j)
{
    if (i == j)
    {
        return S[j];
    }
    ll ret = (Hash[j ] - Hash[i + 1] + moder )% moder;
    ret = (ret + S[i] * hpower[0] + S[j] * hpower[j - i + 1]) % moder;
    return ret;
}
char wd[maxn];
map<ll, int> htable[27];
map<ll, string> h2str;
int mem[maxn];
int pre[maxn];
int dfs(int pos)
{
    if (mem[pos] != -1)
    {
        return mem[pos];
    }
    int ans = 0;
    if (htable[S[pos] - 'a'].size() == 0)
    {
        return mem[pos] = 0;
    }
    for (int ii = 0; ii < lennum && pos + lenss[ii] <= n; ii++)
    {
        int i = lenss[ii];
        ll hh = get(pos, pos + i - 1);
        if (htable[S[pos] - 'a'].find(hh) != htable[S[pos] - 'a'].end())
        {
            int tmp = dfs(pos + i);
            if (tmp)
            {
                ans += htable[S[pos] - 'a'][hh] * tmp;
                pre[pos + i] = pos;
            }
        }
        if (ans > 1)
        {
            break;
        }
    }
    return mem[pos] = ans;
}
int main()
{
    int T;
    init();
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%s", S);
            n = strlen(S);
            build();
            for (int i = 0; i < 27; i++) htable[i].clear();
            h2str.clear();
            int wdnum;
            scanf("%d", &wdnum);
            for (int i = 0; i < wdnum; i++)
            {
                scanf("%s", wd);
                int m = strlen(wd);
                lenss[i] = m;
                if (m == 1)
                {
                    htable[wd[0] - 'a'][wd[0]]++;
                    h2str[wd[0]] = wd;
                    continue;
                }
                if (m > n)
                {
                    continue;
                }
                ll hh = (wd[0] * 1LL + wd[m - 1] * hpower[m]) % moder;
                for (int i = 1; i + 1 < m; i++)
                {
                    hh = (hval[wd[i]] + hh) % moder;
                }
                htable[wd[0] - 'a'][hh]++;
                h2str[hh] = wd;
            }
            sort(lenss, lenss + wdnum);
            lennum = unique(lenss, lenss + wdnum) - lenss;
            memset(mem, -1, sizeof(mem));
            mem[n] = 1;
            int ans = dfs(0);
            if (ans == 0)
            {
                printf("impossible\n");
            }
            else if (ans > 1)
            {
                printf("ambiguous\n");
            }
            else
            {
                int p = n;
                vector<string> ans;
                while(p)
                {
                    ll hh = get(pre[p], p - 1);
                    ans.push_back(h2str[hh]);
                    p = pre[p];
                }
                for (int i = ans.size() - 1; i >= 0; i--)
                {
                    printf("%s%c", ans[i].c_str(), i == 0 ? '\n': ' ');
                }
            }
        }
    }
}
