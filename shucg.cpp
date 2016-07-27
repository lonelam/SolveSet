#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 40020;
bool used[maxn];
struct E
{
    int to,length;
};
vector<vector<E> > G(maxn);
const int inf = 0x3f3f3f3f;
void dfs(int cur,int target,int cur_len,int & min_len)
{
    if(cur == target)
    {
        min_len = min(min_len,cur_len);
        return;
    }
    for(E f : G[cur])
    {
        if(!used[f.to])
        {
            used[f.to] = true;
            dfs(f.to,target,cur_len + f.length, min_len);
            used[f.to] = false;
        }
    }
}
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n,m,from,to,length,ans;
            cin>>n>>m;
            for(int i=1;i<=n;i++)
            {
                G[i].clear();
            }
            memset(used,0,sizeof(used));
            for(int i=1;i<n;i++)
            {
                cin>>from>>to>>length;
                G[from].push_back({to,length});
                G[to].push_back({from,length});
            }
            for(int i=0;i<m;i++)
            {
                cin>>from>>to;
                ans = inf;
                used[from] = true;
                dfs(from,to,0,ans);
                used[from] = false;
                cout<<ans<<endl;
            }
        }
    }
}
