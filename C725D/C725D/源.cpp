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
struct TreeNode
{
	int val;
	TreeNode * left, *right;
	TreeNode() :val(-1), left(nullptr), right(nullptr){}
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
	void insert(int x)
	{
		if (x > val)
		{
			if (right != nullptr)
			{
				right->insert(x);
				return;
			}
			else
			{
				right = new TreeNode(x);
				return;
			}
		}
		if (x < val)
		{
			if (left != nullptr)
			{
				left->insert(x);
			}
			else
			{
				left = new TreeNode(x);
			}
			return;
		}
	}
	void pre(vector<int> & res)
	{
		res.push_back(val);
		if (left != nullptr)
		{
			left->pre(res);
		}
		if (right != nullptr)
		{
			right->pre(res);
		}
	}
	void in(vector<int> & res)
	{
		res.push_back(val);
		if (left != nullptr)
		{
			left->in(res);
		}
		if (right != nullptr)
		{
			right->in(res);
		}
	}

};
bool BuildCmp(string & s,vector<int> & orig_pre,vector<int> & orig_in)
{
	if (s.size() != orig_pre.size())
	{
		return false;
	}
	TreeNode * rt = new TreeNode( s[0] - '0');
	for (int i = 1; i < s.size(); i++)
	{
		rt->insert(s[i] - '0');
	}
	vector<int> cmp_pre, cmp_in;
	rt->pre(cmp_pre);
	rt->in(cmp_in);
	for (int i = 0; i < s.size(); i++)
	{
		if (orig_pre[i] != cmp_pre[i] || orig_in[i] != cmp_in[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int t;
	string orig;
	while (cin >> t && t)
	{
		cin >> orig;
		TreeNode * root = new TreeNode(orig[0] - '0');
		for (int i = 1; i < orig.size(); i++)
		{
			root->insert(orig[i] - '0');
		}
		vector<int> pree, inn;
		root->pre(pree);
		root->in(inn);
		while (t--)
		{
			cin >> orig;
			if (BuildCmp(orig, pree, inn))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}