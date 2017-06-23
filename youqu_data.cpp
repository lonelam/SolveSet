#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int kase = 1; kase < 10; kase++)
    {
        string fname  = ".in";
        fname = string(1, kase + '0') + fname;
        freopen(fname.c_str(), "w", stdout);
        random_device rd;
        uniform_int_distribution<int> rn(1, 1e9), rL(1, 2100000000);
        int t = 200000;
        cout << t << endl;

        for (int i = 0; i < t; i++)
        {
            cout << rn(rd) << endl;
        }
    }

}
