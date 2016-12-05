#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	int n, k;
	int gp, tp;
	while (cin >> n >> k >> line)
	{
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == 'G')
			{
				gp = i;
			}
			if (line[i] == 'T')
			{
				tp = i;
			}
		}
		if (gp > tp)
		{
			int prepos = gp;
			for (int i = gp; i >= tp; i--)
			{
				if (line[i] == '.' && prepos - i == k)
				{
					prepos = i;
				}
			}
			if (prepos - tp == k)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			int prepos = gp;
			for (int i = gp; i <= tp; i++)
			{
				if (line[i] == '.' && prepos - i == -k)
				{
					prepos = i;
				}
			}
			if (prepos - tp == -k)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}