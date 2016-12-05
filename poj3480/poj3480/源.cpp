#include<iostream>
using namespace std;
int main()
{
	int t, n,a,b;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			int ans = 1;
			for(int i = 0;i<n;i++)
			{
				cin >> a;
				ans ^= a;
			}
			if (ans == 0)
			{
				cout << "Brother\n";
			}
			else
			{
				cout << "John\n";
			}
		}
	}
}