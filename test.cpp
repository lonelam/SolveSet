
#include <bits/stdc++.h>
using namespace std;
set<int> s;
inline int lcm (int a, int b)
{
    return a / __gcd(a, b) * b;
}
int main()
{
    for (int i = 0; i < 1 << 10; i++)
    {
        int ans = 1;
        for (int j = 0; j < 10; j++)
        {
            if (i >> j & 1)
            {
                ans = lcm(ans, j);
            }
        }
        s.insert(ans);
    }
    cout << s.size() << endl;
    for (int x : s)
    {
        cout <<x << endl;
    }
}
