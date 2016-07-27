#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory>
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
TreeNode * buildTree(II pre_first, II pre_last, II in_first, II in_last)
{
	if (pre_first == pre_last)
	{
		return (nullptr);
	}
	if (in_first == in_last)
	{
		return (nullptr);
	}
	TreeNode * root(new TreeNode(*pre_first));
	II inRootPos = find(in_first, in_last, *pre_first);
	size_t leftSize = distance(in_first, inRootPos);
	root->left = buildTree(next(pre_first), next(pre_first, leftSize + 1), in_first, next(in_first, leftSize));
	root->right = buildTree(next(pre_first, leftSize + 1), pre_last, next(inRootPos), in_last);
	return root;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &preorder[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &inorder[i]);
		}
		TreeNode * rt = buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
		rt->rtpostorder();
		delete rt;
	}

}