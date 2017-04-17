#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 10;
using namespace std;

int ch[maxn * 6][128], fail[maxn * 6], flag[maxn * 6];
bool vis[maxn * 6];
int root, sz;
char str[100100];
int newnode()
{
    memset(ch[sz], -1, sizeof(ch[sz]));
    flag[sz++] = 0;
    return sz - 1;
}
void init()
{
    sz = 0;
    root = newnode();
}

void insert(int id)
{
    int len = strlen(str);
    int now = root;
    for (int i = 0; i < len; i++)
    {
        int & tmp = ch[now][str[i]];
        if (tmp == -1) tmp = newnode();
        now = tmp;
    }
    flag[now] = id;
}

void build()
{
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < 128; i++)
    {
        int & tmp = ch[root][i];
        if (tmp == -1) tmp = root;
        else
        {
            fail[tmp] = root;
            Q.push(tmp);
        }
    }
    while(!Q.empty())
    {
        int now = Q.front();Q.pop();
        if (flag[fail[now]]) flag[now] = flag[fail[now]];
        for (int i = 0; i < 128; i++)
        {
            if (ch[now][i] == -1)
                ch[now][i] = ch[fail[now]][i];
            else
            {
                fail[ch[now][i]] = ch[fail[now]][i];
                Q.push(ch[now][i]);
            }
        }
    }
}

set<int> query()
{
    int len = strlen(str);
    int now = root;
    set<int> ret;
    memset(vis, 0,sizeof(vis));
    for (int i = 0; i < len; i++)
    {
        now = ch[now][str[i]];
        int tmp = now;
        while(tmp != root && !vis[tmp])
        {
            vis[tmp] = true;
            ret.insert (flag[tmp]);
            tmp = fail[tmp];
        }
    }
    return ret;
}
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        init();
        getchar();
        for (int i = 1; i <= n;i ++)
        {

            gets(str);
            //scanf("%s", str);
            insert(i);
        }
        build();
        int m;
        scanf("%d", &m);
        int cnt = 0;
        getchar();
        for (int i = 1; i <= m; i++)
        {

            gets(str);
            set<int> ans = query();
            ans.erase(0);
            if (!ans.empty())
            {
                printf("web %d:", i);
                for (int x : ans)
                {
                    printf(" %d", x);
                }
                cnt++;
                printf("\n");
            }

        }
        printf("total: %d\n", cnt);
    }
}
