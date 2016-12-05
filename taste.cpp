#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string line;
	while (cin >> n)
	{

		cin >> line;
		int cnt = 0;
		int l = 0, r = n - 1;
		for (; l < n; l++)
		{
			if (line[l] != '<')
			{
				break;
			}
		}
		for (; r >= l; r--)
		{
			if (line[r] != '>')
			{
				break;
			}
		}
		cout << l + n - r -1<< endl;
	}
}
