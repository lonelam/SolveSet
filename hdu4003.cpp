#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct node
{
    int to;
    int val;
    int next;
} tree[maxn * 2];
int head[maxn];
int tot;
int dp[maxn][15];
void add(int a, int b, int val)
{
    tree[tot].to = b;
    tree[tot].val = val;
    tree[tot].next = head[a];
    head[a] = tol++;
}
int n, s, k;
void dfs(int root, int f)
{
    for(int i = head[root]; i != -1; i = tree[i].next)
    {
        int son = tree[i].to;
        if(son == f)
        {
            continue;
        }
        dfs(son, root);
        for(int j = k; j >= 0; j--)
        {


        }
    }
}

