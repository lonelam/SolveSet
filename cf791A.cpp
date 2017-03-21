#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    int a,b;
    cin >> a >> b;
    for (int i = 0; ; i++)
    {
        if (a > b)
        {
            cout << i << endl;
            return 0;
        }
        a *= 3;
        b *= 2;
    }
}
