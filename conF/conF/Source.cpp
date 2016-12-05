#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;

const int maxn = 100;


const ll moder = 1000000007;
int main()
{
	ll f0 = 7;
	ll f1 = 11;
	for (int i = 3; i < maxn; i++)
	{
		swap(f0, f1);
		cout << i << "   " << (f1 = ((f0 + f1) ^ (ll)(i & 1)))% moder << endl;
	}
	system("pause");
}