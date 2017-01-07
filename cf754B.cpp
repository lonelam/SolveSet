#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char grid[5][5];
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,1,-1,-1};
int main()
{
    for (int i = 0; i < 4; i ++)
    {
        cin >> grid[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (grid[i][j] == 'x')
            {
                if (i + 2 < 4 && j + 2 < 4 && grid[i + 2][j + 2] == 'x' && grid[i + 1][j + 1] == '.')
                {
                    cout << "YES\n";
                    return 0;
                }
                if (i + 2 < 4 && grid[i+2][j] == 'x' && grid[i + 1][j] == '.')
                {
                    cout << "YES\n";
                    return 0;
                }
                if (j + 2 < 4 && grid[i][j+2] == 'x' && grid[i][j + 1]== '.')
                {
                    cout << "YES\n";
                    return 0;
                }
                for (int dir = 0; dir < 8; dir++)
                {
                    int ti = i + dx[dir]*2;
                    int tj = j + dy[dir]*2;
                    if (ti >= 0 && ti < 4 && tj >= 0 && tj < 4 && grid[ti][tj] == '.' && grid[ti - dx[dir]][tj- dy[dir]] == 'x')
                    {
                        cout << "YES\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}
