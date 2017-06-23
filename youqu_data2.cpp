
#include <bits/stdc++.h>
using namespace std;
int a[8] = {1,2,3,4,5,6,7,8};
int main()
{
    for (int kase = 1; kase < 10; kase++)
    {
        string fname  = ".in";
        fname = string(1, kase + '0') + fname;
        freopen(fname.c_str(), "w", stdout);

        random_shuffle(a, a + 8);
        for (int k = 0; k < 10; k++)
        for (int i = 0; i < 8; i++)
        {
            cout << a[i] << ((i == 7)?"\n":" ");
        }
    }

}
