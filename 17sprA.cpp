#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 30;
char grid[maxn][maxn];

int main()
{
    int n, m;
    int kase = 1;
    while(cin >> n >> m)
    {
        cout <<"Case "<< kase++ << endl;
        for (int i = 0; i < n; i++)
        {
            int p = -i;
            for (int j = 0; j < m; j++)
            {
                if (p < 0)
                    cout << char('A' + (-p));
                else
                {
                    cout << char('A' + p);
                }
                p++;
            }
            cout << endl;
        }
    }
}
