#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    string line;
    int n,m;
    while(cin >> n >> m)
    {
        set<string> poknow;
        int C = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> line;
            poknow.insert(line);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> line;
            if (poknow.find(line) != poknow.end())
            {
                C++;
            }
        }
        n -= C;
        m -= C;
        if (C & 1)
        {
            if (n >= m)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if (n > m)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}
