#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 205;
int x[maxn];
int y[maxn];
double dis[maxn][maxn];
double fdis[maxn];
bool inq[maxn];
int n;
void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dis[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}
	
}
double spfa()
{
	init();
	queue<int> cur;
	cur.push(0);
	for (int i = 0; i < n; i++)
	{
		fdis[i] = 1500;
	}
	fdis[0] = 0;
	while (!cur.empty())
	{
		int c = cur.front();
		cur.pop();
		inq[c] = false;
		for (int i = 0; i < n; i++)
		{
			if (i != c && fdis[i] > max(dis[c][i], fdis[c]))
			{
				fdis[i] = max(dis[c][i], fdis[c]);
				if (!inq[i])
				{
					inq[i] = true;
					cur.push(i);
				}
			}
		}
	}
	return fdis[1];

}
int main()
{
	int kase = 1;
	while (scanf("%d", &n) != EOF&& n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", x + i, y + i);
		}
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",kase++, spfa());

	}
}