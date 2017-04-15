#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    int n, m;
    cin >> n >> m;
    bool ok = true;
    for (int i = 0; ok && i < m; i++)
    {
        int k;
        cin >> k;
        set<int> app, neg;
        bool ook = false;
        int tmp;
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            if (tmp > 0)
            {
                if (neg.find(tmp) != neg.end()) ook = true;
                app.insert(tmp);
            }
            else
            {
                if (app.find(-tmp) != app.end()) ook = true;
                neg.insert(-tmp);
            }
        }
        if (k && !ook)
        {
            ok = false;
        }
    }
    if (ok)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}
