#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 100000;
typedef long double ld;
typedef long long ll;
int n;
char buffer[maxn];
const int chsize = 26;
int maxm;
vector<int> stat[chsize];
int code[chsize];
const ll moder = 1e9+7;
bool cmp(const int lhs,const int rhs)
{
    for (int i = maxm - 1; i >= 0; i--)
    {
        if (stat[lhs][i] != stat[rhs][i])
        {
            return stat[lhs][i] < stat[rhs][i];
        }
    }
    return false;
}
int perm[chsize];
bool vis[chsize];
int main()
{
  //freopen("/home/lais/Downloads/多校联合训练第一场标程及数据/数据/1002.in", "r", stdin);
    int kase = 1;
    while(scanf("%d", &n) != EOF)
    {

        vector<string> ss;
        maxm = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buffer);
            int m = strlen(buffer);
            if (m > 1) vis[buffer[0] - 'a'] = true;
            reverse(buffer, buffer + m);
            ss.push_back(string(buffer));
            maxm = max(maxm, m);
        }
      //  cout << maxm << endl;
        for (int i = 0; i < chsize; i++) stat[i] = vector<int>(maxm, 0);
        /*for (int i = 0; i < chsize; i++)
        {
            for (int j = 0; j < maxm;j++)
            {
                stat[i][j] = 0;
            }
        }*/
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < ss[i].size(); j++)
            {
                stat[ss[i][j] - 'a'][j]++;
            }
        }
        for (int i = 0; i < chsize; i++)
        {
          for (int j = 1; j < maxm; j++)
          {
            stat[i][j] += stat[i][j-1] / 26;
            stat[i][j-1] %= 26;
          }
        }
        for (int i = 0; i < chsize; i++) perm[i] = i;
        sort(perm, perm + chsize, cmp);
        int leader = 0;
        for (int i = 0; i < chsize; i++)
        {
            leader = i;
            if (!vis[perm[i]]) break;
        }
        int leaderalpha = perm[leader];
        for (int i = leader; i >= 1; i--)
        {
            perm[i] = perm[i-1];
        }
        perm[0] = leaderalpha;
        for (int i = 0; i < chsize; i++) code[perm[i]] = i;
        //if (kase == 11) for (int i = 0; i < chsize; i++) cout << char('a' + i) << "->" << code[i] << endl;
        ll ans = 0;
        ll base = 1;
        for (int i = 0; i < maxm; i++)
        {
            for (int j = 0; j < chsize; j++)
            {
                ans = (ans + (((ll) code[j] * stat[j][i]%moder )* base) % moder)% moder;
            }
            base = (base * 26LL) % moder;
        }
       /* for (int i = 0; i < n; i++)
        {
            ll base = 1;
            for (int j = 0; j < ss[i].size(); j++)
            {
                ans = (ans + ((ll)code[ss[i][j] - 'a'] * base) % moder) % moder;
                base = (base * chsize) % moder;
            }
        }*/
        printf("Case #%d: %lld\n", kase++, ans % moder);
    }
}
/*

1
abcdefghijklmnopqrstuvwxyz
5
abcdefghijklmnopqrstuvwxyz
zz
yy
za
ya

*/
