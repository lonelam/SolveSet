#include <bits/stdc++.h>
using namespace std;

int n, k;
int ci;
map<int, multiset<int>> cnt;
bool check()
{
    for (int i = 0; i < k; i++)
    {
        int need = n / k;
        if (i < n % k) need++;
       // cout << i <<" "<< need <<" "<< cnt.size() << endl;
        if (cnt[i].size() != need) return false;
        int p = 0;
        while(!cnt[i].empty())
        {
            if (*cnt[i].begin() > (p++) * k + i)
            {
                return false;
            }
            cnt[i].erase(cnt[i].begin());
        }
    }
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        cnt.clear();
        for (int i = 0; i < n;i++)
        {
            scanf("%d", &ci);
            cnt[(ci - 1) % k].insert(ci - 1);
          //  cout << (ci - 1) % k << endl;
        }

        if (check())
        {
            printf("Jerry\n");
        }
        else printf("Tom\n");
    }
}
