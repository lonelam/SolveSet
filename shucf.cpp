#include<iostream>
#include<vector>
#include<cstring>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 502;
bool G[maxn][maxn];
bool used[maxn];
int indegree[maxn];

int n;
int t;
void bfs(int rt,vector<vector<int>> & stairs)
{
    int lv = 1;
    vector<int> result;
    vector<int> cur,nex;
    cur.push_back(rt);
    stairs[0].push_back(rt);
    used[rt] = true;
    while(!cur.empty())
    {
        for(int x : cur)
        {
            for(int i=1;i<=n;i++)
            {
                if(!used[i]&&G[x][i])
                {
                    used[i] = true;
                    stairs[lv].push_back(i);
                    nex.push_back(i);
                }
            }
        }
        cur.clear();
        swap(cur,nex);
        lv++;
    }
}
int main()
{
    int m,from,to;
    while(cin>>n>>m)
    {
        vector<vector<int>> stairs(n);
        t = n-1;
        memset(indegree,0,sizeof(indegree));
        memset(G,0,sizeof(G));
        memset(used,0,sizeof(used));
        vector<int> result;
        while(m--)
        {
            cin>>from>>to;
            G[from][to] = true;
            indegree[to]++;
        }
        for(int i=n;i>0;i--)
        {
            if(indegree[i] == 0)
            {
                bfs(i,stairs);
            }
        }
        for(int i=0;stairs[i].size()!= 0;i++)
        {
            sort(stairs[i].begin(),stairs[i].end());
            for(int x: stairs[i])
            {
                result.push_back(x);
            }
        }
        cout<<result[0];
        for(int i=1;i<result.size();i++)
        {
            cout<<' '<<result[i];
        }
        cout<<endl;

    }
}
