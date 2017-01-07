#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 1000;
int li[maxn], ri[maxn];
int id[maxn];
struct cmp
{
    bool operator()(int a, int b)
    {
        if (ri[a] != ri[b])
        {
            return ri[a] > ri[b];
        }
        return li[a] < li[b];
    }
};

bool acmp(int a, int b)
{
    if (li[a] != li[b])
    {
        return li[a] < li[b];
    }
    return ri[a] < ri[b];
}
int main()
{
    priority_queue<int, vector<int>, cmp> QQ;
    int n, k;
    scanf("%d%d", &n, &k);
    int L = -1e9;
    int R = 1e9;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", li + i, ri + i);
        id[i] = i;
    }
    sort(id, id + n, acmp);
    for (int i = 0; i < n; i++)
    {
        if (QQ.empty())
            QQ.push(id[i]);
        else
        {
            while(!QQ.empty() && ri[QQ.top()] < li[id[i]])
            {
                QQ.pop();
            }
            QQ.push(id[i]);
            while(QQ.size() > k)
            {
                QQ.pop();
            }
            if (QQ.size() == k && ans < ri[QQ.top()] - li[id[i]] + 1)
            {
                ans = ri[QQ.top()] - li[id[i]] + 1;
                L = li[id[i]];
                R = ri[QQ.top()];
            }
        }
    }

    if (ans == 0)
    {
        L= -1e9;
        R = 1e9;
    }
//    cout << L <<" "<< R << endl;
    printf("%d\n", ans);
    if (ans == 0)
    {
        for (int i = 1; i < k; i++)
        {
            printf("%d ", i);
        }
        printf("%d\n", k);
        return 0;
    }
    for (int i = 0; k > 0 && i < n; i++)
    {
        if (L >= li[i] && ri[i] >= R)
        {
            k--;
            if (k > 0)
            {printf("%d ", i + 1);}
            else if (k == 0)
            {
                printf("%d\n", i + 1);
            }
        }
    }

}
