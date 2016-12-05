#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct node
{
	int x, y;
	friend bool operator < (node a, node b) {
		if (a.x == b.x) return a.y<b.y;
		else return a.x<b.x;
	}
};
node a[100];
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y;
		}

	}
}