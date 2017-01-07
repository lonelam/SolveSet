#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int presum[maxn];
int from[maxn], to[maxn];
int main()
{
    int n;
    cin >> n;
    int prenon = 0;
    int cnt = 0;
    bool nonze = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> presum[i];
        if (presum[i]) nonze = true;
    }
    if (!nonze)
    {
        cout <<"NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        from[cnt] = i;
        while(i <= n && presum[i] == 0)
        {
            i++;
        }
        to[cnt++] = i;
    }
    if (presum[n] == 0)
    {
        cnt--;
        to[cnt - 1] = n;
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << from[i] <<" "<< to[i] << endl;
    }
}
