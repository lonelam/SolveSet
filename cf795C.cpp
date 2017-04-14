#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    int n;
    cin >> n;
    int ones = n / 2;
    if (n % 2 == 0)
    {
        for (int i = 0 ; i < ones; i++)
        {
            cout << '1';
        }
    }
    else if (n & 1)
    {
        cout << '7';
        for (int i = 1; i < ones; i++)
        {
            cout << '1';
        }
    }
    cout << endl;
}
