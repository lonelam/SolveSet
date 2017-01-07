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

                for (int dir = 0; dir < 8; dir++)
                {
                    int ti = i + dx[dir]*2;
                    int tj = j + dy[dir]*2;
                    if (ti >= 0 && ti < 4 && tj >= 0 && tj < 4 && grid[ti][tj] == '.' && grid[ti - dx[dir]][tj- dy[dir]] == 'x')
                    {
                        cout << "YES\n";
                        return 0;
                    }
                    if (ti >= 0 && ti < 4 && tj >= 0 && tj < 4 && grid[ti][tj] == 'x' && grid[ti - dx[dir]][tj- dy[dir]] == '.')
                    {
                        cout <<"YES\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}
