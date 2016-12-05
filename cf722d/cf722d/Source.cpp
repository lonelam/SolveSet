#include<iostream>
#include<string>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;
set<int> x;
int y[50005];
int main()
{
	int n;
	int cur;
	while (cin >> n)
	{
		x.clear();
		//y.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> y[i];
		}
		sort(y, y + n);
		x.insert(1);
		for (int i = 0; i < n; i++)
		{
			cur = y[i];
			while (true)
			{
				//cur = y[i];
				if (x.count(cur >> 1) == 1)
				{
					break;
				}
				cur >>= 1;
			}
			x.insert(cur);
			y[i] = cur;
		}
		cout << y[0];
		for (int i = 1; i < n; i++)
		{
			cout << " " << y[i];
		}
		cout << endl;
	}
}