#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
int main()
{
    set<int> a, b;
    int n;
    scanf("%d", &n);
    int cmd;
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            int x;
            scanf("%d", &x);
            Q.push(x);
            if (a.size() < b.size())
            {
                if(x < *b.begin())
                    a.insert(x);
                else
                {
                    a.insert(*b.begin());
                    b.erase(b.begin());
                    b.insert(x);
                }
            }
            else
            {
                if (b.empty() || x >= *a.rbegin())
                    b.insert(x);
                else
                {
                    b.insert(*a.rbegin());
                    a.erase(*a.rbegin());
                    a.insert(x);
                }
            }
        }
        else if (cmd == 2)
        {
            int p = Q.front();
            Q.pop();
            if (b.find(p) == b.end())
            {
                a.erase(p);
                if (a.size() + 1< b.size())
                {
                    a.insert(*b.begin());
                    b.erase(*b.begin());
                }
            }
            else if (b.find(p) != b.end())
            {
                b.erase(p);
                if (a.size() > b.size())
                {
                    b.insert(*a.rbegin());
                    a.erase(*a.rbegin());
                }
            }
        }
        else if (cmd == 3)
        {
            printf("%d\n", *b.begin());
        }
    }
}
