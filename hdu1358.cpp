#include<bits/stdc++.h>
using namespace std;

//kmp
const int maxn = 1000000 + 20;
int f[maxn];
int main()
{
	int n;
	int kase = 1;
	string line;
	while(cin >> n && n)
	{
		cin >> line;
		f[0] = f[1] = 0;
		for (int i = 1; i < n; i++)
		{
			int j = f[i];
			while(j && line[j] != line[i]) j = f[j];
			f[i + 1] = (line[i] == line[j]? j + 1 : 0);
		}
		cout << "Test case #" << kase++ << endl;
		for (int i = 2; i <= n; i++)
		{
			if ( (i) % (i - f[i]) == 0 && i / (i - f[i]) > 1)
			{
				cout << i << ' ' << (i) / (i - f[i]) << endl;
			}
		}
		cout << endl;
	}
}
