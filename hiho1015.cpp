#include<iostream>
#include<string>
using namespace std;
const int maxn = 100000 + 20;
int P[maxn];
void getFail(string & pat)
{
	int m = pat.length();
	P[0] = P[1] = 0;

	for (int i = 1; i < m; i++)
	{
		// i + 1 dismatched, so P[i] should be used to define the kmp function

		int j = P[i];
		// self-kmp!!
		while(j && pat[i] != pat[j]) j = P[j];
		P[i + 1] = pat[i] == pat[j] ? j + 1 : 0;
	}
}
int main()
{
	int n;
	while(cin >> n)
	{
		string line;
		string pat;
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			cin >> pat >> line ;
			getFail(pat);
			int j = 0;
			for (int k = 0; k < line.length(); k++)
			{
				while( j && line[k] != pat[j]) j = P[j];
				if (line[k] == pat[j]) j++;
				if (j == pat.length()) cnt++;
			}
			cout << cnt << endl;
		}
	}
}


