#include<bits/stdc++.h>

using namespace std;

int ans[10][9][10][6][10][6][2];
bool vis[10][9][10][6][10][6][2];
struct node
{
    int x1, y1, x2, y2, x3, y3, first;
};
const int inf = 0x3f3f3f3f;
int horsex[] = {1, 2, 1, 2, -1, -2, -1, -2};
int horsey[] = {2, -1, -2, 1, 2, 1, -2, -1};
int horsebanx[] = {0, 1, 0, 1, 0, -1, 0, -1 };
int horsebany[] = {1, 0, -1, 0, 1, 0, -1, 0};
int genx[] = {1, 0, -1, 0};
int geny[] = {0, 1, 0, -1};
int solve()
{


    queue<node> q,nex;
    int turn = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 3; j < 6; j++)
        {
            for(int x2 = 7; x2 < 10; x2++)
            {

            }
        }
    }
    while(!q.empty())
    {
        turn++;
        while(!q.empty())
        {
            node c = q.front();
            q.pop();
            if(c.first == 0)
            {
                if(c.y3 == c.y2)
                {
                    return ans[x1][y1][x2][y2][x3][y3][first] = -2 ;
                }
                if(c.y1 == c.y3 && c.x1 == c.x3)
                {
                    return ans[x1][y1][x2][y2][x3][y3][first] = turn ;
                }
                for(int i = 0; i < 4; i++)
                {
                    tx = c.x3 + genx[i];
                    ty = c.y3 + geny[i];
                    if(tx >=0 && tx <=3 && ty >=3 && ty <= 5 && !vis[c.x1] && )
                    {
                        q.push({c.x1, c.y1, c.x2, c.y2, tx,ty, 1});
                    }

                }
            }
        }
    }
    if(first == 0)
    {
        if(y3 == y2)
        {
            return ans[x1][y1][x2][y2][x3][y3][first] = 1;
        }

        int a = 100;
        for(int i = 0; i < 4; i++)
        {
            tx = x3 + genx[i];
            ty = y3 + geny[i];
            if(tx >=0 && tx <=3 && ty >=3 && ty <= 5)
            {
                if(tx == )
            }
        }
    }
}
