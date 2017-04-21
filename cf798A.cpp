#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;

int main()
{
    string line;
    while(cin >> line)
    {
        int l = 0, r = line.size() - 1;
        int cnt = 0;
        while(l < r)
        {
            if (line[l] != line[r])
                cnt++;
            l++;
            r--;
        }
        if (cnt == 1 || cnt == 0 && (line.size() & 1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout <<"NO" << endl;
        }
    }
}
