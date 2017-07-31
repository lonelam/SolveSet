#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char preorder[maxn], inorder[maxn], postorder[maxn];
int p;
void dfs(int prebegin, int preend, int inbegin, int inend)
{
  if (prebegin >= preend)
  {
    return;
  }
  char cur = preorder[prebegin];
  int pos = find(inorder + inbegin , inorder + inend, cur) - inorder - inbegin;
  dfs(prebegin + 1, prebegin + pos + 1, inbegin, inbegin + pos);
  dfs(prebegin + pos + 1, preend, inbegin + pos + 1, inend);
  postorder[p++] = cur;
}
int main()
{
  while(cin >> preorder >> inorder)
  {
    p = 0;
    int n = strlen(preorder);
    dfs(0,n, 0, n);
    postorder[p++] = '\0';
    cout << postorder << endl;
  }
}
