#include<iostream>
using namespace std;



int main()
{
	int t;
	int n;
	while (cin >> t)
	{
		while (t--)
		{
			cin >> n;
			cout << (1 + n * (n + 1) / 2) << endl;
		}
	}
}