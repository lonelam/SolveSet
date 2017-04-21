#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100;
string ss[maxn];
string rss[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin >> n)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            cin >> ss[i];
            rss[i] = ss[i];
        }
        int len = ss[0].size();
        for (int i = 0; i < n && ok; i++)
        {
            if (ss[i].size() != len)
            {
                cout << -1 << endl;
                ok = false;
            }
        }
        int ans = inf;
        for (int i = 0; ok && i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ss[j] = rss[j];
            }
            int cnt = 0;
            for (int j = 0; ok && j < n; j++)
            {
                if (i == j) continue;
                int rot = 0;
                while(ss[j] != ss[i] && rot < len)
                {
                    ss[j] = ss[j].substr(1, ss[j].size() - 1) + ss[j][0];
                    rot++;
                }
                cnt += rot;
                if (rot == len)
                {
                    cout << -1 << endl;
                    ok = false;
                }
            }
            ans = min(ans, cnt);
        }
        if (ok) cout << ans << endl;
    }
}
