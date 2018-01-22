#include <bits/stdc++.h>
using namespace std;
int n;
int grid[31][31];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    grid[x][y] = 0;
    for (int d = 0; d < 4; d++)
    {
        int tx = x + dx[d];
        int ty = y + dy[d];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n && grid[tx][ty] == 2)
            dfs(tx, ty);
    }
}
int main()
{
    cin >> n;
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 0) grid[i][j] = 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 2)
        {
            dfs(i, 0);
        }
        if (grid[0][i] == 2)
        {
            dfs(0, i);
        }
        if (grid[n-1][i] == 2)
        {
            dfs(n-1, i);
        }
        if (grid[i][n-1] == 2)
        {
            dfs(i, n-1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << (j == (n-1)? '\n':' ');
        }
    }
}
