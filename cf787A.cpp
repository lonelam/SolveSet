#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (abs(d - b) % gcd(a, c))
    {
        cout << -1 << endl;
    }
    else
    {
        set<int> get;
        for (int i = 0; i < 10000; i++)
        {
            get.insert(b + a * i);
        }
        for (int i = 0; i < 10000; i++)
        {
            if (get.find(d + c* i) != get.end())
            {
                cout << d + c * i << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }
}
