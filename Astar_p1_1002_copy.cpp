#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

const int kMax = 100007;

int father[kMax];
std::set<int> S[kMax];
std::set<int> appear;
std::vector<int> V;

int Find(int x)
{
    if(father[x] == -1)
        return x;
    return father[x] = Find(father[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
        return;
    if(S[x].size() > S[y].size())
        std::swap(x, y);
    for(auto it = S[x].begin(); it != S[x].end(); ++it)
    {
        S[*it].erase(x);
        S[*it].insert(y);
        S[y].insert(*it);
    }
    father[x] = y;
}

int main()
{

  freopen("data.in", "r", stdin);
    int N, x, y, p;
    scanf("%d" ,&N);
    int ans = 0;
    memset(father, -1, sizeof(father));
    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d%d", &x, &y, &p);
        appear.insert(x);
        appear.insert(y);
        ++ans;
        int xrt = Find(x), yrt = Find(y);
        if(p)
        {
            if(xrt==yrt||S[xrt].count(yrt)==0)
            {
                Union(x,y);
            }
            else
            {
                V.push_back(ans);
                ans = 0;
                for(auto it = appear.begin(); it != appear.end(); ++it)
                {
                    S[*it].clear();
                    father[*it] = -1;
                }
                appear.clear();
            }
        }
        else
        {
            if(xrt!=yrt)
            {
                S[xrt].insert(yrt);
                S[yrt].insert(xrt);
            }
            else
            {
                V.push_back(ans);
                ans = 0;
                for(auto it = appear.begin(); it != appear.end(); ++it)
                {
                    S[*it].clear();
                    father[*it] = -1;
                }
                appear.clear();
            }
        }
    }
    printf("%d\n", V.size());
    for(const auto &r : V)
        printf("%d\n", r);
    return 0;
}
