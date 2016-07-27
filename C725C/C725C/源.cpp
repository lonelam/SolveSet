#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<queue>
#include<string>
using namespace std;
const int inf = INT_MAX;
bool failed;
struct TreeNode
{
	int val;
	TreeNode * left, *right;
	TreeNode() :val(inf), left(nullptr), right(nullptr){}
	TreeNode(int n) :val(n), left(nullptr), right(nullptr) {}
	~TreeNode()
	{
		if (left != nullptr)
		{
			delete left;
		}
		if (right != nullptr)
		{
			delete right;
		}
	}
	void postorder()
	{
		if (left != nullptr)
		{
			left->postorder();
		}
		if (right != nullptr)
		{
			right->postorder();
		}
		printf("%d ", val);
	}
	void rtpostorder()
	{
		if (left != nullptr)
		{
			left->postorder();
		}
		if (right != nullptr)
		{
			right->postorder();
		}
		printf("%d\n", val);
	}
	void insert(string & s, int stp,int v)
	{
		if (s[stp] == ')')
		{
			if (val != inf)
			{
				failed = true;
			}
			val = v;
			return;
		}
		if (s[stp] == 'L')
		{
			if (left != nullptr)
			{
				left->insert(s, stp + 1, v);
			}
			else
			{
				left = new TreeNode();
				left->insert(s, stp + 1, v);
			}
		}
		if (s[stp] == 'R')
		{
			if (right != nullptr)
			{
				right->insert(s, stp + 1, v);
			}
			else
			{
				right = new TreeNode();
				right->insert(s, stp + 1, v);
			}
		}
	}

	bool isvalid()
	{
		if (val == inf)
		{
			return false;
		}
		bool ans = true;
		if (left != nullptr)
		{
			ans = ans&&left->isvalid();
		}
		if (right != nullptr)
		{
			ans = ans && right->isvalid();
		}
		return ans;
	}
	void leveltrv()
	{
		vector<int> result;
		queue<TreeNode *> q,nex;
		q.push(this);
		while (!q.empty())
		{
			while (!q.empty())
			{
				TreeNode * cur = q.front();
				q.pop();
				result.push_back(cur->val);
				if (cur->left != nullptr)
				{
					nex.push(cur->left);
				}
				if (cur->right != nullptr)
				{
					nex.push(cur->right);
				}
			}
			swap(q, nex);
		}
		bool start = false;
		
		for (int i = 0; i < result.size(); i++)
		{
			if (!start)
			{
				start = true;
				cout << result[i];
			}
			else
			{
				cout << ' ' << result[i];
			}
		}
		cout << endl;
	}
};

int main()
{
	char seq[200];
	int v, cnt;
	string s;
	failed = false;
	TreeNode * root = new TreeNode();
	while (cin>>s)
	{
		if (s == "()")
		{
			if (root->isvalid()&& !failed)
			{
				root->leveltrv();
			}
			else
			{
				cout << "not complete\n";
			}
			delete root;
			root = new TreeNode();
			failed = false;
		}
		else
		{
			v = 0;
			int i = 1;
			bool neg = false;
			if (s[i] == '-')
			{
				i++;
				neg = true;
			}
			while (isdigit(s[i]))
			{
			
				v *= 10;
				v += s[i] - '0';
				i++;
			}
			if (neg)
			{
				v = -v;
			}
			root->insert(s, i + 1, v);

		}
	}
}

