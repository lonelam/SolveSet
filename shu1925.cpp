#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
 
/*
-----------Answered by Lonelam---------
*
*          ┌─┐       ┌─┐
*       ┌──┘ ┴───────┘ ┴──┐
*       │                 │
*       │       ───       │
*       │  ─┬┘       └┬─  │
*       │                 │
*       │       ─┴─       │
*       │                 │
*       └───┐         ┌───┘
*           │         │
*           │         │
*           │         │
*           │         └──────────────┐
*           │                        │
*           │                        ├─┐
*           │                        ┌─┘
*           │                        │
*           └─┐  ┐  ┌───────┬──┐  ┌──┘
*             │ ─┤ ─┤       │ ─┤ ─┤
*             └──┴──┘       └──┴──┘
*                 神兽保佑
*                 代码无BUG!
*/
using namespace std;
struct pixel
{
	int r, g, b;
};
int cnt[256][256][256];

bool used[10000000];

int main()
{
    
	int t, n, q, i = 1;
	while (scanf("%d",&t)!=EOF)
	{
		while (t--)
		{
			cout << "Case #" << i++ << ":\n";
			memset(cnt, 0, sizeof(cnt));
			memset(used,0,sizeof(used));
			map<int, pixel>g;
			pixel tmp;
			int No,cls = 1;
			cin >> n >> q;
			cnt[0][0][0] = n;
			while (q--)
			{
				scanf("%d%d%d%d",&No,&tmp.r,&tmp.g,&tmp.b);
				if (!used[No%10000000] || g.count(No) != 0)
				{
					used[No%10000000] = true;
					if (--cnt[g[No].r][g[No].g][g[No].b] == 0)
					{
						cls--;
					}
					if (cnt[tmp.r][tmp.g][tmp.b]++ == 0)
					{
						cls++;
					}
					g[No] = tmp;
				}
				else
				{
					if (--cnt[0][0][0] == 0)
					{
						cls--;
					}
					if (cnt[tmp.r][tmp.g][tmp.b]++ == 0)
					{
						cls++;
					}
					g[No] = tmp;
				}
				printf("%d\n",cls);
			}
		}
	}
}
