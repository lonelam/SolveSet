#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
const int maxn = 201 + 5;
int grid[maxn][maxn];
// 0 空，1 墙， 2 门
int trans[maxn][maxn][4];
int n, m;
typedef pair<int,int> pii;
int nemox, nemoy;
bool dfs(pii cur, vector<pii> & to_ins, int layer)
{
    cout << "---dfs:" << cur.x << " " << cur.y << endl;
    grid[cur.x][cur.y] = layer;
    if (cur.x == nemox && cur.y == nemoy)
    {
        return true;
    }
    for (int d = 0; d < 4; d++)
    {
        if (trans[cur.x][cur.y][d] == 1) continue;
        pii t = {cur.x + dx[d], cur.y + dy[d]};
        if (trans[cur.x][cur.y][d] == 2)
        {
            to_ins.push_back(t);
            continue;
        }
        if (t.x >= 0 && t.x <= 201
            && t.y >= 0 && t.y <= 201
            && grid[t.x][t.y] == -1
            )
        {
            if (dfs(t, to_ins, layer)) return true;
        }
    }
    return false;
}
int BFS()
{
    queue<pii> cur, nex;
    cur.push({0, 0});
    int layer = 0;
    while(!cur.empty())
    {
        while(!cur.empty())
        {
            pii marlin = cur.front();
            cur.pop();
            if (grid[marlin.x][marlin.y] != -1)
            {
                continue;
            }
            vector<pii> to_ins;
            if (dfs(marlin, to_ins, layer))
            {
                return layer;
            }
            for (int i = 0; i < to_ins.size(); i++)
            {
                nex.push(to_ins[i]);
            }
        }
        layer++;
        swap(nex, cur);
    }
    return -1;
}
int main()
{
    while(cin >> m >> n && m != -1)
    {
        memset(trans, 0, sizeof(trans));
        memset(grid, -1, sizeof(grid));
        for (int i = 0; i < m; i++)
        {
            int x, y, d, t;
            cin >> x >> y >> d >> t;
            //1 表示它与 Y-轴平行
            if (d)
            {
                for (int j = 0; j < t && y + j <= 200; j++)
                {
                    trans[x][y + j][2] = 1;
                    trans[x - 1][y + j][3] = 1;
                }
            }
            else
            {
                for (int j = 0; j < t && x + j <= 200; j++)
                {
                    trans[x + j][y][1] = 1;
                    trans[x + j][y - 1][0] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            int x, y, d;
            cin >> x >> y >> d;
            //1 表示它与 Y-轴平行
            if (d)
            {
                trans[x][y][2] = 2;
                trans[x - 1][y][3] = 2;
            }
            else
            {
                trans[x][y][1] = 2;
                trans[x][y - 1][0] = 2;
            }
        }
        double f1, f2;
        cin >> f1 >> f2;
        nemox = min(201, (int)floor(f1));
        nemoy = min(201, (int)floor(f2));
        cout << BFS() << endl;
    }
}
