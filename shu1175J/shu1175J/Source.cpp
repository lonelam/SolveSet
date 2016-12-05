#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
	string line;
	int n, m;
	while (cin >> n >> m)
	{
		cin >> line;
		for (int i = 0; i < n; i++)
		{
			if (islower(line[i]))
			{
				line[i] = 'a' + (line[i] - 'a' + m) % 26;
			}
			else if(isupper(line[i]))
			{
				line[i] = 'A' + (line[i] - 'A' + m) % 26;
			}
		}
		cout << line << endl;
	}
}