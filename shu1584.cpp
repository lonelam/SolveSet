#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;


int main()
{
    int n;
    while(cin >> n)
    {
        ll sum = 0;
        ll air = 1, land = 1;
        for (int i = 0; i < 10; i++)
        {
            air *= n;
        }
        for (int i = 0; i < 6; i++)
        {
            land *= n;
        }
        sum = (air + 4 * n * n + 5 * land) / 10;
        cout << sum << endl;
    }
}
