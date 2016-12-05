
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
int n;
const int maxn = 45000;
double x[maxn], y[maxn], r[maxn];
bool inside(int i, int j)
{
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy <= r[j] * r[j];
}

void solve()
{
    vector<pair<double,int> > events;
    for (int i = 0; i < n; i++)
    {
        events.push_back({x[i] - r[i], i});
        events.push_back({x[i] + r[i], i + n});
    }
    sort(events.begin(), events.end());
    set<pair<double, int> > outers;
    vector<int> res;
    for (int i = 0; i < events.size(); i++)
    {
        int id = events[i].second % n;
        if (events[i].second < n)
        {
            set<pair<double,int> >::iterator it = outers.lower_bound({y[id], id});
            if (it != outers.end() && inside(id, it->second)) continue;
            if (it != outers.begin() && inside(id, (--it)->second)) continue;
            res.push_back(id);
            outers.insert({y[id], id});
        }
        else
        {
            outers.erase({y[id], id});
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
    {
        printf("%d%c", res[i] + 1, i + 1 == res.size() ? '\n' : ' ');
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf",r + i, x + i, y + i);
        }
        solve();
    }
}

