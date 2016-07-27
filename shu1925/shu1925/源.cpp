#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>


using namespace std;
//一个像素点
struct pixel
{
	int r, g, b;
};
int cnt[256][256][256];//存下每种颜色的数量
//哈希优化，可以不用
bool used[10000000];

int main()
{

	int t, n, q, i = 1;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			cout << "Case #" << i++ << ":\n";
			memset(cnt, 0, sizeof(cnt));
			memset(used, 0, sizeof(used));
			//BST，map的使用
			map<int, pixel>g;
			pixel tmp;
			int No, cls = 1;//cls 颜色数
			cin >> n >> q;
			cnt[0][0][0] = n;//
			while (q--)
			{
				scanf("%d%d%d%d", &No, &tmp.r, &tmp.g, &tmp.b);
				if (!used[No % 10000000] || g.count(No) != 0)//判断点是否已经被改动过了
				{
					used[No % 10000000] = true;
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
				printf("%d\n", cls);//输出
			}
		}
	}
}