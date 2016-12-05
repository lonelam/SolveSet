
int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> G[maxn], bcc[maxn];

stack<edge> s;
int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i = 0 ; i < G[u].size();i++)
    {
        int v= G[u][i];
        edge e = (edge) {u, v};
        if(!pre[v])
        {
            s.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if(lowv >= pre[u])
            {
                iscut[u] = true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)
                {
                    edge x = s.top(); s.pop();
                    if(bccno[x.u] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    }
                    if(bccno[x.v] != bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if(x.u == u && x.v == v)
                    {
                        break;
                    }
                }
            }
            else if(pre[v] < pre[u] && v != fa)
            {
                S.push(e);
                lowu = min(lowu, pre[v]);
            }
        }
        if(fa < 0 && child == 1)
        {
            iscut[u] = 0;
        }
    }
    return lowu;
}
void find_bcc(int u)
{
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(!pre[i]) dfs(i, -1);
    }
}
