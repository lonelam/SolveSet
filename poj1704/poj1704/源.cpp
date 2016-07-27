#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX_N = 1000;
int N, P[MAX_N];
int main()
{
	int t, n, a, b;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			
			int ans = 0;
			
			for (int i = 0; i < n; i++)
			{
				cin >> P[i];
			}
			if (n & 1)
			{
				P[n++] = 0;
			}
			sort(P, P + n);
			for (int i = 0; i < n; i += 2)
			{
				ans ^= abs(P[i + 1] - P[i] )- 1;
			}
			
			if (ans == 0)
			{
				cout << "Bob will win\n";
			}
			else
			{
				cout << "Georgia will win\n";
			}
		}
	}
}