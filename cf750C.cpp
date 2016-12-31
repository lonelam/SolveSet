#include <iostream>
using namespace std;
const int maxn = 200000 + 100;
const int inf = 0x3f3f3f3f;
int c[maxn];
int d[maxn];
int main()
{
    int n;
    while(cin >> n)
    {
        int maxd2 = -inf;
        bool based = false;
        bool imp = false;
        int mind1 = inf;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i] >> d[i];
            if ( d[i] == 2)
            {
                maxd2 = max(maxd2, cur);
            }

            if (d[i] == 1)
            {
                mind1 = min(mind1, cur);
            }

            cur += c[i];
        }
        if (mind1 <= maxd2)
        {
            cout << "Impossible\n";
        }
        else if (maxd2 == -inf)
        {
            cout << "Infinity\n";
        }
        else
        {
            cout << (1899+cur - maxd2)<< endl;
        }
    }
}
