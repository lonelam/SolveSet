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
#include <random>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef long double ld;

const int maxn = 100000;
set<string> string_table;
vector<string> all_string_table;
random_device rd;
char randchar()
{
	uniform_int_distribution<int> rndchar('a', 'z');
	return char(rndchar(rd));
}
void stringrand()
{
	uniform_int_distribution<int> len_rnd(3, 30);
	for (int i = 0; i < 100000; i++)
	{
		int lenlen = len_rnd(rd);
		string a(lenlen, 'a');
		for (int j = 0; j < lenlen; j++)
		{
			a[j] = randchar();
		}
		string_table.insert(a);
	}
	for (string x : string_table)
	{
		all_string_table.push_back(x);
	}
}
vector<string> inset;
vector<string> conset;
vector<pair<string, int>> incontest;
map<string, int> contestid;
map<int, bool> isopen;
vector<vector<int> > contest_list;
int main()
{
	stringrand();
	for (int k = 1; k < 10; k++)
	{
		srand(rd());
		string fext = ".in";
		string fname(1, k + '0');
		string iname = fname + fext;
		int tot = 0;
		freopen(iname.c_str(), "w", stdout);
		cout << 1000 << " " << 15000 << endl;
		inset.clear();

		for (int i = 0; i < 1000; i++)
		{
			cout << *string_table.rbegin() << endl;
			inset.push_back(*string_table.rbegin());
			string_table.erase(*string_table.rbegin());
		}

		for (int i = 0; i < 5000; i++)
		{
			uniform_int_distribution<int> cmd_rnd(1, 5);
			int cmd = cmd_rnd(rd);
			if (cmd == 1)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
				int tid = tidrand(rd);
				uniform_int_distribution<int> tinsetrand(0, inset.size() - 1);
				if (rand() & 1)
					cout << all_string_table[tid] << endl;
				else if (rand() & 1)
				{
					tid = tinsetrand(rd);
					cout << inset[tid] << endl;
				}
				else if (conset.size())
				{
					uniform_int_distribution<int> tconsetrand(0, conset.size() - 1);
					tid = tconsetrand(rd);
					cout << conset[tid] << endl;
				}
				else
				{
				    tid = tidrand(rd);
					cout << all_string_table[tid] << endl;
				}
			}
			else if (cmd == 2)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
				int tid = tidrand(rd);
				uniform_int_distribution<int> tinsetrand(0, inset.size() - 1);

				if (rand() & 1)
					cout << all_string_table[tid] << endl;
				else if (rand() & 1)
				{
					tid = tinsetrand(rd);
					cout << inset[tid] << endl;
				}
				else if (conset.size())
				{
					uniform_int_distribution<int> tconsetrand(0, conset.size() - 1);
					tid = tconsetrand(rd);
					cout << conset[tid] << endl;
				}
				else
				{
				    tid = tidrand(rd);
					cout << all_string_table[tid] << endl;
				}
			}
			else if (cmd == 3)
			{
				cout << cmd << endl;
				tot++;
			}
			else if (cmd == 4)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> con_rnd(1, tot ? tot : 1000);
				cout << con_rnd(rd) << endl;
			}
			else if (cmd == 5)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
				int tid = tidrand(rd);
				uniform_int_distribution<int> con_rnd(1, tot ? tot : 1000);
				cout << all_string_table[tid] << " " << con_rnd(rd) << endl;
			}
		}
		for (int i = 0; i < 100; i++)
		{
			cout << 3 << endl;
			tot++;
		}
		uniform_int_distribution<int> con_rnd(1, tot ? tot : 1000);
		for (int i = 0; i < 4900; i++)
		{
			cout << 5 << " ";
			cout << *string_table.rbegin() << " " << con_rnd(rd) << endl;
			conset.push_back(*string_table.rbegin());
			string_table.erase(*string_table.rbegin());

		}
		for (int i = 0; i < 5000; i++)
		{
			uniform_int_distribution<int> cmd_rnd(1, 5);
			int cmd = cmd_rnd(rd);
			if (cmd == 1)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
				int tid = tidrand(rd);
				uniform_int_distribution<int> tinsetrand(0, inset.size() - 1);

				if (rand() & 1)
					cout << all_string_table[tid] << endl;
				else if (rand() & 1)
				{
					tid = tinsetrand(rd);
					cout << inset[tid] << endl;
				}
				else
				{
					uniform_int_distribution<int> tconsetrand(0, conset.size() - 1);
					tid = tconsetrand(rd);
					cout << conset[tid] << endl;
				}
			}
			else if (cmd == 2)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
				int tid = tidrand(rd);
				uniform_int_distribution<int> tinsetrand(0, inset.size() - 1);

				if (rand() & 1)
					cout << all_string_table[tid] << endl;
				else if (rand() & 1)
				{
					tid = tinsetrand(rd);
					cout << inset[tid] << endl;
				}
				else
				{
					uniform_int_distribution<int> tconsetrand(0, conset.size() - 1);
					tid = tconsetrand(rd);
					cout << conset[tid] << endl;
				}
			}
			else if (cmd == 3)
			{
				cout << cmd << endl;
				tot++;
			}
			else if (cmd == 4)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> con_rnd(1, tot ? tot : 1000);
				cout << con_rnd(rd) << endl;
			}
			else if (cmd == 5)
			{
				cout << cmd << " ";
				uniform_int_distribution<int> tidrand(0, all_string_table.size() - 1);
				int tid = tidrand(rd);
				uniform_int_distribution<int> con_rnd(1, tot ? tot : 1000);
				cout << all_string_table[tid] << " " << con_rnd(rd) << endl;
			}
		}
	}
}
