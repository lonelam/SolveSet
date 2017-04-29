#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    bool st = true;
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] && (a[0] || a[1] || a[2] || a[3]))
    {
        if (!st) cout << endl;
        st = false;
        int pre = -1;
        sort(a, a +4);
        while(true)
        {
            if (a[0]) cout << a[0] << a[1] <<a [2] <<a [3];
            pre = a[0];
            if (next_permutation(a, a +4))
            {
                if (a[0] == 0 || pre == 0) continue;
                if (a[0] != pre)
                {
                    cout << endl;
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << endl;
                break;
            }
        }

    }
}
