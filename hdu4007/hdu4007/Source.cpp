#include<iostream>
#include<algorithm>
using namespace std;
int n, r;
struct node
{
	int x, y;
	friend bool operator<(const node & lhs, const node & rhs)
	{
		if(lhs.x != rhs.x) return  lhs.x < rhs.x;
		else return lhs.y < rhs.y;
	}
} ns[1050];
int main()
{
	while (cin >> n >> r)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> ns[i].x >> ns[i].y;
		}
		sort(ns, ns + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int sqy = ns[i].y;
			int sqmy = sqy + r;
			int le = 0, rt = 0;
			int cnt = 0;
			
			while (le < n)
			{
				//cnt = 0;
				//for (rt = le; rt < n && ns[rt].x <= ns[le].x + r; rt++)
				//{
				//	if (ns[rt].y >= sqy && ns[rt].y <= sqmy)
				//	{
				//		cnt++;
				//	}
				//}
				while (rt < n && ns[rt].x <= ns[le].x + r)
				{
					if (ns[rt].y >= sqy && ns[rt].y <= sqmy)
					{
						cnt++;
					}
					rt++;
				}
				ans = max(ans, cnt);
				le++;
			}

		}
		cout << ans << endl;
	}
}