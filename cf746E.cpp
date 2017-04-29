#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 100;

int a[maxn];
int b[maxn];
bool vis[maxn * 2];
bool cmp(int lhs, int rhs)
{
    return a[lhs] < a[rhs];
}
int n, m;
int oddhead, evenhead;
bool find_odd()
{
    while(vis[oddhead])
    {
        oddhead += 2;
    }
    if (oddhead > m) return false;
    return true;
}
bool find_even()
{
    while(vis[evenhead])
    {
    //    printf("%d\n", evenhead);
        evenhead += 2;
    }
    if (evenhead > m) return false;
    return true;
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        if (n & 1)
        {
            printf("-1\n");
            break;
        }
        set<int> odd, even;
        oddhead = 1;
        evenhead = 2;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            b[i] = i;
            if (a[i] <= m && a[i] <= 2 * n) vis[a[i]] = true;
            if (a[i] & 1)
            {
                odd.insert(a[i]);
            }
            else
            {
                even.insert(a[i]);
            }
        }
        sort(b, b + n, cmp);
        int cnt = 0;
        for (int i = 0; i + 1< n; i++)
        {
            if (a[b[i]] == a[b[i + 1]])
            {
                ++cnt;
                if (odd.size() > even.size())
                {
                    if (find_even())
                    {
                        a[b[i]] = evenhead;
                        vis[evenhead] = true;
                        even.insert(evenhead);
                    }
                    else
                    {
                        printf("-1\n");
                        return 0;
                    }
                }
                else
                {
                    if (find_odd())
                    {
                        a[b[i]] = oddhead;
                        vis[oddhead] = true;
                        odd.insert(oddhead);
                    }
                    else
                    {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }
        //cout <<"spilie" << endl;
        for (int i = 0; i < n; i++)
        {
            if (odd.size() > even.size())
            {
                if (a[i] & 1)
                {
                    ++cnt;
                    if (find_even())
                    {
                        vis[evenhead] = true;
                        even.insert(evenhead);
                        odd.erase(a[i]);
                        a[i] = evenhead;
                    }
                    else
                    {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
            else if (odd.size() < even.size())
            {
                if (!(a[i] & 1))
                {
                    ++cnt;
                    if (find_odd())
                    {
                        vis[oddhead] = true;
                        odd.insert(oddhead);
                        even.erase(a[i]);
                        a[i] = oddhead;
                    }
                    else
                    {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
            else
            {
                break;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < n;i ++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
/*

10 4
99 98 97 96 95 94 1 3 7 5

*/
