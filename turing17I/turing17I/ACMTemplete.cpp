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
string q1 = "Is this NEUQ£¿";
string a1 = "Yes, welcome to NEUQ.";
string q2 = "I have some question!";
string a2 = "What can I do for you ?";

int main()
{
	string input;
	cin >> input;
	if (input == "Is")
	{
		cout << a1;
	}
	else if (input == "I")
	{
		cout << a2;
	}
}