#include<string>
#include<iostream>
#include<set>
#include<algorithm>
#include<sstream>
#include<cctype>
using namespace std;
//the£¬a£¬an£¬of£¬for¼°and
set<string> ign = { "THE", "A" ,"AN", "OF", "FOR", "AND"};
int main()
{
	int kase = 1;
	string line;
	while (getline(cin, line))
	{
		for_each(line.begin(), line.end(), [](char & a) {if(a  == '-') a = ' '; });

		stringstream ss(line);
		string wd;
		string ans;
		while (ss >> wd)
		{
			for_each(wd.begin(), wd.end(), [](char & a) {a = toupper(a); });
			if (ign.find(wd) == ign.end())
			{
				ans.push_back(wd[0]);
			}
		}
		cout << "Case " << kase++ << ": " << ans << endl;
	}
}