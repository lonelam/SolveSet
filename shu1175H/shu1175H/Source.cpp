#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>

using namespace std;

int main()
{
	int kase = 1;
	int n, b;
	char ans[1000];
	while (cin >> n >> b)
	{
		string res;
		while (n)
		{
			int car = n % b;
			if (car < 10)
			{
				res.push_back(car + '0');
			}
			else
			{
				res.push_back(car - 10 + 'A');
			}
			n /= b;
		}
		reverse(res.begin(), res.end());
		cout <<"Case "<<kase++<<": " <<res << endl;
	}
}