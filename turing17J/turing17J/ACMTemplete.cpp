#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
typedef long long ll;
typedef long double ld;

map<string, vector<string> > mp;
char word[50];
char tmp[50];
struct groupkey
{
	string key;
	string firstone;
	int sz;
	bool operator<(const groupkey & rhs) const
	{
		if (sz != rhs.sz)
		{
			return sz > rhs.sz;
		}
		return firstone < rhs.firstone;
	}
};
int main()
{
	while (scanf("%s", word) != EOF)
	{
		//	if (word[0] == '0') break;
		memcpy(tmp, word, sizeof(word));
		sort(tmp, tmp + strlen(tmp));
		mp[tmp].push_back(word);
	}
	set<groupkey> st;
	for (auto p : mp)
	{
		sort(p.second.begin(), p.second.end());
		st.insert({ p.first,p.second[0], (int)p.second.size() });
		if (st.size() > 5)
		{
			st.erase(*st.rbegin());
		}
	}
	for (auto g : st)
	{
		vector<string> & t = mp[g.key];
		sort(t.begin(), t.end());
		t.erase(unique(t.begin(), t.end()), t.end());
		printf("Group of size %d: ", t.size());
		for (int i = 0; i <t.size(); i++)
		{
			printf("%s ", t[i].c_str());
		}
		printf(".\n");
	}
	//system("pause");
}

/*
neuq
tea
bate
beat
caret
trace
nueq
carte
cater
crate
abet
ate
eat
beta
eta
signal
*/

/*

qe
qe
h
h


*/