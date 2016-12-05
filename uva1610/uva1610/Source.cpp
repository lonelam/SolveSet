#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1000 + 10;
string lines[maxn];
int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> lines[i];
		}
		sort(lines, lines + n);
		int lef = n / 2 - 1;
		int rit = n / 2;
		string ans;
		int i = 0;
		while (lines[lef][i] == lines[rit][i])
		{
			ans.push_back(lines[lef][i]);
				i++;
		}
		while (lines[lef][i] + 1 == lines[rit][i])
		{
			ans.push_back(lines[lef][i]);
		}
		cout << ans << endl;
	}
}
