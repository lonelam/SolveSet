#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int a[maxn];
vector<int> icnt[maxn];
multiset<int> seat;
int main()
{
    int T, n;
    while(scanf("%d", &T) !=EOF)
    {
        while(T--)
        {
            scanf("%d", &n);
            set<int> left;
            for (int i = 0; i < n; i++)
            {
                left.insert(i);
                scanf("%d", a + i);
                //nex[i] = (i + 1) % n;
            }
        //    memset(vis, 0, sizeof(vis));
            //int R = 0;

            int cnt = n;
            int id = 0;
            while(cnt)
            {
                id++;
                icnt[id].clear();
                seat.clear();
                int pre = 0;
                set<int> to_d;
                for (int i : left)
                {
                    //if (vis[i]) continue;
                    if (seat.empty())
                    {
                        //vis[i] = id;
                        to_d.insert(i);
                        seat.insert(a[i]);
                        seat.insert(a[i]);
                        --cnt;
                        icnt[id].push_back(i + 1);
                        continue;
                    }
                    multiset<int>::iterator ub = seat.upper_bound(a[i]);
                    if (ub != seat.begin())
                    {
                        to_d.insert(i);
                        --ub;
                        seat.erase(ub);
                        seat.insert(a[i]);
                        seat.insert(a[i]);
                        //vis[i] = id;
                        --cnt;
                        icnt[id].push_back(i + 1);
                    }
                }
                for (int i : to_d)
                {
                    left.erase(i);
                }
            }
            printf("%d\n", id);
            for (int i = 1; i <= id; i++)
            {
                printf("%d", icnt[i].size());
                for (int j : icnt[i])
                    printf(" %d", j);
                printf("\n");
            }

        }
    }
}
/*Sample Input

4
4
1 2 3 4
4
2 4 3 1
4
1 1 1 1
5
3 2 1 4 1
Sample Output

1
4 1 2 3 4
2
3 1 2 3
1 4
1
4 1 2 3 4
3
2 1 4
1 2
2 3 5
*/
