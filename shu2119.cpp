#include <bits/stdc++.h>
using namespace std;
string grid[10][10];
int ans[10];
int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        e = -1;
        map<string, int> digit;
        map<int, string> pro;
        bool ok = true;
        for (int i = 1; i < n; i++)
        {
            int cnt = 0;
            for (int j = 1; j < n; j++)
            {
                if (grid[i][j].size() > 1) cnt++;
                else if (grid[i][j].size() > 2) ok = false;
            }
            ans[i] = cnt;
            digit[grid[i][0]] = cnt;
            if (cnt == 1) e = i;
        }

        if (e == -1) ok = false;
        for (int i = 1; i < n; i++)
        for (int i = 1; i < n; i++)
        {
            cout << grid[i][0] <<"="<< ans[i]<<(i == n-1?"\n":" ");
        }
        cout << n - 1 << endl;
    }
}
