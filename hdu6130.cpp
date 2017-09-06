
#include <bits/stdc++.h>
using namespace std;
int ans[10000000 +100];
int main()
{
    ans[0] = 1;
    ans[1] = ans[2] = 2;
    int p = 2;
    int q = 3;
    while(q < 10000001)
    {
        if (ans[p] == 1) { ans[q] = (ans[q-1]==1)?2:1; q++;}
        else {ans[q] = ans[q + 1] = (ans[q - 1]==1)?2:1; q+= 2;}
        p++;
    }
    int T;
    cin >> T;
    int n;
    while(T--)
    {
        cin >> n;
        cout << ans[n-1] << endl;
    }
}
