#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int f(string &s, int i)
{
	if (s[i] == 'T'&&s[i + 1] == 'H'&&s[i + 2] == 'E')
		return 0;
	else if (s[i] == 'A')
		return 0;
	else if (s[i] == 'A'&&s[i + 1] == 'N')
		return 0;
	else if (s[i] == 'O'&&s[i + 1] == 'F')
		return 0;
	else if (s[i] == 'F'&&s[i + 1] == 'O'&&s[i + 2] == 'R')
		return 0;
	else if (s[i] == 'A'&&s[i + 1] == 'N'&&s[i + 2] == 'D')
		return 0;
	else return 1;
}

int main()
{
	int i, j, k = 0;
	string s, s1;
	while (getline(cin, s)) {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		//  cout << s<<endl;
		j = 0;
		if (s[0] != ' '&&f(s, 0))
			s1[j++] = s[0];
		for (i = 1; s[i]; i++)
			if (s[i - 1] == ' '&&f(s, i))
				s1[j++] = s[i];
		s1[j] = '\0';

		cout << "Case " << ++k << ": " << s1 << endl;
	}
	return 0;
}
