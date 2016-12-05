#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
	int x, y;
	bool operator < (const Point & rhs) const
	{
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
	int dot(Point  a)
	{
		return x * a.x + y * a.y;
	}
	int cross(Point  a)
	{
		return x * a.y - y * a.x;
	}
	int length()
	{
		return x * x + y * y;
	}
	Point operator-(Point rhs)
	{
		Point ans(*this);
		ans.x -= rhs.x;
		ans.y -= rhs.y;
		return ans;
	}
};
Point ps[50050];
Point conv[100050];
int main()
{
	int t,n;
	while (scanf("%d",&n)!=EOF)
	{
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &ps[i].x, &ps[i].y);
	//		cin >> ps[i].x >> ps[i].y;
		}
		sort(ps, ps + n);
		for (int i = 0; i < n; i++)
		{
			while (k > 1 && (conv[k - 1] - conv[k - 2]).cross(ps[i] - conv[k - 1]) <= 0)
			{
				k--;
			}
			conv[k++] = ps[i];
		}
		int tk = k;
		for (int i = n - 2; i >= 0; i--)
		{
			while (k > tk && (conv[k - 1] - conv[k - 2]).cross(ps[i] - conv[k - 1] )<= 0)
			{
				k--;
			}
			conv[k++] = ps[i];
		}
		k--;
		int ans = 0;
		
		if (k == 2)
		{
			ans = (conv[0] - conv[1]).length();
		}
		else
		{
			int i = 0, j = 0;
			for (int o = 0; o < k; o++)
			{
				if (!(conv[i] < conv[o])) i = o;
				if ((conv[j] < conv[o])) j = o;
			}
				int si = i, sj = j;
				while (i != sj || j != si)
				{
					ans = max(ans, (conv[i] - conv[j]).length());
					if ((conv[(i + 1) % k] - conv[i]).cross(conv[(j)] - conv[(j + 1) % k]) > 0)
					{
						i = (i + 1) % k;
					}
					else
					{
						j = (j + 1) % k;
					}
				}
		}
		printf("%d\n", ans);
	//	cout <<ans<< endl;
	}
}