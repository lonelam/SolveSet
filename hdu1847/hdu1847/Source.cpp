#include<iostream>
using namespace std;

bool g[1000];
int main()
{
	int n;
	while (cin >> n)
	{
		if (n % 3 == 0)
		{
			cout << "Cici\n";
		}
		else
		{
			cout << "Kiki\n";
		}
	}
}