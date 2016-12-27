#include "seq.h"
#include<string>
#include <iostream>
#define unsorted
using namespace std;
const int maxn = 100000;
int init_arr[maxn];

int main()
{
	SqListClass<int> seq;
	int n;
	cout << "the initial n: ";
	cin >> n;
	cout << "enter n number: ";
	for (int i = 0; i < n; i++)
	{
		cin >> init_arr[i];
	}
	seq.CreateList(init_arr, n);
	cout << "Call DispList()....";
	seq.DispList();
	cout << "enter commands(unique):  ";
	string cmd;
	int val;
	while (cin >> cmd)
	{
		if (cmd == "unique")
		{
			cin >> val;
			seq.unique(val);
		}
		cout << "command executed. Calling DispLsit()...\n";
		seq.DispList();
		cout << "enter commands(unique):  ";
	}

}