#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	int kase = 1;
	int n, b;
	char ans[1000];
	while (cin >> n >> b)
	{

		string res(itoa(n, ans, b));
		for_each(res.begin(), res.end(), [](char & a) {if (islower(a)) a = toupper(a); });
		cout <<"Case "<<kase++<<": " <<res << endl;
	}
}
