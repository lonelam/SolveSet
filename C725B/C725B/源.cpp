#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory>
#include<iterator>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode * left, *right;
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
	void query(int t)
	{
		if (t == val)
		{
			return;
		}
		if (t > val && right != nullptr)
		{
			printf("W");
			right->query(t);
			return;
		}
		if (left == nullptr)
		{
			return;
		}
		printf("E");
		left->query(t);
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
};

template<typename II>
TreeNode * buildTree(II pre_first, II pre_last)
{
	if (pre_first == pre_last)
	{
		return (nullptr);
	}
	TreeNode * root(new TreeNode(*pre_first));
	II i = next(pre_first);
		while (i!=pre_last && (*(i)) < (*pre_first))
		{
			i++;
		}
		if (i != pre_last)
		{
			size_t leftSize = *i - *pre_first - 1;
			root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1));
			root->right = buildTree(next(pre_first, leftSize + 1), pre_last);
			return root;
		}
		root->left = buildTree(next(pre_first), pre_last);
		return root;
}

int main()
{
	int n,k;
	int t;
	while (scanf("%d", &t) != EOF)
	{
		while (t--)
		{
			scanf("%d", &n);
			vector<int> preorder(n);
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &preorder[i]);
			}
			int q;
			TreeNode * rt = buildTree(preorder.begin(), preorder.end());
			scanf("%d", &q);
			while (q--)
			{
				scanf("%d", &k);
				rt->query(k);
				printf("\n");
			}
			delete rt;
			
		}
	}
}
