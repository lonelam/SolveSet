#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
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
const int maxn = 100 + 5;
struct Building
{
	int id;
	double x, y, w, d, h;
	bool operator<(const Building & rhs) const
	{
		return rhs.x || (x == rhs.x && y < rhs.y);
	}
	
} b[maxn];

int n;
double x[maxn * 2];
bool cover(int i, double mx)
{
	return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i, double mx)
{
	if (!cover(i, mx))
	{
		return false;
	}
	for (int k = 0; k < n; k++)
	{
		if (b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int kase = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].h);
			x[i * 2] = b[i].x;
			x[i * 2 + 1] = b[i].x + b[i].w;
			b[i].id = i + 1;
		}
		sort(b, b + n);
		sort(x, x + n * 2);
		int m = unique(x, x + n * 2) - x;
		if (kase++)
		{
			printf("\n");
		}
		printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase,b[0]);
		for(int i = )
	}
}