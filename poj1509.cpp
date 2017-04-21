#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 105000;
const int chsize = 26;
char s[maxn * 2];
struct SAM_Node
{
    SAM_Node * fa, *nex[chsize];
    int len;
    int id, pos;
    SAM_Node() {}
    SAM_Node(int _len)
    {
        fa = 0;
        len = _len;
        memset(nex, 0, sizeof(nex));
    }
};

SAM_Node SAM_node[maxn], *SAM_root, * SAM_last;

int SAM_size;
SAM_Node *newSAM_Node(int len)
{
    SAM_node[SAM_size] = SAM_Node(len);
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node * p)
{
    SAM_node[SAM_size] = *p;
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
void SAM_init()
{
    SAM_size = 0;
    SAM_root = SAM_last = newSAM_Node(0);
    SAM_node[0].pos = 0;
}

void SAM_add(int x, int len)
{
    SAM_Node *p = SAM_last, *np = newSAM_Node(p->len + 1);
    np->pos = len;
    SAM_last = np;
    for (; p && !p->nex[x]; p = p->fa)
    {
        p->nex[x] = np;
    }
    if (!p)
    {
        np->fa = SAM_root;
        return;
    }
    SAM_Node * q = p->nex[x];
    if (q->len == p->len + 1)
    {
        np->fa = q;
        return;
    }
    SAM_Node * nq = newSAM_Node(q);
    nq->len = p->len + 1;
    q->fa = nq;
    np-> fa = nq;
    for (; p && p -> nex[x] == q; p = p->fa)
    {
        p->nex[x] = nq;
    }
}
int len;
void SAM_build()
{
    SAM_init();

    strcpy(s + len, s);

    for (int i = 0; i < len * 2; i++)
    {
        SAM_add(s[i] - 'a', i + 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i= 0; i < n; i++)
    {
        scanf("%s", s);
        len = strlen(s);
        SAM_build();
        SAM_Node * p = SAM_root;
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < chsize; k++)
            {
                if (p->nex[k])
                {
                    p = p->nex[k];
                    //cout << (char)(k + 'a');
                    break;
                }
            }

        }
        cout << endl;
        printf("%d\n", p->pos - len + 1);
    }
}
