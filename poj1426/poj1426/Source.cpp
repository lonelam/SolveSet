#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;

struct bnum
{
	static const int diginum = 100000;
	vector<int> v;
	bnum():v(1,1) {}
	int operator%(int rhs)
	{
		int carry = 0;
		for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++)
		{
			int s = carry * diginum + *i;
			carry = s % rhs;
		}
		return carry;
	}
	bnum extend0()
	{
		bnum ans(*this);
		int carry = 0;
		for (vector<int>::iterator i = ans.v.begin(); i != ans.v.end(); i++)
		{
			
			*i *= 10;
			*i += carry;
			carry = *i / diginum;
			if (*i >= diginum)
			{
				*i %= diginum;
			}
		}
		if (carry != 0)
		{
			ans.v.push_back(carry);
		}
		return ans;
	}
	bnum extend1()
	{
		bnum ans(*this);
		int carry = 1;
		for (vector<int>::iterator i = ans.v.begin(); i != ans.v.end(); i++)
		{

			*i *= 10;
			*i += carry;
			carry = *i / diginum;
			if (*i >= diginum)
			{
				*i %= diginum;
			}
		}
		if (carry != 0)
		{
			ans.v.push_back(carry);
		}
		return ans;
	}
	void show()
	{
		vector<int>::reverse_iterator i = v.rbegin();
		cout.width(0);
		cout << *i;
		i++;
		cout.fill('0');
		cout.width(5);
		for (; i != v.rend(); i++)
		{
			cout << *i;
		}
		cout << endl;
	}
};

int main1()
{
	int n;
	while (cin >> n && n)
	{
		int fac5 = 0, fac2 = 0;

		bnum ans;
		queue<bnum> q;
		q.push(ans);
		while (!q.empty())
		{
			bnum & cur = q.front();
			if (cur % n == 0)
			{
				ans = cur;
				break;
			}
			q.push(cur.extend0());
			q.push(cur.extend1());
			q.pop();
			
		}
		ans.show();

	}
	return 0;
}