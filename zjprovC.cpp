#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200 * 20 + 2;
char p[202][22];
char qs[22][202][22];
int qid[22][202];
int m[22];
int vis[202];
int main()
{
    int T, n, q, c;
    while(scanf("%d", &T)!=EOF)
    {
        while(T--)
        {
            scanf("%d%d%d", &n, &q, &c);
            map<string, int> id;
            for (int i = 0; i < c; i++)
            {
                scanf("%s", p[i]);
                id[string(p[i])] = i;
            }
            for (int i = 0; i < q; i++)
            {
                scanf("%d", m + i);
                for (int j = 0; j < m[i]; j++)
                {
                    scanf("%s", qs[i][j]);
                    qid[i][j] = id[string(qs[i][j])];
                }
            }
            int over;
            for (int i = 0; i < n; i++)
            {
                memset(vis, 0,sizeof(vis));

                int ycnt = 0;
                for (int j = 0; j < q; j++)
                {
                    scanf("%d", &over);
                    if (over)
                    {
                        for (int k = 0; k < m[j]; k++)
                        {
                            ++vis[qid[j][k]];
                        }
                        ycnt++;
                    }
                    else
                    {
                        for (int k = 0; k < m[j]; k++)
                        {

                            vis[qid[j][k]]--;
                        }

                    }
                }
                int standone = -1, standcnt = 0;
                for (int j = 0; j < c; j++)
                {

                    if (ycnt == vis[j])
                    {
                        standone = j;
                        standcnt++;
                    }
                }
                if (standcnt == 1)
                {
                    printf("%s\n", p[standone]);
                }
                /*else if (leftcnt == 1)
                {
                    printf("%s\n", p[leftone]);
                }*/
                else
                {
                    printf("Let's go to the library!!\n");
                }
            }
        }
    }
}
