#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 50000;
const int chsize = 27;
int idx(char C)
{
    if (isupper(C))
    return C - 'A';
    else
    return chsize - 1;
}
int ch[maxn][chsize], fail[maxn], flg[maxn], vis[maxn];
int root, sz;
string virus[1001];
char str[2000000 + 100];
int newnode()
{
    memset(ch[sz], -1, sizeof(ch[sz]));
    flg[sz] = 0;
    return sz++;
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
        int & tmp = ch[now][idx(str[i])];
        if (tmp == -1) tmp = newnode();
        now = tmp;
    }
    flg[now] = id;
}
void build()
{
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < chsize; i++)
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
        int now = Q.front(); Q.pop();
        if (flg[fail[now]]) flg[now] = flg[fail[now]];
        for (int i = 0; i < chsize; i++)
        {
            if (ch[now][i] == -1)
            {
                ch[now][i] = ch[fail[now]][i];
            }
            else
            {
                fail[ch[now][i]] = ch[fail[now]][i];
                Q.push(ch[now][i]);
            }
        }
    }
}

map<int, int> query()
{
    int len = strlen(str);
    int now = root;
    map<int, int> ret;
    //memset(vis, 0, sizeof(vis));
    for (int i = 0; i < len; i++)
    {
        now = ch[now][idx(str[i])];
        int tmp = now;
        while(tmp != root)
        {
            if (flg[tmp]) ret[flg[tmp]] += 1;
            //vis[tmp] = 1;
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
        getchar();
        init();
        for (int i = 1; i <= n; i++)
        {
            gets(str);
            virus[i] = str;
            insert(i);
        }
        build();
        gets(str);
        map<int, int> ans = query();
        for (pair<int,int> p : ans)
        {
            printf("%s: %d\n", virus[p.first].c_str(), p.second);
        }
    }

}
